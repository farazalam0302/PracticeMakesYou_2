#include "Adder/adder.h"
#include <bits/stdc++.h>
using namespace std;

void matMul(int a[3][2], int b[2][3], int m, int n, int p, int q) {
  if (n != p)
    return;
  int c[3][3] = {0};

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < q; ++j) {
      c[i][j] = 0;
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < q; ++j) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < q; ++j) {
      for (int k = 0; k < p; ++k) {
        c[i][j] = c[i][j] + a[i][k] * b[k][j];
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < q; ++j) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
}

int MySum(int a, int b) { return (a + b); }
int main() { //
             // clang-format off
	int a[3][2] = {{1,2},
			       {4,5},
				   {8,7} };

	int b[2][3] = {{1,2,3 },
		           {4,5,6 } };
             // clang-format on

  matMul(a, b, 3, 2, 2, 3);

  cout << "\n\nADD = " << (add(10, 25)) << endl;

  return 0;
}
