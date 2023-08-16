#include <bits/stdc++.h>
using namespace std;

string removeSpaces(string &input) {
  string ret = "";
  for (auto &i : input) {
    if (i == ' ')
      continue;
    ret = ret + i;
  }
  return ret;
}

int evaluate(string &in) {
  int n = in.length();
  if (n == 0) {
    cout << "\nEmpty Command\n";
    return -1;
  }
  string s = removeSpaces(in);
  cout << s << endl;
  stack<string> opStack;
  string tr = "true";
  string ntr = "!true";
  string fa = "false";
  string nfa = "!false";

  string op = "";
  for (int i = 0; i < n; i++) {
    string tok = "";
    while (s[i] != '|' && s[i] != '&' && i < n) {
      tok = tok + s[i];
      i++;
    }
    // cout << tok << endl;
    opStack.push(tok);
    // cout << s[i] << endl;
    if (i < n) {
      op = "";
      op = op + s[i];
      opStack.push(op);
    }
  }
  int op1, op2;
  string topp;
  // while (opStack.size() > 0) {
  //   topp = opStack.top();
  //   opStack.pop();
  //   cout << "\n topp =" << topp << endl;
  // }

  topp = opStack.top();
  opStack.pop();
  cout << "\n topp=" << topp << endl;
  cout << "\n nfa=" << nfa << endl;
  cout << "\n\n\nequals = " << (topp.compare("!false")) << endl;
#if 0
  while (opStack.size() > 1) {
    topp = opStack.top();
    opStack.pop();
    cout << "\n topp = " << topp << endl;
    cout << "\n topp.compare(nfa) == 0 =" << (topp.compare(nfa)) << endl;
    if (topp.compare(ntr) == 0 || topp.compare(fa) == 0)
      op1 = 0;
    else if (topp.compare("!false") == 0 || topp.compare(tr) == 0)
      op1 = 1;
    else {
      cout << "\n1. invalid tokens\n";
      return -1;
    }
    string op = opStack.top();
    opStack.pop();
    topp = opStack.top();
    opStack.pop();
    if (topp.compare(ntr) == 0 || topp.compare(fa) == 0)
      op2 = 0;
    else if (topp.compare(nfa) == 0 || topp.compare(tr) == 0)
      op2 = 1;
    else {
      cout << "\n2. invalid tokens\n";
      return -1;
    }
    int res;
    if (op.compare("|") == 0) {
      res = op1 | op2;
    } else if (op.compare("&") == 0) {
      res = op1 & op2;
    } else {
      cout << "\nerrored ops\n";
      return -1;
    }
    if (res == 0) {
      opStack.push(fa);
    } else if (res == 1) {
      opStack.push(tr);
    }
  }
  cout << opStack.top() << endl;
#endif
  return 0;
}

int main(int argc, char const *argv[]) {
  string s = "true | false & true | !false";
  int val = evaluate(s);
  cout << "\nval = " << val << endl;
  return 0;
}
