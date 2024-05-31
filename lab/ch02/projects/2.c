#include <stdio.h>

main()
{
  char fnNumber[3];
  int i,j;
  char c;
  for(i = 0; (c=getchar()) != EOF && c!='\n' && i < 2; i++){
    if(c<'0' || c>'9')
      i--;
    else {
      fnNumber[i] = c;
    }
  }
  fnNumber[2] = '\0';

  int num = 0;
  for(i = 0; i < 2; i++) {
    num *= 10;
    num += fnNumber[i] - '0';
  }
  
  char table[5][3];

  for(i = 0; i < 5; i++){
    for(j = 0; j < 3; j++){
      if(i == 0){
        table[i][0] = 'A';
        table[i][1] = 'B';
        table[i][2] = 'F';
      }else{
        table[i][2] = ((num >> (i-1)) & 1) + '0';
        table[i][0] = (((i-1) >> 1) & 1) + '0';
        table[i][1] = (((i-1)) & 1) + '0';
      }
    
      printf("| %c |", table[i][j]);
    }
      printf("\n");
  }
}
