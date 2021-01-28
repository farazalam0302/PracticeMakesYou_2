/*
 * http://www.ardendertat.com/2011/10/10/programming-interview-questions-6-combine-two-strings/
 *
 *
 * We are given 3 strings: str1, str2, and str3. Str3 is said to be a shuffle of
 * str1 and str2 if it can be formed by interleaving the characters of str1 and
 * str2 in a way that maintains the left to right ordering of the characters
 * from each string. For example, given str1=”abc” and str2=”def”, str3=”dabecf”
 * is a valid shuffle since it preserves the character ordering of the two
 * strings. So, given these 3 strings write a function that detects whether str3
 * is a valid shuffle of str1 and str2.
 */

#include <bits/stdc++.h>
using namespace std;

bool isShuffle(string s1, string s2, string s3) {
  int len1 = s1.length();
  int len2 = s2.length();
  int len3 = s3.length();
  if ((len1 + len2) != len3) {
    return false;
  }
  if (len1 == 0 || len2 == 0 || len3 == 0) {
    string tmp = s1 + s2;
    if (tmp.compare(s3) == 0)
      return true;
    else
      return false;
  }

  bool x = false, y = false;

  if (s1[0] != s3[0] && s2[0] != s3[0]) {
    return false;
  }
  if (s1[0] == s3[0] && isShuffle(s1.substr(1), s2, s3.substr(1))) {
    //    x = true;
    return true;
  }
  if (s2[0] == s3[0] && isShuffle(s1, s2.substr(1), s3.substr(1))) {
    //    y = true;
    return true;
  }

  return false;  //|| x || y;
}

bool isShuffleInterleaved_dp(string s1, string s2, string s3, auto& dp) {
  if (!(s1.length() || s2.length() || s3.length())) {
    return true;
  }
  if (!(s3.length())) return false;

  string key = (s1 + "|" + s2 + "|" + s3);  // memoization
  if (dp.find(key) == dp.end()) {
    bool x = (s1.length() && s3[0] == s1[0]) &&
             isShuffleInterleaved_dp(s1.substr(1), s2, s3.substr(1), dp);

    bool y = (s2.length() && s3[0] == s2[0]) &&
             isShuffleInterleaved_dp(s1, s2.substr(1), s3.substr(1), dp);

    dp[key] = x || y;
  } else
    return dp[key];
}

bool isShuffleInterleaved_dp_bottomUp(string s1, string s2, string s3) {
  int L1 = s1.length();
  int L2 = s2.length();
  int L3 = s3.length();
  if (!(L1 || L2 || L3)) return true;
  if ((L1 + L2) != L3) return false;

  //	bool T[L1+1][L2+1] ;
  vector<vector<bool>> T(L1 + 1, vector<bool>(L2 + 1, false));

  for (int i = 0; i <= L1; ++i) {
    for (int j = 0; j <= L2; ++j) {
      if (i == 0 && j == 0) {
        T[i][j] = true;
      } else if (i && j && s1[i - 1] == s3[i + j - 1] &&
                 s2[j - 1] == s3[i + j - 1]) {
        T[i][j] = T[i - 1][j] || T[i][j - 1];
      } else if (i && s1[i - 1] == s3[i + j - 1]) {
        T[i][j] = T[i - 1][j];
      } else if (j && s2[j - 1] == s3[i + j - 1]) {
        T[i][j] = T[i][j - 1];
      }
    }
  }
  return T[L1][L2];
}

int main() {
  string s1, s2, s3;
  s1 = "abc";
  s2 = "acd";
  s3 = "acdbac";

  unordered_map<string, bool> dp;

  isShuffleInterleaved_dp_bottomUp(s1, s2, s3) ? cout << "\n\nYes it is\n\n"
                                               : cout << "\n\n NOooo!!!\n\n";

  //  isShuffleInterleaved_dp(s1, s2, s3, dp) ? cout << "\n\nYes it is\n\n"
  //                                          : cout << "\n\n NOooo!!!\n\n";

  //  isShuffle(s1, s2, s3) ? cout << "\n\nYes it is\n\n"
  //                        : cout << "\n\n NOooo!!!\n\n";

  //
  return 0;
}
