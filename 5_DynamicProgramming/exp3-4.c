#include <stdio.h>
#include <time.h>

#define NUM 10
#define MAX 10000
#define NONE -1
#define START 0
#define OPEN 1
#define CLOSE 2

typedef enum { false, true } Bool;

typedef struct node {
  char label;
  char label_from;
  int cost;
  Bool open;
} Node;

int Cost[NUM][NUM];
Node Label0[NUM];

void arr_input(int arr[][NUM], int n);
void arr_output(int arr[][NUM], int n);
void arr_copy(const int arr1[][NUM], int arr2[][NUM], int n);
Bool arr_match(const int arr1[][NUM], const int arr2[][NUM], int n);
int get_cost(char str1, char str2);
void init(int n, char start);
void dijkstra(char start, int n, char end);
Bool exist_open(int n);
int get_index(char ch);
void show_path(Node node, char start);

int main(void) {
  int n;
  char start, end;
  int i;
  int time;
  clock_t s, e;

  scanf("%d", &n);
  arr_input(Cost, n);
  //scanf(" %c %c", &start, &end);
  start = 'A';


  for ( i = 0; i < n; i++ ) {
    time = 1000000;
    end = 'A' + i;
    s = clock();
    while ( time-- ) {
      dijkstra(start, i+1, end);
    }
    e = clock();
    printf("%d : %f\n", i+1, (0.0+e-s)/CLOCKS_PER_SEC);
  }

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
    Label0[i].label = 'A'+i;
    if ( Label0[i].label == start ) {
      Label0[i].cost = 0;
      Label0[i].label_from = START;
      Label0[i].open = OPEN;
    } else {
      Label0[i].cost = MAX;
      Label0[i].label_from = NONE;
      Label0[i].open = NONE;
    }
  }
}

void dijkstra(char start, int n, char end) {
  Node *node;
  int ind;
  int min, min_pos;
  int i;
  int t;
  char ch = start;

  init(n, start);

  ind = get_index(ch);
  node = &(Label0[ind]);
  node->open = OPEN;

  while ( 1 ) {
    min = MAX;
    min_pos = -1;
    if ( exist_open(n) == false ) { /*puts("Failed");*/ return; }

    ind = min_open(n);
    node = &Label0[ind];
    node->open = CLOSE;

    if ( node->label == end ) { /*show_path(*node, start);*/ return ; }

    for ( i = 0; i < n; i++ ) {
      if ( Cost[ind][i] != 0 ) {
        if ( Label0[i].open == NONE ) {
          Label0[i].open = OPEN;
          Label0[i].cost = node->cost + Cost[ind][i];
          Label0[i].label_from = node->label;
        } else {
          t = node->cost + Cost[ind][i];
          if ( t < Label0[i].cost ) {
            Label0[i].cost = t;
            Label0[i].label_from = node->label;
          }
        }
        if ( min > Label0[i].cost ) {
          min = Label0[i].cost;
          min_pos = i;
        }
      }
    }
  }
}

Bool exist_open(int n) {
  int i;

  for ( i = 0; i < n; i++ ) {
    if ( Label0[i].open == OPEN ) { return true; }
  }

  return false;
}

int get_index(char ch) {
  return ch - 'A';
}

int min_open(int n) {
  int i;
  int min = MAX, min_pos = -1;

  for ( i = 0; i < n; i++ ) {
    if ( Label0[i].open != OPEN ) { continue; }
    if ( Label0[i].cost < min ) { min = Label0[i].cost; min_pos = i; }
  }

  return min_pos;
}

void show_path(Node node, char start) {
  int ind;

  if ( node.label == start ) { printf("%c ", node.label); return; }
  ind = get_index(node.label_from);
  show_path(Label0[ind], start);
  printf("- %c ", node.label);
}
