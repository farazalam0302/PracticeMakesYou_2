#include <iostream>

#include "Matrix.h"
using namespace std;
using namespace Numeric_lib;

int main() {
  Matrix<int, 2> a(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      a[i][j] = i;
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << a[i][j] << ", ";
    }
    cout << endl;
  }

  return 0;
}
