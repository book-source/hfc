#include<stdio.h>

char *sports[] = {
  "football",
  "basketball",
  "pingpang",
  "tenis"
};


int
main ()
{
/*	char *p = sports;
	while(p){
		printf("%s\n", sports);
		p++;
	}
*/
  puts(sports[1]);
  int i;
  for(i = 0; i < 6; i++)
    puts(sports[i]);
  return 0;
}
