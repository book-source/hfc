#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{

  int times = 3;
  int i;
  for (i = 0; i < times; i++){
    pid_t pid = fork();
    if(pid == -1){
      fprintf(stderr,"can't fork process: %s\n", strerror(errno));
      return 1;
    }
    if(!pid) {
      if(execl("/bin/ls", "/bin/ls", "/data",  NULL) == -1){
     // while(1) {
     // }
      fprintf(stderr,"can't run cmd: %s\n", strerror(errno));
      return 1;
      }
    }
  return 0;
  }
}
