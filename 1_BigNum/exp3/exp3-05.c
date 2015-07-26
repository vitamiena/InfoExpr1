#include <stdio.h>
#include <math.h>
#include "BigNumLib.h"

int main(void) {
  BigNum n1, n3;
  int t4;
  BigNum t;
  int a2, a4;
  BigNum s;
  int k;

  bignum_init(&n1, 1);
  a2 = pow(2, 23)+1;

  bignum_div2(n1, a2, &n3, &a4);
  for ( k = 1; k < 1024; k++ ) {
    bignum_scl(&n3, 2);
    a4 *= 2;

    bignum_inc(&n3, a4/a2);
    a4 %= a2;
  }

  printf("整商:\n");bignum_output(n3);
  printf("剰余:\n");printf("%d\n", a4);

  return 0;
}
