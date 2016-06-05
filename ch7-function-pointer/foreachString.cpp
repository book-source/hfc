/*
	FileName: foreachString.cpp
	Author: ACb0y
	Create Time: 2011年3月20日22:20:33
	Last Modify Time: 2011年3月20日22:46:43
 */
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
void foreachStringOne(char * str)
{
	int len = strlen(str);
	for (int i = 0; i < len; ++i) 
	{
		printf("%c", str[i]);
	}
	printf("/n");
}
void foreachStringTwo(char * str) 
{
	while (*str) 
	{
		printf("%c", *str);
		++str;
	}
	printf("/n");
}
void print(char c)
{
	printf("%c", c);
}
void foreachStringThree(char * str) 
{
	for_each(str, str + strlen(str), print);
	printf("/n");
}
int main()
{
	char str[] = "hello word!";
	foreachStringOne(str);
	foreachStringTwo(str);
	foreachStringThree(str);
	return 0;
}

