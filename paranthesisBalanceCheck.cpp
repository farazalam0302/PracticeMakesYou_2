/*
Given an expression string exp. Examine whether the pairs and the orders of
“{“,”}”,”(“,”)”,”[“,”]” are correct in exp. For example, the program should
print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp =
“[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.
Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else
print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced

** For More Input/Output Examples Use 'Expected Output' option **
*/
#include <bits/stdc++.h>
using namespace std;

class ParenthesisBalance {
public:
  bool isBalancedParen(string &s) {
    int n = s.length();
    stack<char> mystack;
    for (int i = 0; i < n; i++) {
      if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
        mystack.push(s[i]);
      } else if ((s[i] == '}' || s[i] == ')' ||
                  s[i] == ']' && !mystack.empty())) {
        char ch = mystack.top();
        if (s[i] == '}') {
          if (ch == '{')
            mystack.pop();
          else
            return false;
        } else if (s[i] == ')') {
          if (ch == '(')
            mystack.pop();
          else
            return false;
        } else if (s[i] == ']') {

          if (ch == '[')
            mystack.pop();
          else
            return false;
        }
      }
    }
    return mystack.empty();
  }
};

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string s;
    getline(cin, s);
    ParenthesisBalance pb;
    pb.isBalancedParen(s) ? cout << "balanced" << endl
                          : cout << "not balanced" << endl;
    s = "";
  }
  return 0;
}
