#include <bits/stdc++.h>
using namespace std;
string removeSpaces(string &s) {
  string ret = "";
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == ' ')
      continue;
    ret = ret + s[i];
  }
  ret = ret + '\0';
  return ret;
}
int evaluate(string &s) {
  int n = s.length();
  if (n == 0) {
    cout << "\nEmpty Command\n";
    return -1;
  }
  // s = removeSpaces(s);
  cout << s << endl;
  stack<int> vStack;
  bool isNot = false;
  string op = "";
  for (int i = 0; i < n; i++) {
    string tok = "";
    if (s[i] == '!') {
      isNot = true;
      continue;
    }
    while (s[i] != '|' && s[i] != '&' && i < n) {
      tok = tok + s[i];
      i++;
    }
    // cout << "tk = " << tok<< endl;
    if (isNot) {
      if (tok.compare("true") == 0) {
        vStack.push(0);
      } else if (tok.compare("false") == 0) {
        vStack.push(1);
      } else {
        cout << "\n1000 Invalid Tokens\n";
        return -1;
      }
      isNot = false;
    } else {
      if (tok.compare("true") == 0) {
        vStack.push(1);
      } else if (tok.compare("false") == 0) {
        vStack.push(0);
      } else {
        cout << "1001 Invalid Tokens\n";
        return -1;
      }
    }
    if (s[i] == '|' || s[i] == '&') {
      vStack.push(s[i]);
      continue;
    }
  }
  int op1, op2;
  int opr;
  int tmp;
  while (vStack.size() > 2) {
    op1 = vStack.top();
    vStack.pop();
    opr = vStack.top();
    vStack.pop();
    op2 = vStack.top();
    vStack.pop();
    if (opr == (int)'|') {
      tmp = op1 | op2;
      vStack.push(tmp);
    } else if (opr == (int)'&') {
      tmp = op1 & op2;
      vStack.push(tmp);
    }
  }
  return vStack.top();
}
int main(int argc, char const *argv[]) {
  string s = "true|false&true|!false";
  string s2 = " false & true | !  false";

  int val = evaluate(s);
  cout << "\nval = " << val << endl;
  cout << removeSpaces(s2) << endl;

  return 0;
}
