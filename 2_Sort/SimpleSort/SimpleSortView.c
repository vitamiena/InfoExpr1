//====================================================================
//  C言語プログラミング  例題
//  単純整列算法  処理過程の視覚化
//  メイン ソース
//--------------------------------------------------------------------
//  SimpleSortView.c
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2002.02.07
//====================================================================

//====================================================================
//  仕様
//====================================================================

/*--------------------------------------------------------------------

実行時引数で、整列算法を指定する
1: 単純選択法  2: 単純交換法  3: 単純挿入法
SimpleSort.exe 3
データ数 = ?  6
配列要素 : ?  5 3 4 2 6 1

比較  交換  処理過程
             5  3  4  2  6  1
             3  5  4  2  6  1
             3  4  5  2  6  1
             2  3  4  5  6  1
             2  3  4  5  6  1
             1  2  3  4  5  6

単純挿入法  比較    回  交換    回

--------------------------------------------------------------------*/


//====================================================================
//  ヘッダ情報
//====================================================================

#include <stdio.h>
#include <stdlib.h>
#include "SimpleSortProc.h"

#define  SW   6
#define  TEN 10

//====================================================================
//  メイン関数
//====================================================================

int main(int argv, char *argc[]) {
  //----  宣言
  int sw = 0;        // 算法の種別
  char *str;         // 算法メッセージ
  int n;             // データ数
  Data seq[LEN];     // データ列
  int ct_cmp;    // 比較回数
  int ct_swp;    // 交換回数
  int c_type;        // 比較回数と交換回数の選択
  int time;          // 入力回数

  //----  算法の指定
  if ( argv == 5 ) {
    sw = atoi(argc[1]);
    n = atoi(argc[2]);
    c_type=atoi(argc[3]);
    time = atoi(argc[4]);
  }
  if ( sw < 1 || sw > SW ) {
    puts("1:選択法 2:交換法 3:挿入法 4:撹拌法 5:小人法 6:転置法");
    return 0;
  }
  //----  データ数と各要素の入力
  //printf("データ数 = ?  ");
  //scanf("%d", &n);        // データ数の入力
  //printf("配列要素 : ?  ");
  while ( time-- ) {
    ct_cmp = 0;
    ct_swp = 0;
    arr_input(seq, n);      // 各要素の入力
    puts("");

    //----  初期表示
    //puts("比較  交換 : 処理過程");
    proc_view(seq, n, ct_cmp, ct_swp);

    //----  整列算法の選択と実行
    switch ( sw ) {
    case 1:
      sel_sort_ct(seq, n, &ct_cmp, &ct_swp);
      str = "単純選択法";
      break;
    case 2:
      exch_sort_ct(seq, n, &ct_cmp, &ct_swp);
      str = "単純交換法";
      break;
    case 3:
      ins_sort_ct(seq, n, &ct_cmp, &ct_swp);
      str = "単純挿入法";
      break;
    case 4:
      shaker_sort_ct(seq, n, &ct_cmp, &ct_swp);
      str = "撹拌法";
      break;
    case 5:
      gnome_sort_ct(seq, n, &ct_cmp, &ct_swp);
      str = "小人法";
      break;
    case 6:
      trans_sort_ct(seq, n, &ct_cmp, &ct_swp);
      str = "転置法";
      break;
    }

    //----  整列結果の出力
    //printf("%s  比較 %3d回  交換 %3d回\n", str, ct_cmp, ct_swp);
    if ( c_type == 1 ) {
      printf("%3d, ", ct_cmp);
    } else if ( c_type == 2 ) {
      printf("%3d, ", ct_swp);
    }
  }
  return 0;
}
