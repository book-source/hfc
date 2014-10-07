#include <stdio.h>
#include <stdlib.h>

int main()
{
	char card_name[3];
	do {
        	puts("input card name:");\
        	scanf("%2s", card_name);
        	int val = 0;
        	switch (card_name[0])
        	{
        		case 'K':
        		case 'Q':
        		case 'J':
        			val = 10;
        			break;
        		case 'A':
        			val = 11;
        			break;
			case 'X':
				continue;
        		default:
        			val = atoi(card_name);	
				if((val < 1) || (val > 10))
				{
					puts("I can't understand this value!");
					continue;
				}
        	}
        	
        	if (val > 2 && val < 7)
        	{
        		printf("count plus\n");
        	}
        	if (val == 10)
        	{
        		printf("count minus\n");
        	}
	} while(card_name[0] != 'X');
	return 0;
}
