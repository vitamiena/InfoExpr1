//====================================================================
//  工学部「情報環境実験１」  例題プログラム
//  指定範囲の乱数と乱列の生成
//--------------------------------------------------------------------
//  RandSeq RandSeq.c
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2015.05.25
//====================================================================


//====================================================================
//  概略仕様
//====================================================================


//====================================================================
//  事前処理
//====================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "RandSeq.h"


//====================================================================
//  指定範囲の乱数の生成
//====================================================================

//--------------------------------------------------------------------
//  0以上1未満の実数値乱数
//--------------------------------------------------------------------

double frand(void) 
{
  return rand() / (RAND_MAX +1.0);    // +1.0 で実数化
}

//--------------------------------------------------------------------
//  low以上hig未満の実数値乱数
//--------------------------------------------------------------------

double frand2(double low, double hig) 
{
  return (hig-low) * frand() + low;
}

//--------------------------------------------------------------------
//  n未満の自然数の整数値乱数
//--------------------------------------------------------------------

int irand(int n) 
{ 
  return (int) (n * frand());    // int型への型変換
}

//--------------------------------------------------------------------
//  low以上hig以下の整数値乱数
//--------------------------------------------------------------------

int irand2(int low, int hig) {
  return irand(hig-low+1) + low;    // hig-low+1通り
}


//====================================================================
//  乱順列の生成
//====================================================================

//--------------------------------------------------------------------
//  交換法による乱順列の生成
//--------------------------------------------------------------------

void qrand(Data seq[], int n) 
{
  int k;
  for ( k = 0; k < n; k++ ) { seq[k] = k; }    // 初期化として整列を格納
  exch_rand(seq, n);                           // 一様な要素交換
}

//--------------------------------------------------------------------
//  一様な要素交換
//--------------------------------------------------------------------

void exch_rand(Data seq[], int n)  
{
  int k, t;
  for ( k = 1; k < n; k++ ) { 
    t = irand(k+1); 
    arr_swap(seq, t, k);         // kとk以下のtの位置で交換
  }
}

//--------------------------------------------------------------------
//  要素交換
//--------------------------------------------------------------------

void arr_swap(Data seq[], int p1, int p2) 
{
  Data t;
  t = seq[p1]; seq[p1] = seq[p2]; seq[p2] = t;
}


//====================================================================
//  半乱順列の生成
//====================================================================

//--------------------------------------------------------------------
//  回数指定による半乱順列
//--------------------------------------------------------------------

void crand(Data seq[], int n, int c) 
{
  int p1, p2;
  while ( c-- > 0 ) {                // c回だけ交換
    p1 = irand(n); p2 = irand(n); 
    arr_swap(seq, p1, p2);  
  }
}

//--------------------------------------------------------------------
//  回数指定による半乱順列(必ず交換)
//--------------------------------------------------------------------

void crand2(Data seq[], int n, int c) 
{
  int p1, p2;
  while ( c-- > 0 ) {
    p1 = irand(n); 
    do { p2 = irand(n); } while ( p1 == p2 );    // p2はp1と異なる値を選ぶ
    arr_swap(seq, p1, p2);    
  }
}

//--------------------------------------------------------------------
//  確率指定による半乱順列
//--------------------------------------------------------------------

void prand(Data seq[], int n, double p) 
{
  int k, t;
  for ( k = 1; k < n; k++ ) {    
    if ( frand() < p ) {         // 確率p未満のときのみ
      t = irand(k+1);            // k以下の整乱数
      arr_swap(seq, t, k);       // 要素の交換
    }
  }
}


//====================================================================
//  補助関数
//====================================================================

