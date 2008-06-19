#include <stdio.h>

int main(int argc, char *argv[])
{
	int fd;
	fd = open(argv[1]);

	if((unlink(argv[1])==0)){;	
	printf("seiko\n");
	}else{
	printf("shippai\n");
	}
	
	close(fd);
}


