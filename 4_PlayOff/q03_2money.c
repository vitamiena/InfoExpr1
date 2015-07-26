#include <stdio.h>
#include "recursive.h"

#define COINS 5

int main(int argc, char **argv)
{
  int coin[COINS] = {1, 5, 10, 50, -1};
  int money = atoi(argv[1]);
  int cnt = atoi(argv[2]);
  int len = COINS-1;

  printf("sum = %d\n", enum_money(coin, len, money, cnt));

  return 0;
}
