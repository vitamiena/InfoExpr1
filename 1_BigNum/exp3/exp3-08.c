#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BigNumLib.h"

int brand(void) {
  return (int)rand() % 10000;
}

int main(void) {
  BigNum n1, n2, n3, n4;
  int k;
  clock_t t1, t2;
  int REP = 1000;

  srand((unsigned)time(NULL));

  bignum_init(&n1, 1);
  bignum_shift(&n1, 50);
  bignum_init(&n2,0);

  while ( n2.uni != 100 ) {
    bignum_shift(&n2, 1);
    bignum_inc(&n2, brand());
    t1 = clock();
    for ( k = 0; k < REP; k++ ) {
      bignum_div3(n1, n2, &n3, &n4);
    }
    t2 = clock();
    printf("[%d]:%.10f\n",n2.uni, (t2-t1+0.0)/CLOCKS_PER_SEC);
    bignum_output(n3);
    bignum_output(n4);
    fprintf(stderr, "%.10f\n",(t2-t1+0.0)/CLOCKS_PER_SEC);
  }

  return 0;
}
