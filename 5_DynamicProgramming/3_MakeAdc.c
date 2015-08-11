#include <stdio.h>
#include <stdlib.h>

#define NUM 10
#define LEN 255

void set_label(char label[]);
void set_relation(int relation[][NUM], char input[]);
void graph_output(int relation[][NUM], char label[], int n);

int main(void) {
  char tmp[LEN];
  int relation[NUM][NUM] = {{0}};
  char label[NUM];
  int n;
  int i;

  fgets(tmp, sizeof(tmp), stdin);
  sscanf(tmp, "%d", &n);
  set_label(label);

  for ( i = 0; i < n; i++ ) {
    if ( fgets(tmp, sizeof(tmp), stdin) == NULL ) { puts("Input Error"); return 0; }
    set_relation(relation, tmp);
  }
  graph_output(relation, label, n);

  return 0;
}

void set_label(char label[]) {
  int i;

  for ( i = 0; i < NUM; i++ ) {
    label[i] = 'A' + i;
  }
}

void set_relation(int relation[][NUM], char input[]) {
  int p = 0;
  int label;

  while ( input[p] == ' ' ) { p++; }
  if ( input[p] >= 'A' && input[p] < 'A'+NUM ) { label = input[p++] - 'A'; }

  while ( input[p] != '\0' ) {
    while ( input[p] == ' ' ) { p++; }
    if ( input[p] >= 'A' && input[p] < 'A'+NUM ) { relation[label][input[p++]-'A'] = 1; }
    while ( input[p] == ' ' ) { p++; }
    if ( input[p] == '\n' ) { break; }
  }
}

void graph_output(int relation[][NUM], char label[], int n) {
  int i;
  int j;

  printf("  ");
  for ( i = 0; i < n; i++ ) {
    printf("%c ", label[i]);
  }
  puts("");

  for ( i = 0; i < n; i++ ) {
    printf("%c ", label[i]);
    for ( j = 0; j < n; j++ ) {
      printf("%d ", relation[i][j]);
    }
    puts("");
  }
}
