/*
 * link
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
 *
 * Given a string S, find the longest palindromic substring in S. Substring of
string S: S[ i . . . . j ] where 0 ? i ? j < len(S). Palindrome string: A string
which reads the same backwards. More formally, S is palindrome if reverse(S) =
S. Incase of conflict, return the substring which occurs first ( with the least
starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines
consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the
respective test case.

Constraints:
1 ? T ? 100
1 ? Str Length ? 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa

Explanation:
Testcase 1: The longest palindrome string present in the given string is
"aabbaa".

** For More Input/Output Examples Use 'Expected Output' option **
 */
#if 0
// A C++ solution for longest palindrome
#include <bits/stdc++.h>
using namespace std;

// Function to print a substring str[low..high]
void printSubStr(string str, int low, int high) {
  for (int i = low; i <= high; ++i) cout << str[i];
}

// This function prints the
// longest palindrome substring
// It also returns the length
// of the longest palindrome
int longestPalSubstr(string str) {
  // get length of input string
  int n = str.size();

  // All substrings of length 1
  // are palindromes
  int maxLength = 1, start = 0;

  // Nested loop to mark start and end index
  for (int i = 0; i < str.length(); i++) {
    for (int j = i; j < str.length(); j++) {
      int flag = 1;

      // Check palindrome
      for (int k = 0; k < (j - i + 1) / 2; k++)
        if (str[i + k] != str[j - k]) flag = 0;

      // Palindrome
      if (flag && (j - i + 1) > maxLength) {
        start = i;
        maxLength = j - i + 1;
      }
    }
  }

  cout << "\n\nLongest palindrome substring is: ";
  printSubStr(str, start, start + maxLength - 1);

  // return length of LPS
  return maxLength;
}

// Driver Code
int main() {
  string str = "abcaabbaaabc";
  longestPalSubstr(str);
  return 0;
}

#endif
#if 1

#include <bits/stdc++.h>
using namespace std;
string bruteForceLCSubstring(string s) {
  int len = s.length();
  int flag;
  int maxlength = 1;
  int start = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i; j < len; ++j) {
      flag = 1;
      for (int k = 0; k < (j - i + 1) / 2; ++k) {
        if (s[i + k] != s[j - k]) {
          flag = 0;
        }
      }
      if (flag && (j - i + 1) > maxlength) {
        start = i;
        maxlength = j - i + 1;
      }
    }
  }

  string result = "";
  for (int i = start; i < (start + maxlength); ++i) {
    result = result + s[i];
  }

  cout << "result = " << result << endl;
  return result;
}

void printMatrix(vector<vector<int>>& a) {
  for (auto i : a) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

string dynamicProgrammedLCSubstring(string& s) {
  /*
   * Maintain a boolean table[n][n] that is filled in bottom up manner.
The value of table[i][j] is true, if the substring is palindrome, otherwise
false. To calculate table[i][j], check the value of table[i+1][j-1], if the
value is true and str[i] is same as str[j], then we make table[i][j] true.
Otherwise, the value of table[i][j] is made false.
   */
  int len = s.length();
  vector<vector<int>> dp(len, vector<int>(len, 0));
  // single char is always palindrome
  for (int i = 0; i < len; ++i) {
    dp[i][i] = 1;
  }
  // checking string of length 2
  for (int i = 0; i < len - 1; ++i) {
    if (s[i] == s[i + 1]) dp[i][i + 1] = 1;
  }
  int start = 0;
  int maxLength = 2;
  // check for string >= 3 length
  for (int k = 3; k < len; ++k) {
    for (int i = 0; i < (len - k + 1); ++i) {
      int j = i + k - 1;
      if (s[i] == s[j]) {
        if (dp[i + 1][j - 1] == 1) {
          dp[i][j] = 1;
          if (k > maxLength) {
            start = i;
            maxLength = k;
          }
        }
      }
    }
  }
  for (auto i : s) {
    cout << i << " ";
  }
  cout << "\n";
  printMatrix(dp);

  string result = "";
  for (int i = start; i < (start + maxLength); ++i) {
    result = result + s[i];
  }

  cout << "result = " << result << endl;
  return s;
}

int main() {
  string input = "abcaabbaaabc";
  cout << (bruteForceLCSubstring(input)) << endl;

  cout << "Dynamic Programming " << endl;
  dynamicProgrammedLCSubstring(input);

  return 0;
}

#endif
