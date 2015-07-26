#include <stdio.h>
#include "BigNumLib.h"

int main(void) {
  BigNum n1, n3;
  int a2, a4;
  BigNum s;

  bignum_input(&n1);
  scanf("%d", &a2);

  bignum_div2(n1, a2, &n3, &a4);
  s = n3;
  bignum_scl(&s, a2);
  bignum_inc(&s, a4);

  if ( bignum_cmp(n1, s) != 0 ) {
    puts("検算結果が異なる");
    printf("s:");bignum_output(s);
    return 1;
  }

  puts("正しい");
  printf("整商:");bignum_output(n3);
  printf("剰余:%4d", a4);

  return 0;
}
