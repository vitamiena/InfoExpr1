#include <stdio.h>
#include "BigNumLib.h"

int main(void) {
  BigNum n1, n2;
  BigNum ans1, ans2;

  bignum_input(&n1);
  bignum_input(&n2);

  bignum_gcd1(n1, n2, &ans1);
  bignum_gcd1(n1, n2, &ans2);

  if ( bignum_cmp(ans1, ans2) != 0 ) {
    puts("Error!");
    printf("n1:");bignum_output(n1);
    printf("n2:");bignum_output(n1);

    printf("ans1:");bignum_output(ans1);
    printf("ans2:");bignum_output(ans2);
    return 1;
  } else {
    bignum_output(ans1);
  }

  return 0;
}
