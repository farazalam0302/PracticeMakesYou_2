#include <bits/stdc++.h>
using namespace std;

void printSpiral(vector<vector<int>>& a) {
  int m = a.size();
  int n = a[0].size();
  int start_row = 0;
  int start_col = 0;
  int end_row = m - 1;
  int end_col = n - 1;
  while (start_row <= end_row && start_col <= end_col) {
    for (int i = start_col; i <= end_col; ++i) {
      cout << a[start_row][i] << " ";
    }
    start_row++;
    for (int i = start_row; i <= end_row; ++i) {
      cout << a[i][end_col] << " ";
    }
    end_col--;

    if (start_col <= end_col) {
      for (int i = end_col; i >= start_col; --i) {
        cout << a[end_row][i] << " ";
      }
      end_row--;
    }
    if (start_row <= end_row) {
      for (int i = end_row; i >= start_row; --i) {
        cout << a[i][start_col] << " ";
      }
      start_col++;
    }
  }
}

int main() {
  vector<vector<int>> a{{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}

  };
  vector<int> b{1,  2,  3, 4, 5, 10, 15, 20, 25, 24, 23, 22, 21,
                16, 11, 6, 7, 8, 9,  14, 19, 18, 17, 12, 13};
  printSpiral(a);

  cout << "\n\nCheck \n\n";
  for (auto i : b) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
