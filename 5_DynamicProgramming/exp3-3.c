#include <stdio.h>
#include <time.h>

#define NUM 10
#define MAX 10000

typedef enum { false, true } Bool;

void arr_input(int arr[][NUM], int n);
void arr_output(int arr[][NUM], int n);
void arr_copy(const int arr1[][NUM], int arr2[][NUM], int n);
Bool arr_match(const int arr1[][NUM], const int arr2[][NUM], int n);
void relation_own(int relation[][NUM], int n);
void floyd(const int rel[][NUM], int arr0[][NUM], int n);

int main(void) {
  int relation[NUM][NUM] = {{0}};
  int table[NUM][NUM];
  int n;
  int i;
  clock_t start, end;
  int time;

  scanf("%d", &n);
  arr_input(relation, n);

  relation_own(relation, n);

  for ( i = 0; i < n; i++ ) {
    time = 1000000;
    start = clock();
    while ( time-- ) {
      floyd(relation, table, i+1);
    }
    end = clock();
    printf("%d : %f\n", i+1, (0.0+end-start)/CLOCKS_PER_SEC);
  }

  arr_output(table, n);

  return 0;
}

void arr_input(int arr[][NUM], int n) {
  int i, j;

  for ( i = 0; i < n; i++ ) {
    for ( j = 0; j < n; j++ ) {
      scanf("%d", &arr[i][j]);
    }
  }
}

Bool arr_match(const int arr1[][NUM], const int arr2[][NUM], int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) {
      if ( arr1[i][j] != arr2[i][j] ) {
        return false;
      }
    }
  }

  return true;
}

void arr_copy(const int arr1[][NUM], int arr2[][NUM], int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) {
      arr2[i][j] = arr1[i][j];
    }
  }
}

void arr_output(int arr[][NUM], int n) {
  int i, j;

  for ( i = 0; i < n; i++ ) {
    for ( j = 0; j < n; j++ ) {
      printf("%d ", arr[i][j]);
    }
    puts("");
  }
  puts("");
}

void relation_own(int relation[][NUM], int n) {
  int i;

  for ( i = 0; i < n; i++ ) {
    relation[i][i] = 1;
  }
}

void floyd(const int rel[][NUM], int arr0[][NUM], int n) {
  int arr1[NUM][NUM];
  int i, j, k;
  int tmp;

  for ( i = 0; i < n; i++ ) {
    for ( j = 0; j < n; j++ ) {
      arr0[i][j] = rel[i][j] == 0 ? MAX : rel[i][j];
    }
  }

  for ( i = 0; i < n; i++ ) {
    for ( j = 0; j < n; j++ ) {
      for ( k = 0; k < n; k++ ) {
        tmp = arr0[i][k] + arr0[k][j];
        if ( arr0[i][j] > tmp ) { arr0[i][j] = tmp; }
      }
    }
  }

  for ( i = 0; i < n; i++ ) {
    for ( j = 0; j < n; j++ ) {
      arr0[i][j] = arr0[i][j] == MAX ? 0 : arr0[i][j];
    }
  }
}
