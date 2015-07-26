//====================================================================
//  工学部「情報環境実験１」(富永)  例題
//  多倍長整数の計算  四則演算の関数実装
//--------------------------------------------------------------------
//  BigNum  BigNumLib.c
//  ライブラリ
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2015.05.20  v2.0
//--------------------------------------------------------------------
//  s13t210 太田翔也
//  2015.05.20  v2.0  元ソース
//====================================================================


//====================================================================
//  仕様
//====================================================================

/*--------------------------------------------------------------------

4桁ごとに区切って、多倍長整数を扱う。1000進数による計算と同等である。
多倍長整数を構造体 BigNum で定義する。
四則演算では、計算範囲の吟味を行い、正常計算かどうかを返却する。
四則演算の結果は、ポインタ引数に格納する。
除算は、整除演算とし、整商と剰余を同時に計算する。
単倍長整数とは、10000未満の自然数を指す。負数は扱わない。

--------------------------------------------------------------------*/


//====================================================================
//  前処理
//====================================================================

//--------------------------------------------------------------------
//  ヘッダ指定
//--------------------------------------------------------------------

#include <stdio.h>
#include "BigNumLib.h"


//====================================================================
//  関数定義(入出力)
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の入力
//--------------------------------------------------------------------

Bool bignum_input(BigNum *n)
{
  //----  局所宣言
  int u;    // 多倍長の節数
  int t;    // 一時変数
  int k;    // 反復変数

  //----  初期処理
  bignum_init(n, 0);    // 結果を0に初期化

  //----  節数の入力と確認
  scanf("%d", &u);    // 節数の入力
  if ( u > UNI ) { return FALSE; }    // 節数の超上なら打切

  //----  各節の入力と確認
  for ( k = u-1; k >= 0; k-- ) {    // 上位節から
    scanf("%d", &t);    // 入力値の各格納
    if ( t >= RAD ) { return FALSE; }    // 節値が基数の以上なら打切
    (*n).num[k] = t;    // 構造体の配列メンバに節値を格納
  }

  //----  事後処理
  bignum_chk(n);    // 実際の桁数の計算

  //----  返却処理
  return TRUE;    // 処理が正常に完了
}

// 現在の入力方法は、多倍長の節数を指定し、各節を上位節から入力する。
// 節の区切は、空白1字とする。各節の上位桁の 0 は省略できる。
// 4  16 2031 45 0007 → 16 2031 0045 0007
// 改良として、gets() と sscanf() を用いて、
// 16203100450007 のように桁数を指定せずに入力できるようにする。

//--------------------------------------------------------------------
//  多倍長整数の出力
//--------------------------------------------------------------------

void bignum_output(const BigNum n)
{
  //----  局所宣言
  int k = n.uni-1;    // 最上位節

  //----  0の出力
  if ( k < 0 ) { k = 0; }

  //----  最上位桁の出力(0無)
  printf("%4d ", n.num[k]);

  //----  下位桁の出力(0付)       // 最上位桁の 0 は出力せず
  while ( --k >= 0 ) {
    printf("%04d ", n.num[k]);    // 途中桁の0は出力
  }

  //----  出力後の改行
  puts("");
}


//====================================================================
//  関数定義(補助関数)
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の初期化(単倍長整数の多倍長化)
//--------------------------------------------------------------------

