#include <stdio.h>
int main()
{
  FILE *f1 = fopen("test1.txt", "r");
  FILE *f2 = fopen("test2.txt", "r");
  int des1 = fileno(f1);
  int des2 = fileno(f2);
  printf("%d,%d\n", des1, des2);
  //dup2(des2, des1);
  dup2(3, 4);
  printf("%d,%d\n", fileno(f1), fileno(f2));
  return 0;
}
