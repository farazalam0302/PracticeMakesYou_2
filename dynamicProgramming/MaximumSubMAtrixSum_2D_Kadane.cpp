/*

Maximum sum rectangle in a 2D matrix | DP-27
Given a 2D array, find the maximum sum subarray in it. For example, in the
following 2D array, the maximum sum subarray is highlighted with blue rectangle
and sum of this subarray is 29.


This problem is mainly an extension of Largest Sum Contiguous Subarray for 1D
array.


Recommended: Please solve it on “PRACTICE ” first, before moving on to the
solution. The naive solution for this problem is to check every possible
rectangle in given 2D array. This solution requires 4 nested loops and time
complexity of this solution would be O(n^4).

Kadane’s algorithm for 1D array can be used to reduce the time complexity to
O(n^3). The idea is to fix the left and right columns one by one and find the
maximum sum contiguous rows for every left and right column pair. We basically
find top and bottom row numbers (which have maximum sum) for every fixed left
and right column pair. To find the top and bottom row numbers, calculate sun of
elements in every row from left to right and store these sums in an array say
temp[]. So temp[i] indicates sum of elements from left to right in row i. If we
apply Kadane’s 1D algorithm on temp[], and get the maximum sum subarray of temp,
this maximum sum would be the maximum possible sum with left and right as
boundary columns. To get the overall maximum sum, we compare this sum with the
maximum sum so far.

*/

#include <bits/stdc++.h>
using namespace std;

int kadane_1D(vector<int> &t, int &start, int &end) {
  int n = t.size();
  int maxSumTillNow = INT_MIN;
  int currentMaxima = 0;
  start = 0;
  end = -1;
  for (int i = 0; i < n; i++) {
    currentMaxima = currentMaxima + t[i];
    if (currentMaxima > maxSumTillNow) {
      maxSumTillNow = currentMaxima;
      end = i;
    }
    if (currentMaxima < 0) {
      start = i + 1;
      currentMaxima = 0;
    }
  }
  if (end != -1) {
    return maxSumTillNow;
  }

  // special case if all numbers < 0
  maxSumTillNow = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (maxSumTillNow < t[i]) {
      start = end = i;
      maxSumTillNow = t[i];
    }
  }
  return maxSumTillNow;
}

int main(int argc, char const *argv[]) {
  int M[4][5] = {{1, 2, -1, -4, -20},
                 {-8, -3, 4, 2, 1},
                 {3, 8, 10, 1, 3},
                 {-4, -1, 1, 7, -6}};
  int rows = 4;
  int cols = 5;
  int maxSum = INT_MIN;
  int sum, start, end;

    int finalLeft, finalRight, left, right, finalTop, finalBottom;
  for (left = 0; left < 5; left++) {
    // resetting temp array

    vector<int> temp(4, 0);

    // resetting temp array

    for (right = left; right < 5; right++) {
      for (int i = 0; i < 4; i++) {
        temp[i] = temp[i] + M[i][right];
      }
      sum = kadane_1D(temp, start, end);
      if (sum > maxSum) {
        maxSum = sum;
        finalLeft = left;
        finalRight = right;
        finalTop = start;
        finalBottom = end;
      }
    }
  }
  cout << "Max sum is: " << maxSum << "\n\n" << endl;

  for (int i = finalTop; i <= finalBottom; i++) {
    for (int j = finalLeft; j <= finalRight; j++) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
