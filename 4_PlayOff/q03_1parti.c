#include <stdio.h>
#include "recursive.h"

int main(int argc, char **argv)
{
  int num = atoi(argv[1]);
  int upp = atoi(argv[2]);
  int len = atoi(argv[3]);

  enum_parti1(num, upp, len);

  return 0;
}
