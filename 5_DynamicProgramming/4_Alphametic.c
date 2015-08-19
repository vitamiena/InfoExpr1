#include <stdio.h>

#define LEN 11

void str_input(char str1[], int n1, char str2[], int n2, char str0[], int n0);
void set_strs_id(char str1[], char str2[], char str0[], int b1[], int b2[], int b0[]);
int set_str_id(char open[], int *op, char str[], int b[]);
int search_str_ind(char str[], char ch);
void number_output(int a[], int b[], int n);

int main(void) {
  int n1, n2, n0;
  char str1[LEN], str2[LEN], str0[LEN];
  int b1[LEN], b2[LEN], b0[LEN];
  int a[LEN];
  int i;

  for ( i = 0; i < LEN; i++ ) {
    a[i] = i;
  }

  scanf("%d %d %d ", &n1, &n2, &n0);
  str_input(str1, n1, str2, n2, str0, n0);

  set_strs_id(str1, str2, str0, b1, b2, b0);

  printf("%s %s %s\n", str1, str2, str0);
  number_output(a, b1, n1);
  number_output(a, b2, n2);
  number_output(a, b0, n0);

  return 0;
}

void str_input(char str1[], int n1, char str2[], int n2, char str0[], int n0) {
  char tmp[255];
  char *p = tmp;
  int i;

  fgets(tmp, sizeof(tmp), stdin);

  while ( *p == ' ' ) { p++; }
  for ( i = 0; i < n1; i++ ) {
    str1[i] = *p;
    p++;
  }
  while ( *p == ' ' ) { p++; }
  for ( i = 0; i < n2; i++ ) {
    str2[i] = *p;
    p++;
  }
  while ( *p == ' ' ) { p++; }
  for ( i = 0; i < n0; i++ ) {
    str0[i] = *p;
    p++;
  }
  str1[n1] = '\0';
  str2[n2] = '\0';
  str0[n0] = '\0';
}

void set_strs_id(char str1[], char str2[], char str0[], int b1[], int b2[], int b0[]) {
  char open[LEN] = {'\0'};
  int op = 0;

  set_str_id(open, &op, str1, b1);
  set_str_id(open, &op, str2, b2);
  set_str_id(open, &op, str0, b0);
}

int set_str_id(char open[], int *op, char str[], int b[]) {
  int p = 0;
  int t;

  while ( str[p] != '\0' ) {
    t = search_str_ind(open, str[p]);
    if ( t == -1 ) {
      open[*op] = str[p];
      b[p++] = (*op)++;
    } else {
      b[p++] = t;
    }
  }

}

int search_str_ind(char str[], char ch) {
  int p = 0;
  while ( str[p] != '\0' ) {
    if ( str[p] == ch ) { return p; }
    p++;
  }
  return -1;
}

void number_output(int a[], int b[], int n) {
  int i;

  for ( i = 0; i < n; i++ ) {
    printf("%d", a[b[i]]);
  }
  puts("");
}
