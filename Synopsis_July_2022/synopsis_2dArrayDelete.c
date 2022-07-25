#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {

  int m = 4;
  int n = 4;
  ////////////////////////////////////////////////////////////
  int **a = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; ++i) {
    a[i] = (int *)malloc(n * sizeof(int));
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = j + 1;
    }
  }
  printf("\n");
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d, ", a[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  for (int i = 0; i < m; ++i) {
    free(a[i]);
  }

  free(a);

  ////////////////////////////////////////////////////////////

  // Method 2

  int *b = (int *)malloc(m * n * sizeof(int));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i * n + j] = j + 1;
    }
  }
  printf("b = \n");
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d, ", b[i * n + j]); // = j + 1;
    }
    printf("\n");
  }

  free(b);

  ////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////
  // Method 3

  int *c[m];
  for (int i = 0; i < m; ++i) {
    c[i] = (int *)malloc(n * sizeof(int));
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      c[i][j] = j + 1;
    }
  }

  printf("c = \n");
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d, ", c[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  ////////////////////////////////////////////////////////////

  return 0;
}
