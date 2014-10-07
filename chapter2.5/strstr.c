#include<stdio.h>
#include<string.h>

int main()
{
	char *a = "hello world";
	char *b = "world";
	printf("%p\n", a);
	printf("%p\n", b);
	printf("%p\n", strstr(a, b));
	
	printf("%s\n", strstr(a, b));
	return 0;
}
