#include <stdio.h>

#define NUM 10
#define MAX 10000
#define NONE -1
#define START 0

typedef enum { false, true } Bool;

typedef struct node {
  char label;
  char label_from;
  int cost;
} Node;

int Cost[NUM][NUM];
Node Label0[NUM];
Node Queue[NUM];
int Pos = 0;

void arr_input(int arr[][NUM], int n);
void arr_output(int arr[][NUM], int n);
void arr_copy(const int arr1[][NUM], int arr2[][NUM], int n);
Bool arr_match(const int arr1[][NUM], const int arr2[][NUM], int n);
int get_cost(char str1, char str2);
void init(int n, char start);
void enqueue(Node node);
Node dequeue(void);
void relation_own(int relation[][NUM], int n);
void floyd(const int rel[][NUM], int arr0[][NUM], int n);

int main(void) {
  int table[NUM][NUM];
  int n;
  char start, end;

  scanf("%d", &n);
  arr_input(Cost, n);
  scanf("%c %c", &start, &end);

  arr_output(Cost, n);

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

int get_cost(char str1, char str2) {
  return Cost[str1-'A'][str2-'A'];
}

void init(int n, char start) {
  int i;

  for ( i = 0; i < n; i++ ) {
    Label0[i].label = 'A'+1;
    if ( Label0[i].label == start ) {
      Label0[i].cost = 0;
      Label0[i].label_from = START;
      enqueue(Label0[i]);
    } else {
      Label0[i].cost = MAX;
      Label0[i].label_from = NONE;
    }
  }
}

void enqueue(Node node) {
  Queue[Pos++] = node;
}

Node dequeue(void) {
  return Queue[--Pos];
}


void dijkstra(char start) {
  Node node;
  int min;

  do {
    min = MAX;
    node.cost = MAX;

  } while ( node.cost != MAX )
}
