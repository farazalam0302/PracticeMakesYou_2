/*
Longest Common SubsequenceSubmissions: 66358   Accuracy: 33.33%   Difficulty:
Medium   Marks: 4 Associated Course(s):   Must Do Interview Preparation
                  

Problems
Given two sequences, find the length of longest subsequence present in both of
them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size
of string str1 and str2 respectively The next two lines contains the 2 string
str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two
strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
*/

#include <bits/stdc++.h>
using namespace std;

class LCS {
public:
  int LCS_length_DP(string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> LCS;
    for (int i = 0; i < m + 1; i++) {
      vector<int> temp;
      for (int j = 0; j < n + 1; j++) {
        temp.push_back(0);
      }
      LCS.push_back(temp);
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          LCS[i][j] = 1 + LCS[i - 1][j - 1];
        } else {
          LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
      }
    }

    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        cout << LCS[i][j] << " ";
      }

      cout << endl;
    }
    return (LCS[m][n]);
  }
};

int main(int argc, char const *argv[]) {
  int t;

  cin >> t;
  cin.ignore();
  while (t--) {
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);

    LCS lcs;
    int answer = lcs.LCS_length_DP(s1, s2);
    cout << "LCS length = " << answer << endl;
  }

  return 0;
}
