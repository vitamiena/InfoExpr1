#include <stdio.h>
#include <math.h>
#include "recursive.h"

int main(int argc, char **argv)
{
  int num = atoi(argv[1]);
  int upp = atoi(argv[2]);
  int len = atoi(argv[3]);

  printf("%d\n", sq_parti3(num, upp, len));
  printf("%d\n", count_cell());

  return 0;
}
