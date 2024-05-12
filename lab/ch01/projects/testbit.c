#include <stdio.h>

int testBit(int in, int b);

main(){
  int ex1 = 12345;
  int b1 = 1;
  printf("%d %d %d\n", ex1, b1, testBit(ex1, b1));
  int ex2 = 12345;
  int b2 = 2;
  printf("%d %d %d\n", ex2, b2, testBit(ex2, b2));
  int ex3 = 12345;
  int b3 = 13;
  printf("%d %d %d\n", ex3, b3, testBit(ex3, b3));

}

int testBit(int in, int b) {
  if(b > 15 || b < 0) return 0;
  int mask = 1 << b;
  if (in & mask)
    return 1;
  return 0;
}

