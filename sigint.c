#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

void handler(int i) 
{
    printf("\nreceived sigint!!\n");
    exit(EXIT_SUCCESS);
}
int main()
{
  struct sigaction act, old;

  act.sa_handler = handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_RESTART;

  if(sigaction(SIGINT, &act, &old) < 0) {
   exit(EXIT_FAILURE);
  } 
  pause();

}

