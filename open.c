#include <stdio.h>

int main(int argc, char *argv[])
{
	int fd;
	fd = open(argv[1]);

	if((rename(argv[1], "hoge")==0)){;	
	printf("seiko\n");
	}else{
	printf("shippai\n");
	}
	
	close(fd);
}


