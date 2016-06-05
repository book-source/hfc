#include<stdio.h>
#include<string.h>

void prt(int a)
{
  printf("hello\n");
  printf("%d\n", a);
}

int main()
{
  void (*p)(int);
  p = prt;
  p(3); 
  return 0;
}
