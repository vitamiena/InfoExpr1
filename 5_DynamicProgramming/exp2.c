#include <stdio.h>
#include <string.h>

#define NUM 10
#define MAX 1000000

void make_working(int wt[][NUM], int h, int w, const char *str1, const char *str2);
int search_min(int wt[][NUM], int i, int j);
void arr_output(int arr[][NUM], int h, int w);
int edit_dist(char *str1, char *str2);
int min_of(int n1, int n2, int n3);

int main(int argc, char **argv) {
  char *str1, *str2;
  int wt[NUM][NUM];
  int h, w;

  if ( argc != 3 ) { fprintf(stderr, "Too few argument!"); return 0; }
  str1 = argv[1];
  str2 = argv[2];

  h = strlen(str1)+1;
  w = strlen(str2)+1;

  //make_working(wt, h, w, str1, str2);
  printf("%d\n", edit_dist(str1, str2));
  //arr_output(wt, h, w);

  return 0;
}

void make_working(int wt[][NUM], int h, int w, const char *str1, const char *str2) {
  int i, j;

  for ( i = 0; i < h; i++ ) {
    wt[i][0] = i;
  }
  for ( j = 0; j < w; j++ ) {
    wt[0][j] = j;
  }

  for ( i = 1; i < h; i++ ) {
    for ( j = 1; j < w; j++ ) {
      wt[i][j] = search_min(wt, i, j);
      if ( str1[i-1] == str2[j-1] && wt[i][j] == wt[i-1][j-1] ) { continue; }
      wt[i][j]++;
    }
  }
}

int search_min(int wt[][NUM], int i, int j) {
  int min = MAX;

  if ( wt[i-1][j] < min ) { min = wt[i-1][j]; }
  if ( wt[i-1][j-1] < min ) { min = wt[i-1][j-1]; }
  if ( wt[i][j-1] < min ) { min = wt[i][j-1]; }

  return min;
}

void arr_output(int arr[][NUM], int h, int w) {
  int i, j;

  for ( i = 0; i < h; i++ ) {
    for ( j = 0; j < w; j++ ) {
      printf("%2d ", arr[i][j]);
    }
    puts("");
  }
}

int edit_dist(char *str1, char *str2) {
  if ( *str1 == '\0' ) { return strlen(str2); }
  if ( *str2 == '\0' ) { return strlen(str1); }
  if ( *str1 == *str2 ) { return edit_dist(str1+1, str2+1); }
  return 1 + min_of( edit_dist(str1+1, str2), edit_dist(str1, str2+1), edit_dist(str1+1, str2+1) );
}

int min_of(int n1, int n2, int n3) {
  int min = n1;
  if ( min > n2 ) { min = n2; }
  if ( min > n3 ) { min = n3; }

  return min;
}
