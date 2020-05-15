/*
link : https://practice.geeksforgeeks.org/problems/next-larger-element/0

https://www.geeksforgeeks.org/next-greater-element/

Given an array A of size N having distinct elements, the task is to find the
next greater element for each element of the array in order of their appearance
in the array. If no such element exists, output -1

Input:
The first line of input contains a single integer T denoting the number of test
cases.Then T test cases follow. Each test case consists of two lines. The first
line contains an integer N denoting the size of the array. The Second line of
each test case contains N space separated positive integers denoting the
values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array
element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

1
4
1 3 2 4

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and
for 4 ? since it doesn't exist hence -1.

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
using namespace std;
class NextGreater {
public:
  void nextGreater(vector<int> &a) {
    vector<int> ret;
    stack<int> mystack;
    int n = a.size();
    mystack.push(a[0]);
    int i;
    for (i = 1; i < n; i++) {
      if (mystack.empty()) {
        mystack.push(a[i]);
        continue;
      }
      while ((mystack.empty() == false) && a[i] > mystack.top()) {
        // ret.push_back(a[i]);
        cout << a[i] << " ";
        mystack.pop();
        if (mystack.empty()) {
          break;
        }
      }
      mystack.push(a[i]);
    }
    while (mystack.empty() == false) {
      ret.push_back(-1);
      cout << (-1) << " ";
      mystack.pop();
    }
    cout << endl;
    return;
  }
};

int main() {
  int t;
  cin >> t;
  // t = 1;
  while (t--) {
    int n, tmp;
    cin >> n;
    // n = 4;
    vector<int> a; //{1, 3, 2, 4};
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      a.push_back(tmp);
    }
    NextGreater ng;
    ng.nextGreater(a);
    // for (auto i : ret) {
    //   cout << i << " ";
    // }
    // cout << endl;
  }

  return 0;
}