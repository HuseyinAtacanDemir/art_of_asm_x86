#include <stdio.h>

int toDate(int m, int d, int y);
int extractMonth(int date);
int extractDay(int date);
int extractYear(int date);

main() 
{
  printf("10/31/1998\n");
  int date1 = toDate(10, 31, 1998);
  printf("%d\n", extractMonth(date1));
  printf("%d\n", extractDay(date1));
  printf("%d\n", extractYear(date1));
  printf("%d\n", date1);  
  printf("1/1/2001\n");
  int date2 = toDate(1, 1, 2001);
  printf("%d\n", extractMonth(date2));
  printf("%d\n", extractDay(date2));
  printf("%d\n", extractYear(date2));
  printf("%d\n", date2);  
  
  printf("5/4/2024\n");
  int date3 = toDate(5, 4, 2024);
  printf("%d\n", extractMonth(date3));
  printf("%d\n", extractDay(date3));
  printf("%d\n", extractYear(date3));
  printf("%d\n", date3);  

}

int toDate(int m, int d, int y){
  if (m > 12 || m < 1) {
    printf("invalid Month\n");
    return 0;
  }
  if (d > 31 || d < 1) {
    printf("invalid Day\n");
    return 0;
  }
  if (y < 1) {
    printf("invalid Year\n");
    return 0;
  }
  int date = 0;
  date = date | ((m & 0xF) << 12);
  date = date | ((d & 0x1F) << 7);
  date = date | ((y % 100) & 0x7F);
  return date;
}

int extractMonth(int date) {
  int mask = 0xF;
  return ((date >> 12) & mask);
}

int extractDay(int date) {
  int mask = 0x1F;
  return ((date >> 7) & mask);
}

int extractYear(int date) {
  int mask = 0x7F;
  return (date & mask);
}
