#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int pipes[2];
  printf("%d\n", pipes[0]);
  printf("%d\n", pipes[1]);
  exit(0);
}
