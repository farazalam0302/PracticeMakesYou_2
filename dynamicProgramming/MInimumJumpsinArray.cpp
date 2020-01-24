/*

Minimum number of jumpsSubmissions: 76001   Accuracy: 33.07%   Difficulty:
Medium   Marks: 4 Associated Course(s):   Must Do Interview Preparation DSA-Self
Paced with Doubt Assistance More

Problems
Given an array of integers where each element represents the max number of steps
that can be made forward from that element. The task is to find the minimum
number of jumps to reach the end of the array (starting from the first element).
If an element is 0, then cannot move through that element.

Input:
The first line contains an integer T, depicting total number of test cases. Then
following T lines contains a number n denoting the size of the array. Next line
contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer
is not possible print "-1"(without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 <= ai <= 107

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with
value 3. Now, from here we jump to 5h element with value 9. and from here we
will jump to last.


*/

#include <bits/stdc++.h>
using namespace std;
class MinJumps {
public:
  int minJumps(vector<int> &a) {
    int n = a.size();
    vector<int> jumpArray(n, INT_MAX);
    vector<int> jumpPathArray(n, -1);
    jumpArray[0] = 0;

    cout << "\n----------------------" << endl;
    cout << "\n       Jump Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << jumpArray[i] << " ";
    }
    cout << "\n----------------------" << endl;
    cout << "\n       Jump Path Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << jumpPathArray[i] << " ";
    }
    cout << "\n----------------------" << endl;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (j + a[j] >= i) {
          if (jumpArray[j] != INT_MAX && jumpArray[i] >= jumpArray[j] + 1) {
            jumpArray[i] = jumpArray[j] + 1;
            jumpPathArray[i] = j;
          }
        }
      }
    }
    cout << "\n       Input Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n----------------------" << endl;
    cout << "\n       Jump Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << jumpArray[i] << " ";
    }
    cout << "\n----------------------" << endl;
    cout << "\n       Jump Path Array";
    cout << "\n----------------------" << endl;
    for (int i = 0; i < n; i++) {
      cout << jumpPathArray[i] << " ";
    }
    cout << "\n----------------------" << endl;

    return jumpArray[n - 1];
  }
};
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  MinJumps mj;
  int answer = mj.minJumps(a);
  if (answer != INT_MAX)
    cout << "answer = " << answer << endl;
  else
    cout << "!!!!  NOT REACHABLE  !!! \n\n" << endl;

  return 0;
}
