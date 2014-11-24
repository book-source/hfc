#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int
main()
{
  if(execl("/sbins/ifconfig", "/sbin/ifconfig", NULL) == -1){
    if(execlp("ipconfig", "ipconfig", NULL) == -1){
      fprintf(stderr, "Cannot run ipconfig: %s\n", strerror(errno));
      fprintf(stderr, "Cannot run ipconfig: %d\n", errno);
      return 1;
    }
  }
  return 0;
}
