#include <stdio.h>
#include "recursive.h"

int main(void)
{
  int num = 50;
  int i, j;
  int upp;

  printf("  ,");
  for ( j = 0; j < num; j++ ) {
    printf("%2d, ", j+1);
  }
  puts("");

  for ( i = 10; i <= num; i+=10 ) {
    printf("%2d,", i);
    upp = i%2==0 ? i-1 : i;
    for ( j = 1; j <= i; j++ ) {
      printf("%2d,", enum_parti1(i, upp, j));
    }
    puts("");
  }
  puts("");

  for ( i = 0; i <= num; i++ ) {
    printf("%2d,", i);
    upp = i%2==0 ? i-1 : i;
    printf("%2d, ", enum_parti1(i, upp, i));
    puts("");
  }

  return 0;
}
