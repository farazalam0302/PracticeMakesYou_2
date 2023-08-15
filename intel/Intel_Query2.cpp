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
          cout << "\n1. Reason No #Stars left for }\n" << endl;
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
      } else {
        cout << "\nReason Stars Position is beyond } position \n" << endl;
        return false;
      }
    } else {
      cout << "\n2. Reason No #Stars left for }\n" << endl;
      return false;
    }
  }
  if (starStack.size() & 0x1) {
    cout << "\nReason #Stars left is odd\n" << endl;
    return false;
  }
  return true;
}
int main(int argc, char const *argv[]) {
  string inp = "{***}}}}}";
  bool Decision = checkBalance(inp);
  Decision ? cout << "\n\nYes Balanced!!!\n\n"
           : cout << "\n\nNot Balanced!!!\n\n";
  return 0;
}
