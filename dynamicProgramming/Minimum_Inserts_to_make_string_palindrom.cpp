/*

Given string str, the task is to find the minimum number of characters to be
inserted to convert it to a palindrome.

Before we go further, let us understand with a few examples:

ab: Number of insertions required is 1 i.e. bab
aa: Number of insertions required is 0 i.e. aa
abcd: Number of insertions required is 3 i.e. dcbabcd
abcda: Number of insertions required is 2 i.e. adcbcda which is the same as the
number of insertions in the substring bcd(Why?). abcde: Number of insertions
required is 4 i.e. edcbabcde Let the input string be str[l……h]. The problem can
be broken down into three parts:

Find the minimum number of insertions in the substring str[l+1,…….h].
Find the minimum number of insertions in the substring str[l…….h-1].
Find the minimum number of insertions in the substring str[l+1……h-1].

*/

#include <bits/stdc++.h>
using namespace std;

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

int findMinInsertsToMakePalindrome(string &s) {
  string r = s;
  reverse(r.begin(), r.end());

  return (s.size() - LCS(s, r));
}

int main(int argc, char const *argv[]) {

  string s = "abcde";
  cout << "Min. Inserts to make " << s
       << " a palindrome  = " << findMinInsertsToMakePalindrome(s) << endl;

  return 0;
}
