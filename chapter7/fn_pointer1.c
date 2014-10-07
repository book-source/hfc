#include<stdio.h>
#include<string.h>

void prt()
{
  printf("hello\n");
}

int main()
{
  void (*p)();
  p = prt;
  p(); 
  return 0;
}
