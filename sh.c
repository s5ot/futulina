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
  //pid_t pid;
  char *p;
  char *parg;
  char *commands[5];
  char **pos;
//  char *path;
  //int flg = 0;
  char *buf_pos;
  int i = 0;

  pos = commands;
  buf_pos = buf;

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
      commands[i] =  parg;

    i=0;
    while(commands[i] != NULL) {
    printf("%d:%s\n",i, commands[i]);
    i++;
    }
//  for(i = 0; i < 5; i++) {
//    printf("%s\n", commands[i]);
//  }
    //printf("%s\n", buf[p - buf_pos]);
    /*
    while((p = strchr(buf, SPACE)) != NULL) {
      strncpy(buf, path, bufpos - p);
      path[bufpos - p - 1] = '\0';
      commands[i] = path;
      i++;
      bufpos = p;
    }
    break;
    */

  }
  exit(EXIT_SUCCESS);
} 
/*
  
      } else { 
        if(commands == NULL)
          commands = malloc(sizeof(**char));
        if(realloc(commands, (sizeof(commands)+sizeof(char*))) != NULL) 
          strcpy(*commands, p);
      } 
    }
    if(realloc(commands, (sizeof(commands)+sizeof(char*))) != NULL)
      strcpy(*commands, "\0");
  

    commands = pos;
    pid = fork();

    if(pid < 0) {
      exit(1);
    } 

    if(pid == 0) {
      execv(path, commands);
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
  }

  exit(EXIT_SUCCESS);
}
*/
