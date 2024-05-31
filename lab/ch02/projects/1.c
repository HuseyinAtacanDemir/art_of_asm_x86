#include <stdio.h>

main()
{
  char vars[2][2] = {{'i','j'},{'k','l'}};
  char in[2][2];
  char test[3];
  char c;
  int i,j;
  for(i = 0; i < 2; i++){
    for(j = 0; j < 2; j++){
      printf("Enter %c: ", vars[i][j]);
      char c1;
      while((c=getchar()) != '\n'){
        c1 = c;
      }
      printf("\n");
      in[i][j] = c1;
    }
  }
  for(i = 0; (c=getchar()) != EOF; i++){
    if (i==2){
      i=-1;
      test[2] = '\0';
      printf("Input: %s Output: %c\n", test, in[test[1]-'0'][test[0]-'0']);
    }
    test[i] = c;
  }
}
