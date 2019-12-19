/*

https://www.geeksforgeeks.org/maximise-the-number-of-toys-that-can-be-purchased-with-amount-k/
https://practice.geeksforgeeks.org/problems/maximize-toys/0

Maximize ToysSubmissions: 11749   Accuracy: 50.04%   Difficulty: Easy   Marks: 2
Associated Course(s):   Must Do Interview Preparation
    
Problems
Given an array consisting cost of toys. Given an integer K depicting the amount
with you. Maximise the number of toys you can have with K amount.

Input:

The first line contains an integer T, depicting total number of test cases.
Then following T lines contains an integer N depicting the number of toys and an
integer K depicting the value of K. Next line is followed by the cost of toys.


Output:

Print the maximum toys in separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 1000
1 ≤ K ≤ 10000
1 ≤ A[i] ≤ 10000


Example:

Input
1
7 50
1 12 5 111 200 1000 10
Output
4

** For More Input/Output Examples Use 'Expected Output' option **
Author: shef5


*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      pq.push(x);
    }
    int sum = 0;
    int count = 0;
    while (!pq.empty()) {
      sum = sum + pq.top();
      pq.pop();
      if (sum <= k) {
        count++;

      } else {
        break;
      }
    }
    cout << count << endl;
  }
  return 0;
}
