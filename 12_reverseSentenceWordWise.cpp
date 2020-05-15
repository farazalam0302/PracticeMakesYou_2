/*

reference link  =
https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0


Given a String of length S, reverse the whole string without reversing the
individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow.
Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed
String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*/
#include <bits/stdc++.h>
using namespace std;

class RevSentence {
public:
  string revSentenceWordWise1(string &s) {
    int sz = s.size();
    stack<string> mystack;
    string temp = "";
    for (int i = 0; i < sz; i++) {
      if (s[i] != '.') {
        temp = temp + s[i];
      } else {
        mystack.push(temp);
        temp = "";
      }
    }
    mystack.push(temp);
    sz = mystack.size();
    string ret = "";
    while (mystack.empty() == false) {

      ret = ret + mystack.top();
      mystack.pop();
      if (mystack.size() == 0)
        break;
      ret += ".";
    }
    return ret;
  }
  string revSentenceWordWise2(string &s) {
    int sz = s.size();
    char *cstr = (char *)s.c_str();

    stack<string> mystack;
    string temp = "";
    char *token = strtok(cstr, ".");
    while (token) {
      mystack.push((token));
      token = strtok(NULL, ".");
    }

    sz = mystack.size();
    string ret = "";
    while (mystack.empty() == false) {

      ret = ret + mystack.top();
      mystack.pop();
      if (mystack.size() == 0)
        break;
      ret += ".";
    }
    return ret;
  }
};

int main() {
  int t;
  RevSentence rs;
  cin >> t;
  t = 1;
  while (t--) {
    string s = "i.like.this.program.very.much";
    // cin >> s;
    cout << rs.revSentenceWordWise1(s) << endl;
  }

  // string a = "i.like.this.program.very.much";
  // RevSentence rs;
  // cout << rs.revSentenceWordWise(a) << endl;
  return 0;
}
