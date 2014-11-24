#include <stdio.h>
#include <unistd.h>

int main()
{
  execl("/bin/ls", "/bin/ls",  NULL);
  printf("------------------------\n");
  execl("/bin/ls", "/bin/ls", "/data", NULL);
  return 0;

}
