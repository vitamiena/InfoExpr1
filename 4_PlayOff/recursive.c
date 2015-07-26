#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "recursive.h"

//---------------------------------------------------------
// 配列の出力
//---------------------------------------------------------
void arr_output(int arr[], int num, int f)
{
  int k;
  for ( k = 0; k < num; k++ ) { printf("%d ", arr[k]); }
  if ( f == 1 ) {
    puts("");
  }
}

//---------------------------------------------------------
// 正奇数の分割数の再帰呼出関数
//---------------------------------------------------------
int enum_parti1(int num, int upp, int len)
{
  int seq[LEN];  // 分割数列
  int pos = 0;

  return enum_parti1_(seq, num, upp, len, pos);
}

//---------------------------------------------------------
// 正奇数の分割数の再帰呼出関数本体
//---------------------------------------------------------
int enum_parti1_(int seq[], int num, int upp, int len, int pos) {
  int s = 0;

  if ( num < 0 || upp < 0 || pos < 0 ) { return 0; }

  if ( upp%2 == 0 ) { upp--; }

  if ( num == 0 ) { arr_output(seq, pos, 1); return 1; }
  if ( upp == 0 || len == 0 ) { return 0; }
  if ( num > upp*len ) { return 0; }
  if ( upp > num ) { upp = num%2 == 0 ? num-1:num; }
  if ( len > num ) { len = num; }
  seq[pos++] = upp;
  s += enum_parti1_(seq, num-upp, upp, len-1, pos);
  pos--;
  s += enum_parti1_(seq, num, upp-2, len, pos);

  return s;
}
//---------------------------------------------------------
// 硬貨の支払パターン
//---------------------------------------------------------
int enum_money(int coin[], int len, int mny, int cnt)
{
  int seq[LEN];
  int pos = 0;
  int j;
  /*
  for ( j = len-1; j >= 0; j-- ) {
    printf("%3d ", coin[j]);
  }
  printf("  N\n");
  for ( j = 0; j <= len; j++ ) {
    printf("----");
  }
  puts("");
  */

  return enum_money_(coin, len, mny, cnt, seq, pos);
}

int enum_money_(int coin[], int len, int mny, int cnt, int seq[], int pos)
{
  int cn;
  int s = 0;
  int i;

  if ( mny < 0 ) { return 0; }
  if ( mny == 0 ) {/* show_money(coin, seq, pos);*/ return 1; }
  if ( len == 0 ) { return 0; }
  cn = coin[len-1];
  if ( cn == 1 ) {
    if ( mny <= cnt ) {
      for ( i = 0; i < mny; i++ ) {
        seq[pos++] = 1;
      }
      //show_money(coin, seq, pos);
      return 1;
    } else {
      return 0;
    }
  }

  if ( mny < cn ) {
    s += enum_money_(coin, len-1, mny, cnt, seq, pos);
  } else {
    seq[pos++] = cn;
    s += enum_money_(coin, len, mny-cn, cnt-1, seq, pos);
    pos--;
    s += enum_money_(coin, len-1, mny, cnt, seq, pos);
  }
  return s;
}

void show_money(int coin[], int seq[], int seq_num) {
  int i, j;
  int show[LEN] = {0};
  int coin_num;

  for ( i = 0; coin[i] != -1; i++) {}
  coin_num = i;
  j = coin_num-1;

  for ( i = 0; i < j; i++ ) {
    show[i] = 0;
  }
  i = 0;

  while ( i < seq_num ) {
    while ( seq[i] == coin[j] ) {
      if ( i >= seq_num ) { break; }
      show[j]++;
      i++;
    }
    j--;
  }

  for ( j = coin_num-1; j >= 0; j-- ) {
    printf("%3d ", show[j]);
  }
  printf("%3d\n", seq_num);
}

//---------------------------------------------------------
// 正奇数の分割数の再帰呼出関数
//---------------------------------------------------------
int sq_parti(int num, int upp, int len)
{
  int seq[LEN];  // 分割数列
  int sum = 0;   // 分割数の総和
  int pos = 0;

  return sq_parti_(seq, num, upp, len, pos, sum);
}

//---------------------------------------------------------
// 正奇数の分割数の再帰呼出関数本体
//---------------------------------------------------------
int sq_parti_(int seq[], int num, int upp, int len, int pos, int sum)
{
  int s = 0;

  while ( upp > 0 ) {
    if ( upp > seq[pos-1] ) { upp--; continue; } // 最後の分割数より大きいなら、次へ
    seq[pos++] = SQ(upp);
    sum += SQ(upp);
    if ( sum == num ) {
      //arr_output(seq, pos, 1);
      s++;
    } else if ( sum < num && pos < len  ) {
      s += sq_parti_(seq, num, upp, len, pos, sum);
    }
    sum -= seq[--pos];
    upp--;
  }

  return s;
}

