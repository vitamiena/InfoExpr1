//====================================================================
//  工学部「情報環境実験１」  例題プログラム
//  指定範囲の乱数と乱列の生成
//--------------------------------------------------------------------
//  RandSeq RandSeq.h
//  Linux  GCC 4.4
//--------------------------------------------------------------------
//  富永研究室  tominaga 富永浩之
//  2015.05.25
//====================================================================


//====================================================================
//  事前処理
//====================================================================


//====================================================================
//  大域宣言
//====================================================================

//--------------------------------------------------------------------
//  データ型
//--------------------------------------------------------------------

typedef  int                 Data;
typedef  enum {FALSE, TRUE}  Bool;


//====================================================================
//  指定範囲の乱数の生成
//====================================================================

double frand(void); 
double frand2(double low, double hig);
int irand(int n); 
int irand2(int low, int hig);


//====================================================================
//  乱順列の生成
//====================================================================

void qrand(Data seq[], int n);
void crand(Data seq[], int n, int c);
void crand2(Data seq[], int n, int c);
void prand(Data seq[], int n, double p);


//====================================================================
//  補助関数
//====================================================================

void exch_rand(Data seq[], int n);
void arr_swap(Data seq[], int p1, int p2);

