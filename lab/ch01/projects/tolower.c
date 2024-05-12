#include <stdio.h>

char toLower(char c);

main() 
{
  char c;
  while((c=getchar())!=EOF)
    printf("\nIn: %c, Out: %c\n", c, toLower(c));
}

char toLower(char c)
{
  char mask = (1 << 5);
  if (c > 0x40 && c < 0x5B)
    return c | mask;
  return c;
}
