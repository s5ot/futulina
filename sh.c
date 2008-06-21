#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define SPACE 32

int main(int argc, char *argv[])
{
  char buf[1024];
  char buf2[1024];
  //char buf3[1024];
  pid_t pid;
  char *p;
  char *parg;
  char *commands[5] = {NULL,NULL,NULL,NULL,NULL};
  char **commands_ptr;
  char **pos;
//  char *path;
  //int flg = 0;
  char *buf_pos;
  int i = 0;

  pos = commands;
  buf_pos = buf;

  fprintf(stdout, "$");
  while((fgets(buf_pos, sizeof buf, stdin) != NULL)) {
    i = 0;
    while((p = strchr(buf_pos, SPACE)) != NULL) {
      strncpy(buf2, buf_pos, (p-buf_pos));
      buf2[p-buf_pos] = '\0';
      parg = malloc(sizeof buf2);
      strcpy(parg, buf2);
      commands[i] =  parg;
      buf_pos = ++p;
      i++;
      //break;
    }

    parg = malloc(sizeof buf2);
    strcpy(parg, buf_pos);
    parg[strlen(parg) -1] = '\0';
    commands[i] =  parg;

    /*
    for(i=0;i<5;i++) {
      printf("%d:%s\n", i,commands[i]);
    }
*/
    pid = fork();

    if(pid < 0) {
      exit(EXIT_FAILURE);
    } 

    if(pid == 0) {
      execvp(commands[0], commands);
      exit(EXIT_FAILURE);
    } else {
      int status;

      waitpid(pid, &status, 0);

      printf("child (PID=%d finished; ",pid);

      if(WIFEXITED(status))
        printf("exit, status=%d\n", WEXITSTATUS(status));
      else if (WIFSIGNALED(status))
        printf("exit, status=%d\n", WTERMSIG(status));
      else 
        printf("abnormal exit\n");

     // exit(EXIT_SUCCESS);
    }
    for(i=0;i<5;i++) {
      commands[i] = NULL;
    }
    fprintf(stdout, "$");
  }

  exit(EXIT_SUCCESS);
}
