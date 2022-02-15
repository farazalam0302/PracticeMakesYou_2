/*
 *
 *
 * https://www.geeksforgeeks.org/longest-common-substring-dp-29/
 *
 * Longest Common Substring | DP-29
Difficulty Level : Medium
 Last Updated : 19 Jan, 2021
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

Examples :

Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
Output : 5
Explanation:
The longest common substring is “Geeks” and is of length 5.

Input : X = “abcdxyz”, y = “xyzabcd”
Output : 4
Explanation:
The longest common substring is “abcd” and is of length 4.

Input : X = “zxabcdezy”, y = “yzabcdezx”
Output : 6
Explanation:
The longest common substring is “abcdez” and is of length 6.


 *
 */
#include <bits/stdc++.h>
using namespace std;

int LCSubstr(char* x, char* y, int m, int n, int lcscount) {
  if (m <= 0 || n <= 0) return lcscount;
  int lcscount1 = INT_MIN, lcscount2 = INT_MIN, lcscount3 = INT_MIN;
  if (x[m - 1] == y[n - 1])
    lcscount1 = LCSubstr(x, y, m - 1, n - 1, lcscount + 1);
  lcscount2 = LCSubstr(x, y, m - 1, n, lcscount);
  lcscount3 = LCSubstr(x, y, m, n - 1, lcscount);
  return max(lcscount1, max(lcscount2, lcscount3));
}

void displayDP(vector<vector<int>>& container) {
  cout << "\n\n" << endl;
  for (auto i : container) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
  cout << "\n\n" << endl;
}

struct maxIndices {
  int x;
  int y;
  int l;
};

int LCSubstrDP(char* x, char* y, int m, int n) {
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  /*
   * first row and column must be 0s and here whole dp is 0s
   */
  maxIndices mi{0, 0, 0};
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (x[i - 1] == y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (mi.l < dp[i][j]) {
          mi.x = i;
          mi.y = j;
          mi.l = dp[i][j];
        }
      } else
        dp[i][j] = 0;
    }
  }

  displayDP(dp);

  cout << "\n(" << mi.x << ", " << mi.y << ")\n" << endl;

  stack<char> st;
  int i = mi.x - 1;
  int l = mi.l;
  while (l) {
    st.push(x[i]);
    i--;
    l--;
  }

  cout << "\n\nLCSS =  ";
  while (!st.empty()) {
    cout << st.top();
    st.pop();
  }

  return mi.l;
}
int main() {
  char x[] = "abcdxyz";
  char y[] = "xyzabcd";
  int m = strlen(x);
  int n = strlen(y);
  int result;
  int lcscount = 0;
  //  result = LCSubstr(x, y, m, n, lcscount);
  result = LCSubstrDP(x, y, m, n);
  cout << "\n\n\n\nresult = \n\n\n" << result << endl;

  return 0;
}
