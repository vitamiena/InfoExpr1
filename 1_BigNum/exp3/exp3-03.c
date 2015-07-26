#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BigNumLib.h"

int main(void) {
  BigNum n1, n2;
  int a;
  BigNum n4;
  int k;
  clock_t t1, t2;
  int REP = 100;

  bignum_init(&n1, 1000);
  bignum_shift(&n1, 1);
  bignum_init(&n2,1);

  while( n2.uni - n1.uni <= 1 && n2.uni-n1.uni >= -1 ) {
    t1 = clock();
    for ( k = 0; k < REP; k++ ) {
      bignum_div1(n1, n2, &a, &n4);
    }
    t2 = clock();
    printf("%.10f\n", (t2-t1+0.0)/CLOCKS_PER_SEC);
    bignum_scl(&n2, 10);
  }

  return 0;
}
