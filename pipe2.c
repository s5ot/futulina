#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int pipes[2];
  char buf[256];

  pipe(pipes);  //in,outのファイルディスクリプタをもらう

  if(fork() == 0) {
    dup2(pipes[0], 0); //inのディスクリプタを標準入力に複製する
    close(pipes[1]);  //outのディスクリプタを閉じる
    execl("/bin/cat", "cat", "-n", NULL);
    exit(0);
  } else {
    FILE *fin, *fout;
    char buf[256];
    int status;

    close(pipes[0]);  //inのディスクリプタを閉じる
    fout = fdopen(pipes[1], "w"); //outのディスクリプタをオープン
    fin = fopen("sample.dat", "r");

    while(1) {
      if(fgets(buf, sizeof buf, fin) == 0) {
        break;
      }
      fprintf(fout,"%s",buf);
    }
    fclose(fin);
    fclose(fout);

    wait(&status);
    exit(0);
  }
}
