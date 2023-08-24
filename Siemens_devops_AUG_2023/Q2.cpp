/*
 * https://www.geeksforgeeks.org/coin-change-dp-7/
 * Coin Change Problem
 * denomination of coins {1,2,4}
 *
 * Min. no of coins required to get N
 *
 * eg 15
 * 3 4s , 1 2s and  1 1s
 *
 */

#include <bits/stdc++.h>
using namespace std;

#if 0 // recursive Solution
int numberOfWaysToGetN(vector<int> &coins, int n, int sum) {
  if (sum == 0)
    return 1;
  if (sum < 0)
    return 0;
  if (n <= 0)
    return 0;
  return (numberOfWaysToGetN(coins, n, sum - coins[n - 1]) +
          numberOfWaysToGetN(coins, n - 1, sum));
}

int main(int argc, char **argv) {

  vector<int> coins{1, 4, 5};
  int N = 13;
  int r = numberOfWaysToGetN(coins, coins.size(), N);
  cout << "#Ways to Get " << N << " = " << r << endl;
  // cin >> N;
  // int c = N;
  // vector<int> ret(deno.size(), 0);
  // for (int i = deno.size() - 1; i >= 0; --i) {
  // ret[i] = c / deno[i];
  // c = c % deno[i];
  // }
  // cout << "[1, 4, 5]" << endl;
  // for (auto i : ret) {
  //
  // cout << i << ", ";
  // }
  //
  // cout << endl;
  //  ;
  //
  //  int c = N;
  //  int f4;
  //  int f2;
  //  int f1;
  //  f4 = c / 4;
  //  c = c % 4;
  //  f2 = c / 2;
  //  c = c % 2;
  //  f1 = c;

  //  cout << "4s = " << f4 << ", 2s = " << f2 << ", 1s  = " << f1 << endl;

  return 0;
}
#endif

#if 0 // Memoization

int numberOfWaysToGetNMemo(vector<int> &coins, int n, int sum,
                           vector<vector<int>> &dp) {
  if (sum == 0)
    return dp[n][sum] = 1;
  if (sum < 0 || n == 0) {
    return 0;
  }
  if (dp[n][sum] != -1)
    return dp[n][sum];

  return (dp[n][sum] =
              numberOfWaysToGetNMemo(coins, n, sum - coins[n - 1], dp) +
              numberOfWaysToGetNMemo(coins, n - 1, sum, dp));
}

int main(int argc, char **argv) {

  vector<int> coins{1, 4, 5};
  int N = 13;
  vector<vector<int>> dp(coins.size() + 1, vector<int>(N + 1, -1));
  int r = numberOfWaysToGetNMemo(coins, coins.size(), N, dp);
  cout << "#Ways to Get " << N << " = " << r << endl;
  return 0;
}

#endif
#if 0 // Tabulation
int numberOfWaysToGetNTabu(vector<int> &coins, int n, int sum) {
  vector<vector<int>> dp(coins.size() + 1, vector<int>(sum + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i][j] += dp[i - 1][j];
      if ((j - coins[i - 1]) >= 0) {
        dp[i][j] += dp[i][j - coins[i - 1]];
      }
    }
  }
  return (dp[n][sum]);
}

int main(int argc, char **argv) {

  vector<int> coins{1, 4, 5};
  int N = 13;
  int r = numberOfWaysToGetNTabu(coins, coins.size(), N);
  cout << "#Ways to Get " << N << " = " << r << endl;
  return 0;
}

#endif

#if 1 // Questions Asked

int MinimiumCoinsneededtoGetSum(vector<int> &coins, int n, int sum) {
  vector<int> dp(sum + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= sum; i++) {
    for (int j = 0; j < n; j++) {
      if (coins[j] <= i) {
        int subRes = dp[i - coins[j]];
        if (subRes != INT_MAX && subRes + 1 < dp[i]) {
          dp[i] = subRes + 1;
        }
      }
    }
  }
  if (dp[sum] == INT_MAX)
    return -1;
  return dp[sum];
}

int main(int argc, char **argv) {

  vector<int> coins{1, 4, 5};
  int N = 13;
  int r = MinimiumCoinsneededtoGetSum(coins, coins.size(), N);
  cout << "MinimiumCoinsneededtoGetSum =  " << r << endl;
  return 0;
}

#endif