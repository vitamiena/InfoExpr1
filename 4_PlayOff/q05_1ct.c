#include <stdio.h>
#include <math.h>
#include "recursive.h"

int main(int argc, char **argv)
{
  int fc = (int)atoi(argv[1]);
  int fm = (int)atoi(argv[2]);
  int upp = (int)atoi(argv[3]);
  int len = (int)atoi(argv[4]);
  int s;

  s = ct_egypt(fc, fm, upp, 1, len);

  printf("%d\n", s);

  return 0;
}
