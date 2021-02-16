/*

============================================================================
============================================================================
============================================================================

Problem :
Coin Change | DP-7
Given a value N, if we want to make change for N cents, and we have infinite
supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make
the change? The order of coins doesn’t matter. For example, for N = 4 and S =
{1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output
should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

============================================================================
============================================================================
============================================================================

links :


https://practice.geeksforgeeks.org/problems/coin-change/0
https://www.geeksforgeeks.org/coin-change-dp-7/


============================================================================
============================================================================
============================================================================

Coin ChangeSubmissions: 36813   Accuracy: 46.07%   Difficulty: Medium   Marks: 4
Associated Course(s):   Must Do Interview Preparation


Problems
Given a value N, find the number of ways to make change for N cents, if we have
infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of
coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four
solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and
S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6},
{2,3,5} and {5,5}. So the output should be 5.

Input:
The first line contains an integer 'T' denoting the total number of test cases.
In each test cases, the first line contains an integer 'M' denoting the size of
array. The second line contains M space-separated integers A1, A2, ..., AN
denoting the elements of the array. The third line contains an integer 'N'
denoting the cents.

Output:
Print number of possible ways to make change for N cents.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 ≤ A[i] ≤ 300

Example:
Input:
2
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5

Explanation:
Testcase 1: The possiblities are as such: {1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2,
2}.



*/

#include <bits/stdc++.h>
#define printMat(x)                \
  for (int i = 0; i < m; i++) {    \
    for (int j = 0; j <= n; j++) { \
      cout << x[i][j] << " ";      \
    }                              \
    cout << endl;                  \
  }
using namespace std;
#if 0
int minimumCoinChangeProblem(vector<int> &coins, int n) {
  int m = coins.size();
  int CP[m][n + 1];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      if (coins[i] == 1 || i == 0) {
        CP[i][j] = j;
        continue;
      }
      if (j == 0) {
        CP[i][j] = 0;
        continue;
      }
      if (coins[i] > j) {
        CP[i][j] = CP[i - 1][j];
      } else {
        CP[i][j] = min(CP[i - 1][j], CP[i][j - coins[i]] + 1);
      }
    }
  }
  printMat(CP);

  return CP[m - 1][n];
}

int main() {

  int t;
  //   cin >> t;
  t = 1;
  while (t--) {
    int sz;
    cin >> sz;
    vector<int> coins;
    vector<int> coins2;
    int tmp;
    coins.push_back(0);
    coins2.push_back(1);
    for (int i = 0; i < sz; i++) {
      cin >> tmp;
      coins.push_back(tmp);
      coins2.push_back(tmp);
    }
    int n;
    cin >> n;
    int m = coins.size(); // no of coins available

    cout << "\n\n===========second MEthod ================\n\n" << endl;

    int ansss = minimumCoinChangeProblem(coins2, n);
    cout << "second method answer = " << ansss << endl;

    cout << "\n\n===========second MEthod ================\n\n" << endl;

    int CP[m][n + 1];

    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        CP[i][j] = 0;
      }
    }
    // memset(CP, 0, m * (n + 1));

    CP[0][0] = 1;

    for (int i = 1; i <= n; i++) {
      CP[0][i] = 0;
    }

    printMat(CP);

    for (int i = 1; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        if (coins[i] > j)
          CP[i][j] = CP[i - 1][j];
        else {
          CP[i][j] = CP[i - 1][j] + CP[i][j - coins[i]];
        }
      }
    }
    cout
        << "\n\n ==========================================================\n\n"
        << endl;

    printMat(CP);

    cout << "answer = " << CP[m][n] << endl;
  }

  return 0;
}

#endif

int getNumberOfWaysToMakeDesiredSum(vector<int>& coins, int N) {
  int rows = coins.size();
  sort(coins.begin(), coins.end());
  vector<vector<int>> dp(rows, vector<int>(N + 1));
  for (int i = 0; i < rows; ++i) {
    dp[i][0] = 1;
  }
  int x, y;
  for (int i = 0; i < rows; ++i) {
    for (int j = 1; j <= N; ++j) {
      x = (i >= 1) ? dp[i - 1][j] : 0;

      y = (j >= coins[i]) ? dp[i][j - coins[i]] : 0;

      dp[i][j] = x + y;
    }
  }
  return dp[rows - 1][N];
}

int getMinimumNumberofWaystoGetDesiredSum(vector<int>& coins, int N) {
  int rows = coins.size();
  sort(coins.begin(), coins.end());
  vector<vector<int>> dp(rows + 1, vector<int>(N + 1));
  int x, y;
  for (int i = 0; i <= rows; ++i) {
    dp[i][0] = 0;
  }
  for (int i = 1; i <= N; ++i) {
    dp[0][i] = i;
  }

  for (auto i : dp) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "\n\n\n\n";
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (coins[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = min(dp[i - 1][j], (1 + dp[i][j - coins[i - 1]]));
    }
  }

  //

  for (auto i : dp) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }

  return dp[rows][N];
}

int main() {
  vector<int> coins{2, 5, 3, 6};
  int N = 10;
  // finding number of ways part 1
  int res;
  //  res = getNumberOfWaysToMakeDesiredSum(coins, N);
  //  cout << "\n\nres = " << res << endl;
  res = getMinimumNumberofWaystoGetDesiredSum(coins, N);
  cout << "\n\nres = " << res << endl;

  return 0;
}
