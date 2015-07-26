#include <stdio.h>
#include "BigNumLib.h"

int main(void) {
  BigNum n1, n2;
  int a;
  BigNum n4;
  BigNum s;

  bignum_input(&n1);
  bignum_input(&n2);

  bignum_div1(n1, n2, &a, &n4);

  bignum_scl(&n2, a);
  bignum_add(n2, n4, &s);

  if ( bignum_cmp(n1, s) != 0 ) {
    puts("検算結果が異なる");
    printf("s:");bignum_output(s);
    return 1;
  }

  puts("正しい");
  printf("整商:%4d\n剰余:", a);
  bignum_output(n4);

  return 0;
}
