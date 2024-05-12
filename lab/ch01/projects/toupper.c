#include <stdio.h>

char toUpper(char c);

main() {
  char c;
  while((c=getchar()) != EOF)
    if (c != '\n')
      printf("\nIn: %c, Out: %c\n", c, toUpper(c));
}

char toUpper(char c) {
  char mask = ~(1 << 5); 
  if (c > 0x60 && c < 0x7B)
    return c & mask;
  return c;
}
