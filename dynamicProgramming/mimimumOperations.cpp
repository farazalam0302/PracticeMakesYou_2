/*

https://practice.geeksforgeeks.org/problems/find-optimum-operation/0



You are given a number N. You have to find the number of operations required to
reach N from 0. You have 2 operations available:

Double the number
Add one to the number
Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case contains an integer N.

Output:
For each test case, in a new line, print the minimum number of operations
required to reach N from 0.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
8
7
Input:
4
5

Explanation:
Testcase1:
Input  : N = 8
Output : 4
0 + 1 = 1, 1 + 1 = 2, 2 * 2 = 4, 4 * 2 = 8
Testcase2:
Input  : N = 7
Output : 5
0 + 1 = 1, 1 + 1 = 2, 1 + 2 = 3, 3 * 2 = 6, 6 + 1 = 7

 



*/

#include <bits/stdc++.h>
using namespace std;

class MinOperation {
public:
  int minOperation_Recursion(int n) {
    if (n == 0)
      return 0;
    if (n % 2 == 1)
      return (1 + minOperation_Recursion(n - 1));
    else
      return (1 + minOperation_Recursion(n / 2));
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n < 0)
      exit(-1);
    int prod = 1;
    int add = 1;
    int tmp = n;
    MinOperation mo;
    cout << "  recursive answer = " << mo.minOperation_Recursion(n) << endl;
    int cost = 0;

    while (tmp != 0) {
      if (tmp & 0x1) {
        tmp--;
        cost = cost + add;
      } else {
        tmp = tmp / 2;
        cost = cost + prod;
      }
    }
    cout << "  non Recursive answer = " << cost << endl;
  }
  return 0;
}