#include <bits/stdc++.h>
using namespace std;

bool isValidNumber(string &s) {
  for (auto &i : s) {
    if (i >= '9' || i <= '0')
      return false;
  }

  return true;
}

int CustomMachine(string &cmds) {
  stack<string> mStack;
  string DUP = "DUP";
  string POP = "POP";
  string PLUS = "+";
  string MINUS = "-";

  char *c = (char *)cmds.c_str();
  char *token = strtok(c, " ");
  while (token) {
    string tmp(token);
    cout << tmp << " ";

    if (tmp.compare(DUP) == 0) {
      if (mStack.empty())
        return -1;
      mStack.push(mStack.top());
    } else if (tmp.compare(POP) == 0) {
      if (mStack.empty())
        return -1;
      mStack.pop();
    } else if (tmp.compare(PLUS) == 0) {
      if (mStack.empty())
        return -1;
      int n1 = stoi(mStack.top());
      mStack.pop();
      if (mStack.empty())
        return -1;
      int n2 = stoi(mStack.top());
      mStack.pop();
      n1 = n1 + n2;
      if (n1 & 0xfff00000)
        return -1;
      mStack.push(to_string(n1));
    } else if (tmp.compare(MINUS) == 0) {
      if (mStack.empty())
        return -1;
      int n1 = stoi(mStack.top());
      mStack.pop();
      if (mStack.empty())
        return -1;
      int n2 = stoi(mStack.top());
      mStack.pop();
      n1 = n1 - n2;
      if (n1 & 0xfff00000)
        return -1;
      mStack.push(to_string(n1));
    } else if (isValidNumber(tmp)) {
      mStack.push(tmp);
    }

    token = strtok(nullptr, " ");
  }
  if (mStack.empty())
    return -1;
  return (stoi(mStack.top()));
}

int main(int argc, char const *argv[]) {
  string cmd1 = "5 6 - +";
  string cmd2 = "1048575 DUP +";
  int n = CustomMachine(cmd1);
  cout << "\n\nANswer = " << n << endl;
  n = CustomMachine(cmd2);
  cout << "\n\nANswer = " << n << endl;

  return 0;
}