Bool bignum_init(BigNum *b, int a)
{
  //----  局所宣言
  int k;    // 反復変数

  //----  事前処理
  // 初期値の吟味
  if ( a < 0 || a >= RAD ) { return FALSE; }    // 節値として不適なら打切

  //----  初期処理
  b->uni = 1;    // 多倍長の節数(1)
  b->dig = 0;    // 実際の桁数(0)

  //----  計算処理
  // 各節の0による初期化
  for ( k = 0; k < UNI; k++ ) { b->num[k] = 0; }
  if ( a == 0 ) { return TRUE; }    // a＝0から処理完了

  //----  事後処理
  // 初期値の代入
  b->num[0] = a;    // 最下位節に代入
  while ( a > 0 ) {
    b->dig++; a /= TEN;    // 節値を割りながら桁数を加算
  }

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  多倍長整数の正規化(節数と桁数の格納)
//--------------------------------------------------------------------

void bignum_chk(BigNum *b)
{
  //----  局所宣言
  int t;    // 最上位の節値
  int k;    // 反復変数

  //----  計算処理
  // 節数の確認
  for ( k = UNI-1; k >= 0; k-- ) {
    if ( b->num[k] != 0 ) { break; }    // 最上位節の検知
  }
  // 0の例外処理
  if ( k < 0 ) { k = 0; }
  // 節数の格納
  b->uni = k+1;            // num[k+1]＝0でnum[k]≠0のとき、節数はk+1

  //----  計算処理
  // 節数による桁数の概算
  b->dig = k * LEV;        // num[k-1]〜num[0]は、LEV桁分ある
  t = b->num[k];           // 最上位桁num[k]は、1〜LEV桁しかない
  // 桁数の格納
  while ( t > 0 ) {
    b->dig++; t /= TEN;    // 節値を割りながら桁数を加算
  }
}

//--------------------------------------------------------------------
//  多倍長整数の大小比較
//--------------------------------------------------------------------

int bignum_cmp(BigNum b1, BigNum b2)
{
  //----  局所宣言
  int k;    // 反復変数

  //----  大小判定
  // strcmp()と同様の返却値
  for ( k = UNI-1; k >= 0; k-- ) {                 // 上位節からの比較
    if ( b1.num[k] < b2.num[k] ) { return -1; }    // 途中で正順のとき
    if ( b1.num[k] > b2.num[k] ) { return +1; }    // 途中で逆順のとき
  }

  //----  返却処理
  return 0;    // 完全に相等のとき
}

//--------------------------------------------------------------------
//  多倍長整数の零判定
//--------------------------------------------------------------------

Bool bignum_zero(BigNum b)
{
  return  ( b.dig == 0 );
}

//--------------------------------------------------------------------
//  多倍長整数の近傍判定
//--------------------------------------------------------------------

Bool bignum_near(BigNum b1, BigNum b2, int a)
{
  //----  局所宣言
  BigNum t;

  //----  計算処理
  // |b1-b2|≦aの判定
  if ( bignum_cmp(b1, b2) > 0 ) { t = b1; b1 = b2; b2 = t; }
  bignum_inc(&b1, a);

  //----  返却処理
  return ( bignum_cmp(b2, b1) <= 0 );
}

//--------------------------------------------------------------------
//  多倍長整数の桁移動
//--------------------------------------------------------------------

Bool bignum_shift(BigNum *b, int s)
{
  //----  局所宣言
  Bool flag;    // 処理完了フラグ
  int k;        // 反復変数

  //----  事前処理
  if ( s == 0 ) { return TRUE; }    // 移動なし
  flag = TRUE;    // 桁溢れが発生していない

  //----  計算処理
  // 右移動
  if ( s < 0 ) {
    for ( k = 0; k < UNI; k++ ) {
      if ( k-s < UNI ) { b->num[k] = b->num[k-s]; }
        else { b->num[k] = 0; }
    }
  }

  //----  計算処理
  // 左移動
  if ( s > 0 ) {
    for ( k = UNI-1; k >= 0; k-- ) {
      // 桁溢れの吟味
      if ( k >= UNI-s && b->num[k] != 0 ) { flag = FALSE; }
      if ( k-s >= 0 ) { b->num[k] = b->num[k-s]; }
        else { b->num[k] = 0; }
    }
  }

  //----  事後処理
  bignum_chk(b);    // 節数と桁数の格納

  //----  返却処理
  return flag;    // 処理完了フラグ
}

//--------------------------------------------------------------------
//  多倍長整数の部分複写(節の指定位置から指定節数の部分)
//--------------------------------------------------------------------

Bool bignum_copy(BigNum b1, int p, int u, BigNum *b0)
{
  //----  局所宣言
  int k;    // 反復変数

  //----  初期化
  bignum_init(b0, 0);

  //----  事前処理
  // 桁溢れの吟味
  if ( p + u > UNI ) { return FALSE; }

  //----  計算処理
  for ( k = 0; k < u; k++ ) {    // 指定節数uの間
    b0->num[k] = b1.num[p+k];    // 指定位置p以降から複写
  }

  //----  事後処理
  bignum_chk(b0);    // 節数と桁数の格納

  //----  返却処理
  return TRUE;    // 正常に処理完了
}


//====================================================================
//  関数定義(加減算)
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の加算
//--------------------------------------------------------------------

Bool bignum_add(BigNum b1, BigNum b2, BigNum *b0)
{
  //----  局所宣言
  int c;    // 節の繰上り
  int v;    // 当該の節値
  int k;    // 反復変数

  //----  初期処理
  bignum_init(b0, 0);    // 和を0に
  c = 0;                 // 繰上りを0に

  //----  計算処理
  for ( k = 0; k < UNI; k++ ) {       // 下位節から
    v = b1.num[k] + b2.num[k] + c;    // 節同士の加算(繰上り付)
    c = v / RAD;                      // 繰上りの計算(整商による)
    b0->num[k] = v % RAD;             // 繰上りの清算(剰余による)
  }

  //----  事後処理
  if ( c != 0 ) { return FALSE; }    // 最上位桁での繰上りの吟味
  bignum_chk(b0);                    // 節数と桁数の格納

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  多倍長整数の増分(多倍長整数への単倍長整数の加算更新)
//--------------------------------------------------------------------

Bool bignum_inc(BigNum *b, int a)
{
  //----  局所宣言
  int k;    // 反復変数

  //----  和の初期化
  b->num[0] += a;

  //---- 計算処理
  // 繰上りの清算
  for ( k = 0; k < UNI-1; k++ ) {    // 下位節から
    if ( b->num[k] >= RAD ) {
      b->num[k] -= RAD;
      b->num[k+1]++;
    }
  }

  //----  事後処理
  if ( b->num[k] > RAD ) { return FALSE; }    // 最上位桁での繰上りの吟味
  bignum_chk(b);                              // 節数と桁数の格納

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  多倍長整数の減算
//--------------------------------------------------------------------

Bool bignum_sub(BigNum b1, BigNum b2, BigNum *b0)
{
  //----  局所宣言
  int c;    // 節の繰下り
  int v;    // 当該の節値
  int k;    // 反復変数

  //----  初期処理
  bignum_init(b0, 0);    // 和の初期化
  c = 0;                 // 繰下りを0に

  //----  減算
  for ( k = 0; k < UNI; k++ ) {           // 下位節から
    v = b1.num[k] - b2.num[k] - c;        // 節同士の加算(繰上り付)
    c = 0;                                // 繰下りの初期化
    while ( v < 0 ) { v += RAD; c++; }    // 繰下りの計算(剰余による)
    b0->num[k] = v;                       // 節値の格納
  }

  //----  事後処理
  if ( c != 0 ) { return FALSE; }    // 最上位桁での繰下りの吟味
  bignum_chk(b0);                    // 節数と桁数の格納

  //----  返却処理
  return TRUE;    // 正常に処理完了
}


//====================================================================
//  関数定義(乗算)
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の多倍長整数による乗算(畳込法による)
//--------------------------------------------------------------------
Bool bignum_mlt(BigNum b1, BigNum b2, BigNum *b0)
{
  //----  局所宣言
  int c;             // 繰上り
  int k1, k2, k0;    // 反復変数

  //----  初期処理
  bignum_init(b0, 0);    // 積の初期化

  //----  事前処理
  // 計算範囲の吟味
  if ( b1.dig + b2.dig > UNI * LEV ) { return FALSE; }    // 桁溢れ

  //----  計算処理
  // 桁同士の乗算と加算
  for ( k1 = 0; k1 < b1.uni; k1++ ) {
    for ( k2 = 0; k2 < b2.uni; k2++ ) {
      if ( k1 + k2 >= UNI ) { continue; }           // 添字の範囲外
      b0->num[k1+k2] += b1.num[k1] * b2.num[k2];    // 桁ごとの加算
      bignum_car(&(b0->num[k1+k2]));                // 繰上りの清算
    }
  }

  //----  計算処理
  // 繰上りの清算
  c = 0;
  for ( k0 = 0; k0 < UNI; k0++ ) {                // 下位桁から
    b0->num[k0] += c;                             // 桁同士の加算
    c = b0->num[k0] / RAD; b0->num[k0] %= RAD;    // 繰上りの清算
  }

  //----  事後処理
   bignum_chk(b0);    // 節数と桁数の格納

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  繰上りの清算
//--------------------------------------------------------------------

Bool bignum_car(int *p)
{
  if ( *p < RAD ) { return FALSE; }
  *(p+1) += *p / RAD;    // 上位桁への繰上りの加算
  *p %= RAD;             // 当該桁の繰上りの除去
  return TRUE;
}

//--------------------------------------------------------------------
//  多倍長整数の倍分(多倍長整数への単倍長整数の乗算更新)
//--------------------------------------------------------------------

Bool bignum_scl(BigNum *b, int a)
{
  //----  局所宣言
  int k;    // 反復変数

  //---- 計算処理
  // 桁ごとの乗算
  for ( k = 0; k < UNI; k++ ) {    // 下位節から
      b->num[k] *= a;
  }
  // 繰上りの清算
  for ( k = 0; k < UNI-1; k++ ) {    // 下位節から
    while ( b->num[k] >= RAD ) {
      b->num[k] -= RAD;
      b->num[k+1]++;
    }
  }

  //----  事後処理
  if ( b->num[k] > RAD ) { return FALSE; }    // 最上位桁での繰上りの吟味
  bignum_chk(b);                              // 節数と桁数の格納

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  カラツバ法による多倍長整数の乗算
//--------------------------------------------------------------------

Bool bignum_mlt2(BigNum b1, BigNum b2, int p, int s, BigNum *b0)
{
  return TRUE;
}


//====================================================================
//  関数定義(累乗)
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の累乗
//--------------------------------------------------------------------

Bool bignum_pow(BigNum b1, int e, BigNum *b0)
{
  //----  返却処理
  return bignum_pow1(b1, e, b0);    // 素朴法による実装
  //return bignum_pow2(b1, e, b0);    // 二分法による実装
  // &(*b0)でb0を実引数に
}

//--------------------------------------------------------------------
//  素朴法による多倍長整数の累乗
//--------------------------------------------------------------------

Bool bignum_pow1(BigNum b1, int e, BigNum *b0)
{
  //----  局所宣言
  // 一時変数
  BigNum bt;

  //----  事前処理
  // 計算範囲の吟味
  if ( e < 0 ) { return FALSE; }
  if ( b1.dig * e > UNI*LEV ) { return FALSE; }
  //----  初期処理
  // 結果*b0を1に初期化
  bignum_init(b0, 1);

  //----  計算処理
  // 素朴法による累乗計算
  while ( e-- > 0 ) {
    bt = *b0;
    bignum_mlt(b1, bt, b0);
  }
  //----  事後処理
  // 節数と桁数の格納
  bignum_chk(b0);
  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  二分累乗法による多倍長整数の累乗
//--------------------------------------------------------------------

Bool bignum_pow2(BigNum b1, int e, BigNum *b0)
{
  //----  局所宣言
  BigNum p;    // 二乗値の格納
  BigNum t;

  //----  事前処理
  // 計算範囲の吟味
  if ( e < -1 ) { return FALSE; }
  if ( b1.dig * e > UNI*LEV ) { return FALSE; }

  //----  初期処理
  // 結果*b0を1に初期化
  bignum_init(b0, 1);
  // 入力b1をpに格納
  p = b1;

  //----  計算処理
  // 二分法による累乗計算
  while ( e > 0 ) {
    //   指数eの奇偶で場合分け
    if ( e%2 == 0 ) {
      e /= 2;
      bignum_sq(&p);
    } else {
      e--;
      t = *b0;
      bignum_mlt(p, t, b0);
    }
  }

  //----  事後処理
  // 節数と桁数の格納
  bignum_chk(b0);
  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  多倍長整数の二乗(自己代入)
//--------------------------------------------------------------------

Bool bignum_sq(BigNum *b)
{
  BigNum bt;
  bt = *b;

  if ( b->dig * 2 > UNI*LEV ) { return FALSE; }

  bignum_mlt(bt, bt, b);

  return TRUE;
}


//====================================================================
//  関数定義(除算)
//====================================================================

//--------------------------------------------------------------------
//  多倍長整数の除算(整商と剰余)
//--------------------------------------------------------------------

Bool bignum_div(BigNum b1, BigNum b2, BigNum *b3, BigNum *b4)
{
  //----  計算処理
  /* bignum_div3(b1, b2, b3, b4); */
  bignum_div5(b1, b2, b3, b4);
  //----  返却処理
  return TRUE;
}

//--------------------------------------------------------------------
//  逐次法による多倍長整数の単倍長整数を整商とする除算(整商と剰余)
//--------------------------------------------------------------------

Bool bignum_div1(BigNum b1, BigNum b2, int *a3, BigNum *b4)
{
  //----  局所宣言
  BigNum t;    // 一時変数
  int k;       // 反復変数

  //----  初期処理
  *a3 = 0;    // 整商の初期化
  *b4 = b1;   // 剰余の初期化

  //----  計算処理
  // b1からb2を引けるだけ引く
  for ( k = 0; bignum_cmp(b1, b2) >= 0; k++ ) {
    bignum_sub(b1, b2, b4);
    b1 = *b4;
    (*a3)++;
  }
  // 引いた回数が整商で残った値が剰余

  //----  事後処理
  if ( *a3 >= RAD ) { return FALSE; }    // 桁溢れ

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  商立法による多倍長整数の単倍長整数による除算(整商と剰余)
//--------------------------------------------------------------------

Bool bignum_div2(BigNum b1, int a2, BigNum *b3, int *a4)
{
  //----  局所宣言
  int k;    // 反復変数

  //----  事前処理
  // 除数の吟味(0除算の禁止)
  if ( a2 == 0 ) { return FALSE; }

  //----  初期処理
  bignum_init(b3, 0);    // 整商の初期化
  *a4 = 0;               // 剰余の初期化

  //----  計算処理
  // 多倍長の各節をa2で除算
  for ( k = b1.uni-1; k > 0; k-- ) {
    // 整商を各節に格納し、剰余を更新
    b3->num[k] = b1.num[k] / a2;
    b1.num[k-1] += (b1.num[k] % a2) * RAD;
  }
  b3->num[0] = b1.num[k]/a2;
  *a4 = b1.num[k] % a2;
  //----  事後処理
  bignum_chk(b3);    // 節数と桁数の格納

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  多倍長整数の半分
//--------------------------------------------------------------------

Bool bignum_half(BigNum *b)
{
  //----  局所宣言
  int r;    // 剰余
  int k;    // 反復変数

  //---- 計算処理
  for ( k = UNI-1; k >= 0; k-- ) {    // 上位節から
      r = b->num[k] & 1;    // 奇偶
      b->num[k] >>= 1;       // 半分
    if ( r == 1 && k >= 1 ) {
      b->num[k-1] += RAD;   // 桁送り
    }
  }

  //----  事後処理
  bignum_chk(b);                              // 節数と桁数の格納

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  二分法による多倍長整数の多倍長整数による除算(整商と剰余)
//--------------------------------------------------------------------

Bool bignum_div3(BigNum b1, BigNum b2, BigNum *b3, BigNum *b4)
{
  //----  局所宣言
  BigNum low;    // 下端
  BigNum hig;    // 上端
  BigNum mid;    // 中央
  BigNum val;     // 計算値(除数と仮整商の積)
  BigNum t;      // 一時変数
  int sft;       // 上端の節数
  int cmp;       // 大小比較の結果

  //----  事前処理
  // 除数の吟味(0除算の禁止)
  if ( bignum_zero(b2) == TRUE ) { return FALSE; }

  //----  初期処理
  bignum_init(&low, 0);       // 下端の初期化(0)
  bignum_init(&hig, 1);       // 上端の仮値(1)
  sft = b1.uni-b2.uni+1;   // 上端の節数
  bignum_shift(&hig, sft);    // 上端の初期化(節移動)
  //----  計算処理
  //--  整商の計算
  while ( bignum_near(low, hig, 1) == 0 ) {
    //   上端と下端の中点として中央値をmidに格納
    bignum_add(low, hig, &mid);

    bignum_half(&mid);
    //   中央値midとb2の乗算をvalに格納l
    if ( bignum_mlt(mid, b2, &val) == FALSE ) {
      return FALSE;
    }
    //   b1とvalが等しければ脱出
    cmp = bignum_cmp(val, b1);
    if ( cmp == 0 ) {
      low = mid;
      break;
    }
    //   異なれば上端または下端を更新
    else if ( cmp > 0 ) {
      hig = mid;
    } else {
      low = mid;
    }
  }
  //--  整商の格納と剰余の計算
  // 下端値lowを整商*b3として格納
  *b3 = low;
  // 整商*b3とb2の乗算をvalに格納l
  bignum_mlt(*b3, b2, &val);
  // b1とvalの差を剰余として*b4に格納
  bignum_sub(b1, val, b4);
  //----  事後処理
  bignum_chk(b3);    // 節数の更新
  bignum_chk(b4);

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//-------------------------------------------------------------------
//  商立法による多倍長整数の多倍長整数による除算(整商と剰余)
//--------------------------------------------------------------------

Bool bignum_div4(BigNum b1, BigNum b2, BigNum *b3, BigNum *b4)
{
  //----  局所宣言
  int uni;     // 節数の差
  BigNum t;    // 一時変数
  int a;       // 各節の整商
  int k;       // 反復変数
  //----  事前処理
  // 除数の吟味(0除算の禁止)
  if ( bignum_zero(b2) == TRUE ) { return FALSE; }

  //----  初期処理
  bignum_init(b3, 0);                  // 整商の初期化(0)
  bignum_init(b4, 0);                  // 剰余の初期化(0)
  uni = b1.uni - b2.uni;            // 節数の差(整商の節数)
  if ( uni < 0 ) {
    *b4 = b1;
    return FALSE;
  }
  t = b2;
  bignum_shift(&t, uni);

  //----  計算処理
  for ( k = uni; k >= 0; k-- ) {
    bignum_div1(b1, t, &a, b4);
    b1 = *b4;
    bignum_shift(&t, -1);
    b3->num[k] = a;
  }

  //----  事後処理
  bignum_chk(b3);
  bignum_chk(b4);

  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//-------------------------------------------------------------------
//  商立法と二分法の組合せによる多倍長整数の多倍長整数による除算(整商と剰余)
//--------------------------------------------------------------------

Bool bignum_div5(BigNum b1, BigNum b2, BigNum *b3, BigNum *b4)
{
  //----  局所宣言
  BigNum t;
  int a;
  int uni;
  int k;

  //----  事前処理
  if ( bignum_zero(b2) == TRUE ) { return FALSE; }

  //----  初期処理
  bignum_init(b3, 0);
  bignum_init(b4, 0);
  uni = b1.uni - b2.uni+1;
  if ( uni < 0 ) {
    *b4 = b1;
    return FALSE;
  }


  bignum_shift(&b2, uni);

  //----  計算処理
  for ( k = uni; k >= 0; k-- ) {
    bignum_div3(b1, b2, &t, b4);
    b1 = *b4;
    bignum_shift(&b2, -1);
    b3->num[k] = t.num[0];
  }

  //----  事後処理
  bignum_chk(b3);
  bignum_chk(b4);

  //----  返却処理
  return TRUE;    // 正常に処理完了
}


//====================================================================
//  関数定義(累乗根)
//====================================================================

//--------------------------------------------------------------------
//  二分法による平方根の切捨整数値
//--------------------------------------------------------------------

Bool bignum_sqrt(BigNum b1, BigNum *b0)
{
  //----  局所宣言
  BigNum low;    // 下端
  BigNum hig;    // 上端
  BigNum mid;    // 中央
  BigNum val;    // 二乗値
  int sft;       // 上端の節数
  int cmp;       // 大小比較の結果

  //----  初期処理
  // lowを最下端0に初期化
  bignum_init(&low, 0);
  // higを最上端に初期化
  // 最上端は結果が含まれる範囲でキリの良い値
  // 1で初期化し、適当な節だけ左シフト
  sft = (UNI-1)/2;
  bignum_init(&hig, 1);
  bignum_shift(&hig, sft);
  //----  計算処理
  while ( bignum_near(hig, low, 1) == FALSE ) {
    //   上端と下端の中点として中央値midの計算
    bignum_add(low, hig, &mid);
    bignum_half(&mid);
    //   中央値midの二乗値val
    bignum_mlt(mid, mid, &val);
    //   二乗値valが入力値b1と等しければ脱出
    cmp = bignum_cmp(val, b1);
    if ( cmp == 0 ) {
      break;
    }//   異なれば上端または下端を更新
    else if ( cmp > 0 ) {
      hig = mid;
    } else {
      low = mid;
    }
  }

  //----  事後処理
  // 中央値midを結果b0に格納
  *b0 = mid;
  // 節数と桁数の更新
  bignum_chk(b0);
  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  二分法による累乗根の切捨整数値
//--------------------------------------------------------------------

Bool bignum_plrt(BigNum b1, int e, BigNum *b0)
{
  //----  局所宣言
  BigNum low;    // 下端
  BigNum hig;    // 上端
  BigNum mid;    // 中央
  BigNum val;    // 累乗値
  int sft;       // 上端の節数
  int cmp;       // 大小比較の結果

  //----  初期処理
  bignum_init(&low, 0);
  bignum_init(&hig, 1);
  sft = (UNI-1)/e;
  bignum_shift(&hig, sft);

  //----  計算処理
  while ( bignum_near(low, hig, 1) == 0 ) {
    bignum_add(low, hig, &mid);
    bignum_half(&mid);

    bignum_pow(mid, e, &val);
    cmp = bignum_cmp(val, b1);
    if ( cmp == 0 ) {
      break;
    } else if ( cmp > 0 ) {
      hig = mid;
    } else {
      low = mid;
    }
  }

  //----  事後処理
  *b0 = mid;
  bignum_chk(b0);

  //----  返却処理
  return TRUE;    // 正常に処理完了
}


//====================================================================
//  関数定義(最大公約数)
//====================================================================

//--------------------------------------------------------------------
//  最大公約数(ブレントの算法)
//--------------------------------------------------------------------

Bool bignum_gcd(BigNum b1, BigNum b2, BigNum *b0)
{
  return bignum_gcd1(b1, b2, b0);
}

//--------------------------------------------------------------------
//  ブレントの算法による最大公約数
//--------------------------------------------------------------------

Bool bignum_gcd1(BigNum b1, BigNum b2, BigNum *b0)
{
  //----  局所宣言
  BigNum e;
  BigNum t;
  int a;
  bignum_init(&e, 1);

  //----  計算処理
  while ( 1 ) {
    if ( bignum_zero(b1) ) { bignum_mlt(b2, e, b0);return; }
    if ( bignum_zero(b2) ) { bignum_mlt(b1, e, b0);return; }
    if ( bignum_cmp(b1, b2) == 0 ) { bignum_mlt(b1, e, b0);return; }
    if ( b1.num[0]%2 == 0 && b2.num[0]%2 == 0 ) {
      bignum_div2(b1, 2, &t, &a); b1 = t;
      bignum_div2(b2, 2, &t, &a); b2 = t;
      bignum_scl(&e, 2);
      continue;
    }
    if ( b1.num[0]%2 == 0 ) { bignum_div2(b1, 2, &t, &a); b1 = t; continue; }
    if ( b2.num[0]%2 == 0 ) { bignum_div2(b2, 2, &t, &a); b2 = t; continue; }
    if ( bignum_cmp(b1, b2) == 1 ) { bignum_sub(b1, b2, &t); b1 = t; }
    else { bignum_sub(b2, b1, &t); b2 = t; }
  }


  //----  返却処理
  return TRUE;    // 正常に処理完了
}

//--------------------------------------------------------------------
//  ユークリッドの互除法による最大公約数
//--------------------------------------------------------------------

Bool bignum_gcd2(BigNum b1, BigNum b2, BigNum *b0)
{
  //----  局所宣言
  BigNum t1, t2;

  //----  計算処理
  if ( bignum_zero(b2) ) { *b0 = b1; return ;}
  if ( bignum_zero(b1) ) { *b0 = b2; return ;}
  if ( bignum_div3(b1, b2, &t1, &t2) == FALSE ) {
    return FALSE;
  }
  b1 = t2;
  bignum_gcd2(b2, b1, b0);

  //----  返却処理
  return TRUE;    // 正常に処理完了
}
