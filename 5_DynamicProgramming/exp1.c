#include <stdio.h>
#include <time.h>

#define NUM 10

void arr_input(int arr[][NUM], int h, int l); // Input
void make_work(int wt[][NUM], int arr[][NUM], int h, int l);  // Making Working Table
int set_val(int wt[][NUM], int i, int j, int h); // Search max route and return max value
void show_max_route(int wt[][NUM], int arr[][NUM], int h, int l);
void show_max_route_(int arr[][NUM], int i, int j, int h);
void arr_output(int arr[][NUM], int h, int l); // Output

int main(void) {
  int arr[NUM][NUM]; // Input Bord
  int wt[NUM][NUM];  // Working Table
  int h, l;          // Bord Size Hight and Length
  int time;
  clock_t start, end;
  int i;

  h = l = NUM;
  arr_input(arr, h, l);
  arr_output(arr, h, l);

  for ( i = 0; i < NUM; i++ ) {
    time = 10000000;
    start = clock();
    while ( time-- ) {
      make_work(wt, arr, i+1, i+1);
    }
    end = clock();

    printf("%d : %f\n", i+1, (end-start+0.0)/CLOCKS_PER_SEC);
  }

  show_max_route(wt, arr, h, l);
  arr_output(wt, h, l);

  return 0;
}

void arr_input(int arr[][NUM], int h, int l) {
  int i, j;

  for ( i = 0; i < h; i++ ) {
    for ( j = 0; j < l; j++ ) {
      scanf("%d ", &arr[i][j]);
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

  if ( i > 0 && wt[i-1][j-1] > max ) { max = wt[i-1][j-1]; }
  if ( wt[i][j-1] > max ) { max = wt[i][j-1]; }
  if ( i < h-1 && wt[i+1][j-1] > max ) { max = wt[i+1][j-1]; }

  return max;
}

void show_max_route(int wt[][NUM], int arr[][NUM], int h, int l) {
  int i;
  int mh = -1;
  int max = -1;

  for ( i = 0; i < h; i++ ) {
    if ( wt[i][l-1] > max ) {
      mh = i;
      max = wt[i][l-1];
    }
  }

  show_max_route_(wt, mh, l-1, h);
  printf(": %2d\n", max);
}

void show_max_route_(int arr[][NUM], int i, int j, int h) {
  int max = -1, mh = 1;

  if ( j > 0 ) {
    if ( i > 0 && arr[i-1][j-1] > max  ) { mh = i-1; max = arr[i-1][j-1];}
    if ( arr[i][j-1] > max  ) { mh = i; max = arr[i][j-1]; }
    if ( i < h-1 && arr[i+1][j-1] > max  ) { mh = i+1; max = arr[i+1][j-1];}
    show_max_route_(arr, mh, j-1, h);
  }

  printf("%2d ", i);
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
