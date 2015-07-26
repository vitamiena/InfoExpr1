#include <stdio.h>
#include "BigNumLib.h"

int main(void) {
  BigNum n1, n2, n3, n4;
  BigNum t1, t2, t3, t4;

  bignum_init(&n1, 2);
  if ( bignum_pow(n1, 400, &t1) == FALSE ) {puts("false1");return 1;}
  if ( bignum_pow(n1, 400, &t2) == FALSE ) {puts("false2");return 1;}
  if ( bignum_pow(n1, 223, &t3) == FALSE ) {puts("false3");return 1;}

  bignum_init(&n2, 2);
  if ( bignum_pow(n2, 345, &t4) == FALSE ) {puts("false4");return 1;}
  n2 = t4;

  bignum_mlt(t1, t2, &n1);
  t1 = n1;
  bignum_mlt(t1, t3, &n1);

  bignum_inc(&n2, -1);


  bignum_div5(n1, n2, &n3, &n4);

  printf("n1:");bignum_output(n1);
  printf("n2:");bignum_output(n2);


  printf("n3:");bignum_output(n3);
  printf("n4:");bignum_output(n4);

  return 0;
}
