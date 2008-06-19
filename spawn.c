#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;

	if(argc != 3) {
		exit(EXIT_FAILURE);
	}

	pid = fork();

	if(pid<0) {
		exit(1);
	} 

	if(pid == 0) {
		execl(argv[1], argv[1], argv[2], NULL);
		exit(EXIT_FAILURE);
	} else {
		int status;
		
		//waitpid(pid, &status, 0);

		printf("child (PID=%d finished; ",pid);

		if(WIFEXITED(status))
			printf("exit, status=%d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("exit, status=%d\n", WTERMSIG(status));
		else 
			printf("abnormal exit\n");
		exit(EXIT_SUCCESS);
}
}
