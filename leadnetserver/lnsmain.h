#ifndef __LNSMAIN_H__

#define __LNSMAIN_H__ 1

#define BUFFSIZE 1024
#define HOSTTEXTSIZE 256

void handle_sigchld(int sig);

int handlesession(int session);

int main (int argc, char *argv[]);


#endif
