/*
problem link :
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0


Longest Increasing SubsequenceSubmissions: 87621   Accuracy: 28.09%  
Difficulty: Medium   Marks: 4 Associated Course(s):   Must Do Interview
Preparation



Problems
Given a sequence A of size N, find the length of the longest increasing
subsequence from a given sequence . The longest increasing subsequence means to
find a subsequence of a given sequence in which the subsequence's elements are
in sorted order, lowest to highest, and in which the subsequence is as long as
possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

Input:
The first line contains an integer T, depicting total number of test cases. Then
following T lines contains an integer N depicting the size of array and next
line followed by the value of array.

Output:
For each testcase, in a new line, print the Max length of the subsequence in a
separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 300

Example:
Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3

Explanation:
Testcase 2: Longest increasing subsequence is of size 3 with elements (there are
many subsequence, but listing one of them): 5 7 9.


*/
#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a, string arrayName) {
  cout << ("\nArray " + arrayName) << endl;
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << "\n\n" << endl;
}

int main(int argc, char const *argv[]) {
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> lenArray;
    vector<int> trackingArray;
    vector<int> index;
    int tmp;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      a.push_back(tmp);
      lenArray.push_back(1);
      trackingArray.push_back(i);
      index.push_back(i);
    }
    // LIS
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[j] <= a[i]) {
          if ((lenArray[i] <= lenArray[j] + 1)) {
            lenArray[i] = lenArray[j] + 1;
            trackingArray[i] = j;
          }
        }
      }
    }
    int maxLength = lenArray[0];
    //    for (auto i : lenArray) {
    //      maxLength = max(maxLength, i);
    //    }
    int trackpoint;
    for (int i = 0; i < lenArray.size(); ++i) {
      if (maxLength < lenArray[i]) {
        maxLength = lenArray[i];
        trackpoint = i;
      }
    }
    cout << "trackpoint = " << trackpoint << endl;

    stack<int> mstack;
    mstack.push(a[trackpoint]);
    for (int i = 0; i < maxLength - 1; ++i) {
      trackpoint = trackingArray[trackpoint];
      mstack.push(a[trackpoint]);
    }
    cout << "LIS Series  = " << endl;
    while (!(mstack.empty())) {
      cout << mstack.top() << ", ";
      mstack.pop();
    }
    cout << " LIS length = " << maxLength << endl;
    printArray(a, "input a");
    printArray(trackingArray, "trackingArray");
    printArray(index, "index");
    printArray(lenArray, "lenArray");
  }

  return 0;
}
