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
 For each test case, print in a new line, the next greater element for each
 array element separated by space in order.

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
 Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4
 and for 4 ? since it doesn't exist hence -1.

 ** For More Input/Output Examples Use 'Expected Output' option **

 */

#include <bits/stdc++.h>
using namespace std;
class NextGreater {
 public:
  void nextGreater(vector<int>& a) {
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
/*
 * Method 2 (Using Stack)

Push the first element to stack.
Pick rest of the elements one by one and follow the following steps in loop.
Mark the current element as next.
If stack is not empty, compare top element of stack with next.
If next is greater than the top element,Pop element from stack. next is the next
greater element for the popped element. Keep popping from the stack while the
popped element is smaller than next. next becomes the next greater element for
all such popped elements Finally, push the next in the stack. After the loop in
step 2 is over, pop all the elements from stack and print -1 as next element for
them.
 */
void nextGreaterElement(vector<int>& a) {
  int sz = a.size();
  if (sz == 0) return;

  stack<int> mstack;
  mstack.push(0);
  unordered_map<int, int> nextGreat;
  vector<int> result(sz, -1);
  int k = 0;
  for (int i = 1; i < sz; ++i) {
    if (mstack.empty()) {
      mstack.push(i);
      continue;
    }
    while (mstack.empty() == false && a[i] > a[mstack.top()]) {
      nextGreat[a[mstack.top()]] = a[i];
      result[mstack.top()] = a[i];
      mstack.pop();
    }

    mstack.push(i);
  }

  while (mstack.empty() == false) {
    nextGreat[a[mstack.top()]] = -1;

    mstack.pop();
  }
  for (auto i : nextGreat) {
    cout << i.first << " --> " << i.second << endl;
  }
  cout << "\n\n\n##########################\n\n";
  for (int i = 0; i < sz; ++i) {
    cout << a[i] << " -> " << result[i] << endl;
  }
}

int main() {
  int t;
  //  cin >> t;
  t = 1;
  while (t--) {
    int n, tmp;
    //    cin >> n;
    n = 4;
    vector<int> a{13, 7, 6, 12};
    //    for (int i = 0; i < n; i++) {
    //      cin >> tmp;
    //      a.push_back(tmp);
    //    }
    //    NextGreater ng;
    //    ng.nextGreater(a);
    for (auto i : a) {
      cout << i << ", ";
    }
    cout << endl;
    nextGreaterElement(a);
    // for (auto i : ret) {
    //   cout << i << " ";
    // }
    // cout << endl;
  }

  return 0;
}
