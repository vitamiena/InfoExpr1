#include <stdio.h>

#define NUM 10
#define MAX 10000000

void arr_input(int arr[][NUM], int h, int l); // Input
void make_work(int wt[][NUM], int arr[][NUM], int h, int l);  // Making Working Table
int set_val(int wt[][NUM], int i, int j, int h); // Search max route and return max value
void arr_output(int arr[][NUM], int h, int l); // Output

int main(void) {
  int arr[NUM][NUM]; // Input Bord
  int wt[NUM][NUM];  // Working Table
  int h, l;          // Bord Size Hight and Length

  scanf("%d %d", &h, &l);
  arr_input(arr, h, l);

  make_work(wt, arr, h, l);

  arr_output(wt, h, l);

  return 0;
}

void arr_input(int arr[][NUM], int h, int l) {
  int i, j;

  for ( i = 0; i < h; i++ ) {
    for ( j = 0; j < l; j++ ) {
      scanf("%d", &arr[i][j]);
    }
  }
}

void make_work(int wt[][NUM], int arr[][NUM], int h, int l) {
  int i, j;

  for ( j = 0; j < l; j++ ) {
    for ( i = 0; i < h; i++ ) {
      wt[i][j] = arr[i][j] + set_val(wt, i, j, h);
    }
  }
}

int set_val(int wt[][NUM], int i, int j, int h) {
  int max = -1;

  if ( j == 0 ) { return 0; }

  if ( i != 0 && wt[i-1][j-1] > max ) { max = wt[i-1][j-1]; }
  if ( wt[i][j-1] > max ) { max = wt[i][j-1]; }
  if ( i < h-1 && wt[i+1][j-1] > max ) { max = wt[i+1][j-1]; }

  return max;
}

void arr_output(int arr[][NUM], int h, int l) {
  int i, j;

  for ( i = 0; i < h; i++ ) {
    for ( j = 0; j < l; j++ ) {
      printf("%2d ", arr[i][j]);
    }
    puts("");
  }
}
