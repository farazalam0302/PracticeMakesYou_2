/*

Maximum sum increasing subsequenceSubmissions: 53395   Accuracy: 42.71%  
Difficulty: Easy   Marks: 2 Associated Course(s):   Must Do Interview
Preparation

Problems
Given an array A of N positive integers. Find the sum of maximum sum increasing
subsequence of the given array.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N(the size of array). The second line of
each test case contains array elements.

Output:
For each test case print the required answer in new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ai ≤ 106

Example:
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
Testcase 1: All the increasing subsequences are : (1,101); (1,2,3,100);
(1,2,3,4,5). Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.
*/

#include <bits/stdc++.h>
using namespace std;
class MaxSumIncreasingSubSequence {
public:
  int maxSum_IncreasingSubSequence(vector<int> &a) {
    int n = a.size();
    vector<int> msisDP(a.begin(), a.end());

    // msisDP[0] = a[0];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] > a[j]) {
          if (msisDP[i] < msisDP[i] + a[j]) {
            msisDP[i] = msisDP[i] + a[j];
          }
        }
      }
    }
    int maxMsis = msisDP[0];
    for (int i = 1; i < n; i++) {
      maxMsis = max(maxMsis, msisDP[i]);
    }
    return maxMsis;
  }
};
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  MaxSumIncreasingSubSequence ms;
  int answer = ms.maxSum_IncreasingSubSequence(a);
  cout << "answer = " << answer << endl;

  return 0;
}
