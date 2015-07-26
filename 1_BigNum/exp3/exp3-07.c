#include <stdio.h>
#include "BigNumLib.h"

int main(void) {
  BigNum n1, n2, n3, n4;
  BigNum t;
  BigNum s;

  bignum_input(&n1);
  bignum_input(&n2);

  bignum_div3(n1, n2, &n3, &n4);

  bignum_mlt(n2, n3, &t);
  bignum_add(t, n4, &s);

  if ( bignum_cmp(n1, s) != 0 ) {
    puts("検算結果が異なる");
    printf("s:");bignum_output(s);
    return 1;
  }

  puts("正しい");
  printf("整商:");bignum_output(n3);
  printf("剰余:");bignum_output(n4);

  return 0;
}
