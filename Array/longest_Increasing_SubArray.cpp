/*
 * Longest increasing subarray
09-09-2017
Given an array containing n numbers. The problem is to find the length of the
longest contiguous subarray such that every element in the subarray is strictly
greater than its previous element in the same subarray. Time Complexity should
be O(n).

Examples:

Input : arr[] = {5, 6, 3, 5, 7, 8, 9, 1, 2}
Output : 5
The subarray is {3, 5, 7, 8, 9}
 *
 */

#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubArray(vector<int> &a, int &start) {
  int n = a.size();
  int len = 1, maxlength = 1;
  start = 0;
  int end1 = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > a[i - 1]) {
      len++;

    } else {
      if (maxlength < len) {
        maxlength = len;
        end1 = i;
      }
      len = 1;
    }
  }
  if (maxlength < len) {
    maxlength = len;
    end1 = n - 1;
  }

  start = end1 - maxlength;
  return maxlength;
}
int main() {
  vector<int> a{5, 6, 3, 5, 7, 8, 9, 1, 2};
  cout << "\n\n Array is " << endl;
  for (auto i : a) {
    cout << i << ", ";
  }
  cout << "\n\n" << endl;
  int start;
  int longestSubarrayLength = longestIncreasingSubArray(a, start);
  cout << "LOngestIncreasingLength = " << longestSubarrayLength;
  cout << "\n start = " << start << endl;

  for (int i = start; (i < (start + longestSubarrayLength)); ++i) {
    cout << a[i] << ", ";
  }
  cout << endl;

  return 0;
}
