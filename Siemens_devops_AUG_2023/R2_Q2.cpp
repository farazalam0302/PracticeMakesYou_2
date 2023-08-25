/*
[6:06 PM] Palaparthi, Srikrishna (DI SW IES DMA QPE DOPS)

Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

[6:07 PM] Palaparthi, Srikrishna (DI SW IES DMA QPE DOPS)

Input : X = “zxabcdezy”, y = “yzabcdezx”
Output : 6
Explanation:
The longest common substring is “abcdez” and is of length 6.

LCS of s1 and s2
eg

    $    y
  $
  x[


 ]


*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

  string x = "zxabcdezy";
  string y = "yzabcdezx";
  x = "$" + x;
  y = "$" + y;

  vector<vector<int>> dp(x.size() + 1, vector<int>(y.size() + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= x.size(); i++) {
    for (size_t j = 1; j <= y.size(); j++) {
      if (x[i] == y[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else {
        dp[i][j] = 0; // max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
      }
    }

    /* code */
  }
  cout << endl;
  for (auto &i : dp) {
    for (auto &j : i) {
      cout << j << ", ";
    }
    cout << endl;
  }

  cout << " Longest Length  =" << dp[x.size()][y.size()];

  return 0;
}
