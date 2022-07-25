// 2d arrays
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {

  int m = 4;
  int n = 4;

  int **a = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; ++i) {
    a[i] = (int *)malloc(n * sizeof(int));
  }
  /////////
  /*
   *
   * a
   * [.]->[ - - - n ]
   * [.]->[ - - - n ]
   * [.]->[ - - - n ]
   * m [.]->[ - - - n ]
   */

  // free

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = j + 1;
    }
  }
  cout << endl;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] << ", "; // = i+1;
    }
    cout << endl;
  }

  cout << endl;

  for (int i = 0; i < m; ++i) {
    free(a[i]);
  }

  free(a);

  return 0;
}
