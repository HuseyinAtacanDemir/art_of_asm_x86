#include <stdio.h>

main()
{
  char fnNumber[6];
  int i,j;
  char c;
  for(i = 0; (c=getchar()) != EOF && c!='\n' && i < 5; i++){
    if(c<'0' || c>'9')
      i--;
    else {
      fnNumber[i] = c;
    }
  }
  fnNumber[5] = '\0';

  int num = 0;
  for(i = 0; i < 5; i++) {
    num *= 10;
    num += fnNumber[i] - '0';
  }
  
  char table[17][5];

  for(i = 0; i < 17; i++){
    for(j = 0; j < 5; j++){
      if(i == 0){
        table[i][0] = 'A';
        table[i][1] = 'B';
        table[i][2] = 'C';
        table[i][3] = 'D';
        table[i][4] = 'F';
      }else{
        table[i][4] = ((num >> (i-1)) & 1) + '0';
        table[i][0] = (((i-1) >> 3) & 1) + '0';
        table[i][1] = (((i-1) >> 2) & 1) + '0';
        table[i][2] = (((i-1) >> 1) & 1) + '0';
        table[i][3] = ((i-1) & 1) + '0';
      }
    
      printf("| %c |", table[i][j]);
    }
      printf("\n");
  }
  int count = 0;
  for(i = 1; i < 17; i++)
    if(table[i][4] == '1')
        count++;
  for(i = 1; i < 17; i++){
    char minterm[9];
    if(table[i][4] == '1'){
      count--;
      int k = 0;
      for(j = 0; j < 4; j++){
        minterm[k++] = 'A' + j;
        if(table[i][j] == '0') 
          minterm[k++] = '\'';
      }
      minterm[k] = '\0';
      printf("%s ", minterm);  
      if(count > 0){
       printf("+ ");
      }
    }
  }
  printf("\n");
}
