#define SQ(X) ( (X) * (X) )

#define NUM 101
#define UPP 101
#define LENGTH 101
#define LEN 100
#define HASH 1000

typedef struct Parti {
  int num;
  int upp;
  int len;
  int data;
  struct Parti *next;
} Parti;

int Val[NUM][UPP][LENGTH]; // 被分割数、最大値、連長
Parti *Val2[HASH];

// 配列の出力
void arr_output(int arr[], int num, int f);

// 正奇数の分割数の再帰呼出関数
int enum_parti1(int num, int upp, int len);

// 正奇数の分割数の再帰関数本体
int enum_parti1_(int seq[], int num, int upp, int len, int pos);

// 金額の支払い方法の再帰呼出関数
int enum_money(int coin[], int len, int mny, int cnt);

// 金額の支払い方法の再帰関数本体
int enum_money_(int coin[], int len, int mny, int cnt, int seq[], int pos);

// 支払パターンを表形式で表示
void show_money(int coin[], int seq[], int seq_num);

// 正整数の分割数の走査
int sq_parti(int num, int upp, int len);

// 正整数の分割数の走査本体
int sq_parti_(int seq[], int num, int upp, int len, int pos, int sum);

// 反復法での二乗値の分割数
int make_val(int num, int upp, int len);

// 動的計画法による分割数
int sq_parti2(int num, int upp, int len);

// エジプト表記
int ct_egypt(int fc, int fm, int upp, int min, int len);

// ハッシュ関数

void init_val2();

int store_val2(int num, int upp, int len, int data);

int get_val2(int num, int upp, int len);

int hash(int num, int upp, int len);

int cell_match(Parti *cell, int num, int upp, int len);
