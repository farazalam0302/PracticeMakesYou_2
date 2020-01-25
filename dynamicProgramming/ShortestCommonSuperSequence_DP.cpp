/*
Shortest Common SupersequenceSubmissions: 13882   Accuracy: 49.64%   Difficulty:
Easy   Marks: 2 Associated Course(s):   Must Do Interview Preparation   DSA-Self
Paced with Doubt Assistance More

Problems
Given two strings str1 and str2, find the length of the smallest string which
has both, str1 and str2 as its sub-sequences. Note: str1 and str2 can have both
uppercase and lowercase letters.

Input:
The first line of input contains an integer T denoting the number of test
cases.Each test case contains two space separated strings.

Output:
For each testcase, in a new line, output the length of the required string.

Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6

*/
#include <bits/stdc++.h>
using namespace std;
class ShortestCommonSuperSequence_DP {
public:
  int shortestCommonSuperSequence_DP(string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> lcsDP(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          lcsDP[i][j] = lcsDP[i - 1][j - 1] + 1;
        } else {
          lcsDP[i][j] = max(lcsDP[i - 1][j], lcsDP[i][j - 1]);
        }
      }
    }
#if 0
    s1 = "$" + s1;
    s2 = "\\$" + s2;
    cout << "\n===========================\n";

    for (int j = 0; j <= n + 1; j++) {
      cout << s2[j] << " ";
    }
    cout << "\n";

    for (int i = 0; i <= m; i++) {
      cout << s1[i] << " ";
      for (int j = 0; j <= n; j++) {
        cout << lcsDP[i][j] << " ";
      }
      cout << endl;
    }
    cout << "\n===========================\n";
#endif
    int scs = m + n - lcsDP[m][n];
    return scs;
  }
};

int main() {
  string s1, s2;
  cin >> s1;
  cin.ignore();
  cin >> s2;
  ShortestCommonSuperSequence_DP scs;
  int answer = scs.shortestCommonSuperSequence_DP(s1, s2);
  cout << "answer = " << answer << endl;

  return 0;
}