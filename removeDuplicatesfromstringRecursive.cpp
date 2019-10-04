/*
Notes : link
https://www.geeksforgeeks.org/recursively-remove-adjacent-duplicates-given-string/

question link :
https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0


Given a string s, recursively remove adjacent duplicate characters from the
string s. The output string should not have any adjacent duplicates.
 


Input:
The first line of input contains an integer T, denoting the no of test cases.
Then T test cases follow. Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac

*/
#include <bits/stdc++.h>
using namespace std;

class DupRemove {

public:
  char *dupRemove(char *s, char *lastChar) {
    if (s[0] == '\0' || s[1] == '\0')
      return s;
    if (s[0] == s[1]) {
      *lastChar = s[0];
      while (s[1] && s[0] == s[1])
        s++;
      s++;
      return (dupRemove(s, lastChar));
    }
    char *remainingStr = dupRemove(s + 1, lastChar);

    if (remainingStr[0] && remainingStr[0] == s[0]) {
      *lastChar = s[0];
      return (remainingStr + 1);
    }

    if (remainingStr[0] == '\0' && *lastChar == s[0]) {
      return remainingStr;
    }
    remainingStr--;
    remainingStr[0] = s[0];
    return remainingStr;
  }
};

int main() {
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    char s[] = "geeks";
    // cin >> s;

    // int n = s.length();
    // string ret = "";
    // for (int i = 0; i < n; i++) {
    //   while (s[i] == s[i + 1]) {
    //     i++;
    //     // continue;
    //   }
    //   if (s[i] == s[i - 1] && i != 0)
    //     continue;
    //   ret = ret + s[i];
    // }
    DupRemove dr;
    char lastChar = '\0';
    char *ret = dr.dupRemove(s, &lastChar);
    cout << "\nresult = " << ret << endl;
  }

  return 0;
}