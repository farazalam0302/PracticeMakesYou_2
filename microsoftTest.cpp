// 1   2  3  5
// 4   6  8 10
// 14 15 16 17
// 20 30 40 50
//
// 6=?

#include <bits/stdc++.h>
using namespace std;

pair<int, int> bSearch(vector<vector<int>> &a, int key) {
  int m = a.size();
  int n = a[0].size();
  int row = 0;
  int col = n - 1;
  //  vector<int> r;
  while (row < m && col >= 0) {
    if (key == a[row][col]) {
      return {row, col};
    } else if (key < a[row][col])
      col--;
    else if (key > a[row][col])
      row++;
  }

  return {-1, -1};
}

int main() {  //

  vector<vector<int>> a{
      {1, 2, 3, 5}, {4, 6, 8, 10}, {14, 15, 16, 17}, {20, 30, 40, 50}};

  pair<int, int> result = bSearch(a, 4);

  cout << result.first << ", " << result.second << endl;

  return 0;
}
