/*
 *
http://www.ardendertat.com/2011/09/20/programming-interview-questions-2-matrix-region-sum/


 * */

#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>>& a) {
  cout << endl;
  for (auto i : a) {
    for (auto j : i) {
      cout << j << ", ";
    }
    cout << "\n";
  }
}

void precomputeSum(vector<vector<int>>& a, vector<vector<int>>& dp) {
  int rows = a.size();
  int cols = a[0].size();
  dp[0][0] = a[0][0];
  for (int i = 1; i < rows; ++i) {
    /// rowise  first column
    dp[i][0] = dp[i - 1][0] + a[i][0];
  }
  for (int i = 1; i < cols; ++i) {
    /// rowise  first column
    dp[0][i] = dp[0][i - 1] + a[0][i];
  }
  for (int i = 1; i < rows; ++i) {
    for (int j = 1; j < cols; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
    }
  }
}

int main() {  //

  vector<vector<int>> a{{1, 1, 1, 1, 1},
                        {2, 2, 2, 2, 2},
                        {3, 3, 3, 3, 3},
                        {4, 4, 4, 4, 4},
                        {5, 5, 5, 5, 5}};
  vector<vector<int>> dp(a.size(), vector<int>(a[0].size(), 0));
  // precompute dp

  precomputeSum(a, dp);
  displayMatrix(dp);

  int i, j;
  i = 1;
  j = 1;
  int x, y;
  x = 1;
  j = 1;
  int ch = 1;
  while (ch) {
    cin >> i >> j >> x >> y;
    int sum = dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1];
    cout << "\n\n Required sum = " << sum << endl;

    cin >> ch;
  }

  return 0;
}
