/*

Cutted Segments

https://practice.geeksforgeeks.org/problems/cutted-segments/0

https://www.geeksforgeeks.org/maximum-number-segments-lengths-b-c/


Problems
Given an integer N denoting the Length of a line segment. you need to cut the
line segment in such a way that the cut length of a line segment each time is
integer either x , y or z. and after performing all cutting operation the total
number of cutted segments must be maximum.


Input
First line of input contains of an integer 'T' denoting number of test cases.
First line of each testcase contains N . Second line of each testcase contains 3
space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000
 


Example

Input

2
4
2 1 1
5
5 3 2


Output
4
2

In first test case, total length is 4, and cut lengths are 2, 1 and 1.  We can
make maximum 4 segments each of length 1. In secon test case, we can make two
segments of lengths 3 and 2.

*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int t = 1;
  while (t--) {
    int N, x, y, z;
    cin >> N;
    cin >> x, cin >> y, cin >> z;
    vector<int> dp(N + 1, -1);
    dp[0] = 0;
    for (int i = 0; i <= N; i++) {
      if (dp[i] != -1) {
        if (i + x <= N) {
          dp[i + x] = max(dp[i + x], dp[i] + 1);
        }
        if (i + y <= N) {
          dp[i + y] = max(dp[i + y], dp[i] + 1);
        }
        if (i + z <= N) {
          dp[i + z] = max(dp[i + z], dp[i] + 1);
        }
      }
    }

    cout << "maximum number of segments = " << dp[N] << endl;

    cout << endl;
  }

  return 0;
}
