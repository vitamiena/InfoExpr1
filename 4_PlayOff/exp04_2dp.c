#include <stdio.h>
#include <math.h>
#include <time.h>
#include "recursive.h"

int main(int argc, char **argv)
{
  int num;
  int upp;
  int len;
  int val_num;
  int val_upp;
  int val_len;
  int n = 1000;
  clock_t start, end;

  if ( argc < 6 ) {
    puts("num upp len val_num val_upp val_len");
    return 0;
  }

  num = atoi(argv[1]);
  upp = atoi(argv[2]);
  len = atoi(argv[3]);
  val_num = atoi(argv[4]);
  val_upp = atoi(argv[5]);
  val_len = atoi(argv[6]);

  start = clock();
  while ( n-- ) {
    if ( make_val(val_num, val_upp, val_len) == -1 ) {
      puts("Error");
      return 0;
    }

    sq_parti2(num, upp, len);
  }
  end = clock();

  printf("%lf s\n", (end-start+0.0)/CLOCKS_PER_SEC);

  return 0;
}
