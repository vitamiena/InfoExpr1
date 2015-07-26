#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BigNumLib.h"

int brand(void) {
  return (int)rand() % 10000;
}

int main(void) {
  BigNum n1, n3;
  int a2, a4;
  BigNum n4;
  int k;
  clock_t t1, t2;
  int REP = 1000000;

  srand((unsigned)time(NULL));

  bignum_init(&n1, 0);
  a2 = 1000;

  while ( n1.uni != 100 ) {
    bignum_shift(&n1, 1);
    bignum_inc(&n1, brand());
    t1 = clock();
    for ( k = 0; k < REP; k++ ) {
      bignum_div2(n1, a2, &n3, &a4);
    }
    t2 = clock();
    printf("%.10f\n", (t2-t1+0.0)/CLOCKS_PER_SEC);
  }

  return 0;
}
