#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "funcs.h"

#include "lnsmain.h"


int endprog = 0; /* Close the server when this goes to 1 */


void handle_sigchld(int sig)
{
  while (waitpid( (pid_t)(-1), 0, WNOHANG) > 0) {} /* Clean up forks */
}

int handlesession(int session)
{
  /* Session handler.  When we reach this, we're a child. */
  
}

int main (int argc, char *argv[])
{
  const char *hostname = 0; /* Use any */
  const char portname[] = "23"; /* Use telnet */
  struct addrinfo hints;
  struct addrinfo *res = NULL;
  char hname[HOSTTEXTSIZE] = "";
  char ipaddr[HOSTTEXTSIZE] = "";
  char rip[HOSTTEXTSIZE] = "";
  long rport = -1;
  char ts[BUFFSIZE] = "";
  char *homevar;
  long err;
  
  endprog = 0;
  
  err = (long) gethostname(hname, HOSTTEXTSIZE);
  if (err != 0) fprintf(stderr, "Error getting hostname %l\n",err);
  
  memset(&hints,0,sizeof(hints));
  hints.ai_family = AF_UNSPEC;  /* Accept both IPv4 and IPv6 */
  hints.ai_socktype = SOCKSTREAM; /* Telnet uses TCP not UDP */
  hints.ai_protocol = 0;  /* Unneeded */
  hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG; 
  err = (long) getaddrinfo(hostname, portname, &hints, &res);
  if (err != 0)
  {
    fprintf(stderr, "Error %l resolving local socket address.\n",err);
    exit(1);
  }
  
  /* Creating the Socket */
  int server_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (server_fd == -1)
  {
    fprintf(stderr, "Error creating server socket: %s.\n",strerror(errno));
    freeaddrinfo(res);
    exit(1);
  }
  int reuseaddr = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) == -1)
  {
    fprintf(stderr, "%s.\n", strerror(errno));
    freeaddrinfo(res);
    exit(1);
  }
  
  /* Bind the server socket to the address/port number */
  if (bind(server_fd, res->ai_addr, res->ai_addrlen) == -1)
  {
    fprintf(stderr, "%s\n",strerror(errno));
    freeaddrinfo(res);
    exit(1);
  }
  freeaddrinfo(res);
  
  /*Listen for connections*/
  if (listen(server_fd,SOMAXCONN))
  {
    fprintf(stderr, "Error %d listening for connections.\n",errno);
    exit(1);
  }
  
  /* Can't remember what this is for, but I needed it on my last such project */
  int session_fd = -1;
  struct sockaddr_storage anaddr;
  struct sockaddr_in *ipv4addr;
  socklen_t anaddr_size;
  struct sockaddr_in laddr;
  socklen_t laddr_size;
  
  /* Register handler to clean up forks */
  struct sigaction sa;
  sa.sa_handler = &handle_sigchld;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART | SA_NOCHLDSTOP;
  if (sigaction(SIGCHLD, &sa, 0) == -1)
  {
    fprintf(stderr, "Error registering SIGCHLD handler.\n");
    close(server_fd);
    exit(1);
  }
  
  /* Register other handlers here... */
  
  while (endprog == 0)
  {
    anaddr_size = sizeof(anaddr);
    laddrsize = sizeof(laddr);
    session_fd = accept(server_fd, (struct sockaddr *)&anaddr, &anaddr_size);
    ipv4addr = (struct sockaddr_in *)&anaddr;
    if (session_fd == -1)
    {
      if ((errno==EINTR) || (errno == EWOULDBLOCK)) continue;
      fprintf(stderr, "Error %d accepting incoming connection\n",errno);
      close(server_fd);
      exit(1);
    }
    getsockname(session_fd, (struct sockaddr *)&laddr,&laddr_size);
    /* Connected at this point! */
    strcpy(rip, (char *) inet_ntoa(ipv4addr->sin_addr));
    rport = (long) ntohs(ipv4addr->sin_port);
    /* rip is the remote IP address, rport is the remote port */
    strcpy(ipaddr, (char *)inet_ntoa(laddr.sin_addr));
    /* ipaddr is the connected local IP address */
    
    /* Fork now to handle connection */
    pid_t pid = fork();
    if (pid == -1)
    {
      fprintf(stderr, "Error %d creating child process.\n",errno);
      close(server_fd);
      exit(1);
    }
    else if (pid == 0)
    {
      /* This is the Child */
      
      /* Save ipaddr here - we're likely to need it later */
      
      /* Return any signal handlers to their defaults here */
      
      /* We can't use the server_fd in the child, so get rid of it! */
      close(server_fd);
      
      /* Call the session handler */
      handlesession(session_fd);
      /* Close the session and exit */
      close(session_fd);
      wait(0);
      exit(0);
    }
    else
    {
      /* This is the Parent */
      /* Don't need the session descriptor anymore */
      close(session_fd);
    }
  }
  
  /* Close Server FD */
  close(server_fd);
  /* Wait for forks */
  waitpid(-1,0,0);
  /* And end */
  exit(0);
}
