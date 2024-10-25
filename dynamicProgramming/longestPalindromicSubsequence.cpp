/*

https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/



Given a string ‘S’, find the length of the Longest Palindromic Subsequence in
it. The Longest Palindromic Subsequence (LPS) is the problem of finding a
maximum-length subsequence of a given string that is also a Palindrome.

LPS
Longest Palindromic Subsequence

Examples:

Input: S = “GEEKSFORGEEKS”
Output: 5
Explanation: The longest palindromic subsequence we can get is of length 5.
There are more than 1 palindromic subsequences of length 5, for example: EEKEE,
EESEE, EEFEE, …etc.


Input: S = “BBABCBCAB”
Output: 7
Explanation: As “BABCBAB” is the longest palindromic subsequence in it. “BBBBB”
and “BBCBB” are also palindromic subsequences of the given sequence, but not the
longest ones.




*/

#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &a) {
  cout << endl;
  for (auto &i : a) {
    for (auto &j : i) {
      cout << j << ", ";
    }
    cout << endl;
  }
}

int recursiveLPS(string &s, int low, int high) {
  if (low == high)
    return 1;
  if (high == low + 1 && s[low] == s[high])
    return 2;
  if (s[low] == s[high])
    return recursiveLPS(s, low + 1, high - 1) + 2;
  return max(recursiveLPS(s, low + 1, high), recursiveLPS(s, low, high - 1));
}

int memoizationLPS(string &s, vector<vector<int>> &memo, int low, int high) {
  if (low == high)
    return 1;
  if (high == low + 1 && s[low] == s[high])
    return 2;
  if (memo[low][high] != -1)
    return memo[low][high];
  if (s[low] == s[high])
    return memo[low][high] = memoizationLPS(s, memo, low + 1, high - 1) + 2;
  return memo[low][high] = max(memoizationLPS(s, memo, low + 1, high),
                               memoizationLPS(s, memo, low, high - 1));
}

int bottomUpLPS(string &s) {
  int n = s.size();
  vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] == s[j]) {
        dp[i][j] = dp[i + 1][j - 1] + 2;
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
  }
#ifdef DEBUG
  printMatrix(dp);
#endif
  return dp[0][n - 1];
}

int LCS(string &s, string &r) {
  int m = s.size();
  int n = r.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (size_t i = 1; i <= m; i++) {
    for (size_t j = 1; j <= n; j++) {
      if (s[i - 1] == r[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  return dp[m][n];
}

int LPSusingLCS(string &s) {
  string r = s;
  reverse(r.begin(), r.end());
  int n = s.size();
  return (LCS(s, r));
}

int main(int argc, char const *argv[]) {
  /* code */
  string s = "GEEKSFORGEEKS";
  // clang-format off
//   cout << "\n Recursive LPS Answer = " << recursiveLPS(s, 0, s.size() - 1) << endl;
  vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
  cout << "\n Memoization DP_LPS Answer = "<< memoizationLPS(s, memo, 0, s.size() - 1) << endl;
  cout << "\n BottomUP DP_LPS Answer = "<< bottomUpLPS(s) << endl;
  cout << "\n BottomUP DP_LPSUsingLCS Answer = "<< LPSusingLCS(s) << endl;
  // clang-format on

  return 0;
}
