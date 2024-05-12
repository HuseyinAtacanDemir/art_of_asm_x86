#include <stdio.h>

#define MAXINPUT 100

int parseInt(char *str);

main()
{
  char str[MAXINPUT];
  char c;
  int i = 0;

  while ((c=getchar()) != EOF && i < MAXINPUT - 1) {
    str[i++] = c;
  }
  str[i] = '\0';
  printf("\nIn %s, Out %d\n", str, parseInt(str));
}

int parseInt(char *str)
{
  int i = 0;
  char c;
  int res = 0;
  while ((c = str[i++]) != '\0'){
    if (!(c >= 0x30 && c <= 0x39))
      break;
    res = res * 10;
    res = res + (int)(c & 0x0F);
  }

  return res;
}
