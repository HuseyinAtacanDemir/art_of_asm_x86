#include <stdio.h>

int cntBits(int input);

main() {
  int ex1 = 123;
  int ex2 = 24513;
  int ex3 = 13456;
  
  printf("Ex: %d, # bits: %d\n", ex1, cntBits(ex1));
  printf("Ex: %d, # bits: %d\n", ex2, cntBits(ex2));
  printf("Ex: %d, # bits: %d\n", ex3, cntBits(ex3));
  
}


int cntBits(int input) {
  int res = 0;
  int mask = 1;
  while (mask) {
    if(mask & input)
      res++;
   mask = mask << 1;
  }
  return res;
}
