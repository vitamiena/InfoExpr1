#include <stdio.h>
#include <math.h>
#include <time.h>
#include "recursive.h"

int main(int argc, char **argv)
{
  int num;
  int upp;
  int len;
  int n = 10000;
  clock_t start, end;

  if ( argc < 4 ) {
    puts("num upp len");
    return 0;
  }

  num = atoi(argv[1]); upp = atoi(argv[2]); len = atoi(argv[3]);

  printf("%d %d %d\n", num, upp, len);

  start = clock();
  while ( n-- ) {
    sq_parti(400, 20, 15);
  }
  end = clock();
  printf("%lf s\n", (end-start+0.0)/CLOCKS_PER_SEC);

  n = 10000;
  start = clock();
  while ( n-- ) {
    sq_parti(400, 15, 20);
  }
  end = clock();
  printf("%lf s\n", (end-start+0.0)/CLOCKS_PER_SEC);

  return 0;
}
