#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
int pipes[2];
char buf[256];

pipe(pipes);
write(pipes[1], "hoge\n", strlen("hoge\n"));
read(pipes[0], buf, sizeof(buf));

printf("buf=%s", buf);
exit(0);
}
