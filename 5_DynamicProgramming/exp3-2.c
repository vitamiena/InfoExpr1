#include <stdio.h>
#include <time.h>

#define NUM 11

typedef enum { false, true } Bool;

void arr_input(int arr[][NUM], int n);
void arr_output(int arr[][NUM], int n);
void arr_copy(const int arr1[][NUM], int arr2[][NUM], int n);
Bool arr_match(const int arr1[][NUM], const int arr2[][NUM], int n);
void arr_logical_multi(int arr0[][NUM], const int arr1[][NUM], const int arr2[][NUM], int n);
void relation_own(int relation[][NUM], int n);
void warshall(const int rel[][NUM], int arr0[][NUM], int n);

int main(void) {
  int relation[NUM][NUM] = {{0}};
  int table[NUM][NUM];
  int n;
  int i, j, k;
  int time;
  clock_t start, end;

  scanf("%d", &n);
  arr_input(relation, n);

  relation_own(relation, n);


  for ( i = 0; i < n; i++ ) {
    /* for ( k = 0; k < NUM; k++ ) { */
    /*   for ( j = 0; j < NUM; j++ ) { */
    /*     table[k][j] = 0; */
    /*   } */
    /* } */

    time = 100000;
    start = clock();
    while (time--) {
      warshall(relation, table, i+1);
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

void arr_logical_multi(int arr0[][NUM], const int arr1[][NUM], const int arr2[][NUM], int n) {
  int i, j, k;

  for (i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) {
      arr0[i][j] = 0;
    }
  }

  for (i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) {
      for ( k = 0; k < n; k++ ) {
        arr0[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }

  for (i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) {
      if ( arr0[i][j] != 0 ) {
        arr0[i][j] = 1;
      }
    }
  }

}

void relation_own(int relation[][NUM], int n) {
  int i;

  for ( i = 0; i < n; i++ ) {
    relation[i][i] = 1;
  }
}

void warshall(const int rel[][NUM], int arr0[][NUM], int n) {
  int arr1[NUM][NUM];
  arr_copy(rel, arr0, n);
  arr_copy(rel, arr1, n);

  while ( 1 ) {
    arr_copy(arr0, arr1, n);
    arr_logical_multi(arr0, arr1, rel, n);
    if ( arr_match(arr0, arr1, n) == true ) { break; }
  }
}
