/******
Inputs:
   s: A string of logical expression supporting "&", "|" and "!".



Returns:
   -1: Invalid token in s.
    0: Value of expression s is false
    1: Value of expression s is true



Example:
   s = "false|!false&true"
   returns: 1



   s = "true|ture"
   returns: -1



******/

#include <bits/stdc++.h>
using namespace std;

// enum { false = 0, true = 1, invalid = -1 };

int evaluate(string s) {
  int n = s.length();
  if (n == 0)
    return -1;
  string tr = "true";
  string fl = "false";
}
}
int main(int argc, char **argv) {

  string input = "false|!false&true";
  int decision = evaluate(input);
  cout << decision << endl;
  return 0;
}
