#include <stdio.h>

#define LEN 10

void str_input(char str1[], int n1, char str2[], int n2, char str0[], int n0);

int main(void) {
  int n1, n2, n0;
  char str1[LEN], str2[LEN], str0[LEN];

  scanf("%d %d %d ", &n1, &n2, &n0);
  str_input(str1, n1, str2, n2, str0, n0);

  printf("%s %s %s", str1, str2, str0);

  return 0;
}

void str_input(char str1[], int n1, char str2[], int n2, char str0[], int n0) {
  char tmp[255];
  char *p = tmp;
  int i;

  fgets(tmp, sizeof(tmp), stdin);

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
