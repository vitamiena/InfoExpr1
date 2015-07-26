#include <stdio.h>
#include "BigNumLib.h"

int main(void) {
  BigNum n1, n2;
  BigNum a1, a2, a3, a4;
  BigNum s1, s2;

  bignum_input(&n1);
  bignum_input(&n2);

  bignum_div4(n1, n2, &a1, &a2);
  bignum_div5(n1, n2, &a3, &a4);

  if ( bignum_cmp(a1, a3) != 0 ) {
    puts("商が異なる");
    printf("a1:");bignum_output(a1);
    printf("a3:");bignum_output(a3);
    return 1;
  }
  if ( bignum_cmp(a2, a4) != 0 ) {
    puts("剰余が異なる");
    printf("a2:");bignum_output(a2);
    printf("a4:");bignum_output(a4);
    return 1;
  }

  bignum_mlt(a1, n2, &s1);
  bignum_add(s1, a2, &s2);

  if ( bignum_cmp(n1, s2) != 0 ) {
    puts("検算結果が異なる");
    printf("s2:");bignum_output(s2);
    return 1;
  }

  puts("2つの解は等しく、正しい");
  bignum_output(a1);
  bignum_output(a2);

  return 0;
}
