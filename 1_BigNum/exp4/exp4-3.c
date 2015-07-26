#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BigNumLib.h"

int brand(void) {
  return (int)rand() % 10000;
}

int main(void) {
  BigNum n1, n2;
  BigNum n3, n4;
  clock_t t1, t2;
  double  total1, total2 ;
  int REP = 1000;
  int k1, k2;
  bignum_init(&n1, 1);
  bignum_shift(&n1, 49);
  bignum_inc(&n1, 1);
  bignum_init(&n2, brand());
  srand((unsigned)time(NULL));

  for ( k1 = 0; k1 < UNI; k1++ ) {
    bignum_shift(&n2, 1);
    bignum_inc(&n2, brand());
    t1 = clock();
    for ( k2 = 0; k2 < REP; k2++ ) {
      bignum_div4(n1, n2, &n3, &n4);
    }
    t2 = clock();
    total1 = (t2-t1+0.0)/CLOCKS_PER_SEC;
    t1 = clock();
    for ( k2 = 0; k2 < REP; k2++ ) {
      bignum_div5(n1, n2, &n3, &n4);
    }
    t2 = clock();
    total2 = (t2-t1+0.0)/CLOCKS_PER_SEC;
    printf("%.10f, %.10f\n", total1, total2);
    fprintf(stderr,"%.10f, %.10f\n", total1, total2);
  }

  return 0;
}
