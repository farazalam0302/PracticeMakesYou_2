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

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    string ret = "";
    for (int i = 0; i < n; i++) {
      while (s[i] == s[i + 1]) {
        i++;
        // continue;
      }
      if (s[i] == s[i - 1] && i != 0)
        continue;
      ret = ret + s[i];
    }
    cout << "\nresult = " << ret << endl;
  }

  return 0;
}