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



void handle_sigchld(int sig)
{
  while (waitpid( (pid_t)(-1), 0, WNOHANG) > 0) {}
}


int main (int argc, char *argv[])
{
  const char *hostname = 0;
  const char portname[] = "23";
}
