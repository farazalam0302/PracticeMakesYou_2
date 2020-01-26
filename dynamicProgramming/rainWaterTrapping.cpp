/*


Trapping Rain WaterSubmissions: 57612   Accuracy: 42.45%   Difficulty: Medium  
Marks: 4

Problems
Given an array arr[] of N non-negative integers representing height of blocks at
index i as Ai where the width of each block is 1. Compute how much water can be
trapped in between blocks after raining. Structure is like below: |  |
|_|
We can trap 2 units of water in the middle gap.



Input:
The first line of input contains an integer T denoting the number of test cases.
The description of T test cases follows. Each test case contains an integer N
denoting the size of the array, followed by N space separated numbers to be
stored in array.

Output:
Output the total unit of water trapped in between the blocks.

Constraints:
1 <= T <= 100
3 <= N <= 107
0 <= Ai <= 108

Example:
Input:
2
4
7 4 0 9
3
6 9 9

======================


12
0 1 0 2 1 0 1 3 2 1 2 1

Output:
10
0

Explanation:
Testcase 1: Water trapped by block of height 4 is 3 units, block of height 0 is
7 units. So, total unit of water trapped is 10 units.


** For More Input/Output Examples Use 'Expected Output' option **

*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> heights(n, 0);
  vector<int> leftMaxheights(n, 0);
  vector<int> rightMaxheights(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  leftMaxheights[0] = heights[0];
  for (int i = 1; i < n; i++) {
    leftMaxheights[i] = max(leftMaxheights[i - 1], heights[i]);
  }

  rightMaxheights[n - 1] = heights[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    rightMaxheights[i] = max(rightMaxheights[i + 1], heights[i]);
  }

  int waterCapacity = 0;

  for (int i = 0; i < n; i++) {
    waterCapacity = waterCapacity +
                    (min(rightMaxheights[i], leftMaxheights[i]) - heights[i]);
  }

  cout << "\n Water Trapped = " << waterCapacity << endl;

  return 0;
}
