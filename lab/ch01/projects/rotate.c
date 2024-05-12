#include <stdio.h>

int ROL(int in);
int ROR(int in);

main(){
  int ex1 = 12345;
  printf("%d %d\n", ex1, ROL(ex1));
  printf("%d %d\n", ex1, ROR(ex1));
  
  int ex2 = 32111;
  printf("%d %d\n", ex2, ROL(ex2));
  printf("%d %d\n", ex2, ROR(ex2));
  
  int ex3 = 19563;
  printf("%d %d\n", ex3, ROL(ex3));
  printf("%d %d\n", ex3, ROR(ex3));

  int ex4 = 4233;
  printf("%d %d\n", ex4, ROL(ex4));
  printf("%d %d\n", ex4, ROR(ex4));

  int ex5 = 8933;
  printf("%d %d\n", ex5, ROL(ex5));
  printf("%d %d\n", ex5, ROR(ex5));  
}

int ROL(int in) {
  int mask = 1 << 15;
  int hoBit = in & mask;
  if (hoBit) {
    in = in << 1;
    in = in + 1;
    return in;
  }
  return (in << 1);
}

int ROR(int in) {
  int mask = 1;
  int loBit = in & mask;
  if (loBit) {
    in = in >> 1;
    in = in | (1 << 15);
    return in;
  }
  return (in >> 1);
}
