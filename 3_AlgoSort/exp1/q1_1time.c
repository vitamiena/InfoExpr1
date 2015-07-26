//====================================================================
//  C言語 中級プログラミング  例題
//  高速整列算法
//--------------------------------------------------------------------
//  AlgoSort AlgoSortView.c
//  ソース本体
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2015.06.16
//====================================================================


//====================================================================
//  ヘッダ情報
//====================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AlgoSortProc.h"


//====================================================================
//  メイン関数
//====================================================================

int main(int argc, char *argv[])
{
  //----  宣言
  int sw = 0;        // 算法の種別
  char *str;         // 算法メッセージ
  int n;             // データ数
  int m;             // 入力乱順列数
  Data seq[LEN];     // データ列
  int ct_cmp = 0;    // 比較回数
  int ct_swp = 0;    // 交換回数
  clock_t start, end;

  //----  算法の指定
  if ( argc == 4 ) {
    sw = atoi(argv[1]);
    n = atoi(argv[2]);
    m = atoi(argv[3]);
  }
  if ( sw < 4 || sw > 8 ) {
    puts("実行時引数の不正");
    puts("4: シェル法  5: コーム法  6: クイック法  7: マージ法  8: ヒープ法");
    return 0;
  }

  //----  整列算法
  start = clock();
  while ( m-- ) {
    input_arr(seq, n);
    ct_cmp = 0;
    ct_swp = 0;

    switch ( sw ) {
    case 4:
      shell_sort(seq, n, &ct_cmp, &ct_swp);
      str = "シェル法";
      break;
    case 5:
      comb_sort(seq, n, &ct_cmp, &ct_swp);
      str = "コーム法";
      break;
    case 6:
      quick_sort(seq, n, &ct_cmp, &ct_swp);
      str = "クイック法";
      break;
    case 7:
      merge_sort(seq, n, &ct_cmp, &ct_swp);
      str = "マージ法";
      break;
    case 8:
      heap_sort(seq, n, &ct_cmp, &ct_swp);
      str = "ヒープ法";
      break;
    }
  }
  end = clock();
  printf("%f\n", (end-start+0.0)/CLOCKS_PER_SEC);
  //----  整列結果の出力
  return 0;
}
