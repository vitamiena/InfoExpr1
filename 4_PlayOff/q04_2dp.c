#include <stdio.h>
#include <math.h>
#include "recursive.h"

int main(int argc, char **argv)
{
  int num = atoi(argv[1]);
  int upp = atoi(argv[2]);
  int len = atoi(argv[3]);

  if ( make_val(NUM-1, UPP-1, LENGTH-1) == -1 ) {
    puts("Error");
  }

  printf("%d\n", sq_parti2(num, upp, len));

  return 0;
}
