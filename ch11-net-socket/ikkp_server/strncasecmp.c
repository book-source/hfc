#include <stdio.h>
#include <string.h>

int main(void)
{
  char *str1 = "STRING ONE";
  char *str2 = "string TWO";
  int result;

  result = strncasecmp(str1, str2, 6);

  if (result == 0)
    printf("Strings compared equal.\n");
  else if (result < 0)
    printf("\"%s\" is less than \"%s\".\n", str1, str2);
  else
    printf("\"%s\" is greater than \"%s\".\n", str1, str2);

  return 0;
}
