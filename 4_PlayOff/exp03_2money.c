#include <stdio.h>
#include "recursive.h"

#define COINS 6
#define MONEY 6

int main(void)
{
  int coin[COINS] = {1, 5, 10, 25, 50, -1};
  int mnys[MONEY] = {100,150,200,250,300,500};
  int i, j;
  int upp;

  printf("   ,");
  for ( j = 10; j <=100; j+=10 ) {
    printf("%5d, ", j);
  }
  puts("");

  for ( i = 0; i < MONEY; i++ ) {
    printf("%3d,", mnys[i]);
    for ( j = 10; j <= 100; j+=10 ) {
      printf("%5d, ", enum_money(coin, COINS-1, mnys[i], j));
    }
    puts("");
  }

  return 0;
}
