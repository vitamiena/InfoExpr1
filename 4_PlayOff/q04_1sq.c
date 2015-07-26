#include <stdio.h>
#include <math.h>
#include "recursive.h"

int main(int argc, char **argv)
{
  int num = atoi(argv[1]);
  int upp = atoi(argv[2]);
  int len = atoi(argv[3]);
  int s;

  s = sq_parti(num, upp, len);

  printf("%d\n", s);

  return 0;
}
