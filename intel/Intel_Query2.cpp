#include <bits/stdc++.h>
using namespace std;
/*
given a string of {{}{}{}}******
check balanced parens
*/
bool checkBalance(string &a) {
  int len = a.length();
  stack<int> openStack;
  stack<int> starStack;
  for (int i = 0; i < len; i++) {
    if (a[i] == '{')
      openStack.push(i);
    else if (a[i] == '*') {
      starStack.push(i);
    } else if (a[i] == '}') {
      if (!openStack.empty()) {
        openStack.pop();
      } else {
        if (!starStack.empty()) {
          starStack.pop();
        } else {
          return false;
        }
      }
    }
  }
  while (!openStack.empty()) {
    if (!starStack.empty()) {
      if (openStack.top() < starStack.top()) {
        openStack.pop();
        starStack.pop();
      } else
        return false;
    } else
      return false;
  }
  if (starStack.size() & 0x1)
    return false;
  return true;
}
int main(int argc, char const *argv[]) {
  string inp = "***{{{}}";
  bool Decision = checkBalance(inp);
  Decision ? cout << "\n\nYes Balanced!!!\n\n"
           : cout << "\n\nNo Balanced!!!\n\n";
  return 0;
}