int make_val(int num, int upp, int len)
{
  int i, j, k;
  int ti, tj, tk;

  if ( num >= NUM || upp >= UPP || len >= LENGTH ) { return -1; }
  if ( num < 0 || upp < 0 || len < 0 ) { return -1; }

  for ( i = 0; i <= num; i++) {
    for ( j = 0; j <= upp; j++ ) {
      for ( k = 0; k <= len; k++ ) {
        if ( i == 0 ) { Val[i][j][k] = 1; }
        else if ( j == 0 || k == 0 ) { Val[i][j][k] = 0; }
        else if ( j == 1 && i <= k) {Val[i][j][k] = 1; }
        else { Val[i][j][k] = -1; }
      }
    }
  }

  for ( i = 1; i <= num; i++ ) {
    for ( j = 1; j <= upp; j++ ) {
      for ( k = 1; k <= len; k++ ) {
        if ( Val[i][j][k] != -1 ) { continue; }
        ti = i;
        tj = i < SQ(j) ? (int)sqrt(i) : j;
        tk = i < k ? i : k;
        Val[i][j][k] = Val[ti][tj-1][tk];
        if ( ti >= tj ) { Val[i][j][k] += Val[ti-SQ(tj)][tj][tk-1]; }
        //        printf("%d %d %d : %d\n", i, j, k, val[i][j][k]);
      }
    }
  }

  return Val[num][upp][len];
}

//---------------------------------------------------------
// 正奇数の分割数の再帰呼出関数
//---------------------------------------------------------
int sq_parti2(int num, int upp, int len)
{
  if ( num == 0 ) { return 1; }
  if ( upp == 0 || len == 0 ) { return 0; }
  if ( num > SQ(upp)*len ) { return 0; }
  if ( upp == 1 && num <= len ) { return 1; }

  if ( SQ(upp) > num ) { upp = (int)sqrt(num); }
  if ( num < len ) { len = num; }

  if ( num < NUM && upp < UPP && len < LENGTH && Val[num][upp][len] != 0 ) {
    //puts("val");
    return Val[num][upp][len];
  } else {
    return sq_parti2(num-SQ(upp), upp, len-1) + sq_parti2(num, upp-1, len);
  }
}

int sq_parti3(int num, int upp, int len)
{
  int data;

  if ( num == 0 ) { return 1; }
  if ( upp == 0 || len == 0 ) { return 0; }
  if ( num > SQ(upp)*len ) { return 0; }
  if ( upp == 1 && num <= len ) { return 1; }

  if ( SQ(upp) > num ) { upp = (int)sqrt(num); }
  if ( num < len ) { len = num; }

  data = get_val2(num, upp, len);
  if ( data != -1 ) {
    return data;
  } else {
    data = sq_parti3(num-SQ(upp), upp, len-1) + sq_parti3(num, upp-1, len);
    store_val2(num, upp, len, data);
    return data;
  }
}

void init_val2()
{
  int i;

  for ( i = 0; i < HASH; i++ ) {
    Val2[i] = NULL;
  }
}

int store_val2(int num, int upp, int len, int data)
{
  int key;
  Parti *cell = NULL;

  key = hash(num, upp, len);

  cell = (Parti *)malloc((int)sizeof(Parti));
  if ( cell == NULL ) { puts("memory error"); return 0; }

  cell->num = num; cell->upp = upp;
  cell->len = len; cell->data = data;

  cell->next = Val2[key];
  Val2[key] = cell;

  return 1;
}

int get_val2(int num, int upp, int len)
{
  int key;
  Parti *cell;

  key = hash(num,upp,len);

  cell = Val2[key];

  while ( cell != NULL ) {
    if ( cell_match(cell, num, upp, len) == 1 ) {
      return cell->data;
    }
    cell = cell->next;
  }

  return -1;
}

int hash(int num, int upp, int len)
{
  int key = num+upp+len;

  return key % HASH;
}

int cell_match(Parti *cell, int num, int upp, int len)
{
  if ( cell->num != num ) { return 0; }
  if ( cell->upp != upp ) { return 0; }
  if ( cell->len != len ) { return 0; }
  return 1;
}

int count_cell()
{
  int ct = 0;
  Parti *cell;
  int i;

  for ( i = 0; i < HASH; i++ ) {
    cell = Val2[i];
    while ( cell != NULL ) {
      ct++;
      cell = cell->next;
    }
  }

  return ct;
}

int ct_egypt(int fc, int fm, int upp,int min, int len) {
  int count = 0;
  int x;
  int r, s;
  if (fc == 0) {
    return 1;
  }
  if (len == 0) {
    return 0;
  }


  for ( x = min; x <= upp; ++x) {
    r = fc * x - fm;
    s = fm * x;
    if (r < 0) {
      continue;
    }
    count += ct_egypt(r, s, upp / x, x, len - 1);
  }
  return count;
}
