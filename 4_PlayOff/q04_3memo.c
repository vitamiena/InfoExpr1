#include <stdio.h>
#include <math.h>
#include "recursive.h"

int main(int argc, char **argv)
{
  int num = atoi(argv[1]);
  int upp = atoi(argv[2]);
  int len = atoi(argv[3]);

  printf("f(%d,%d,%d) = %d\n", num, upp, len, sq_parti3(num, upp, len));
  printf("cell = %d\n", count_cell());

  return 0;
}
