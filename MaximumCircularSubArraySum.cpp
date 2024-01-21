
/*
 * https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
 *
 * Given a circular array of size n, find the maximum subarray sum of the
non-empty subarray.

Examples:

Input: arr[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22
Explanation: Subarray 12, 8, -8, 9, -9, 10 gives the maximum sum, that is 22.

Input: arr[] = {10, -3, -4, 7, 6, 5, -4, -1}
Output:  23
Explanation: Subarray 7, 6, 5, -4, -1, 10 gives the maximum sum, that is 23.


Input: arr[] = {-1, 40, -14, 7, 6, 5, -4, -1}
Output: 52
Explanation: Subarray 7, 6, 5, -4, -1, -1, 40 gives the maximum sum, that is 52.

Recommended Problem
Max Circular Subarray Sum
Arrays
Data Structures
Amazon
Microsoft
Solve Problem
Submission count: 94.9K
Maximum Circular Subarray Sum using Kadane’s Algorithm:
The idea is to modify Kadane’s algorithm to find a minimum contiguous subarray
sum and the maximum contiguous subarray sum, then check for the maximum value
between the max_value and the value left after subtracting min_value from the
total sum.

Illustration:

Input: arr[] = {8, -8, 9, -9, 10, -11, 12}, N = 7

sum = 11

Initialise: curr_max = arr[0], max_so_far = arr[0], curr_min = arr[0],
min_so_far = arr[0]

At i = 1:

curr_max = max(curr_max + arr[1], arr[1]) = max(8 + (-8), -8) = 0
max_so_far = max(max_so_far, curr_max) = max(8, 0) = 8
curr_min = min(curr_min + a[1], a[1]) = min(8 + (-8), -8) = -8
min_so_far = min(curr_min, min_so_far) = min(-8, 8) = -8
At i = 2:

curr_max = max(curr_max + arr[2], arr[2]) = max(0 + 9, 9) = 9
max_so_far = max(max_so_far, curr_max) = max(8, 9) = 9
curr_min = min(curr_min + a[2], a[2]) = min(-8 + 9, 9) = 1
min_so_far = min(curr_min, min_so_far) = min(1, -8) = -8
At i = 3:


curr_max = max(curr_max + arr[3], arr[3]) = max(9 + (-9), -9) = 0
max_so_far = max(max_so_far, curr_max) = max(9, 0) = 9
curr_min = min(curr_min + a[3], a[3]) = min(1 + (-9), -9) = -9
min_so_far = min(curr_min, min_so_far) = min(-9, -8) = -9
At i = 4:

curr_max = max(curr_max + arr[4], arr[4]) = max(0 + 10, 10) = 10
max_so_far = max(max_so_far, curr_max) = max(9, 10) = 10
curr_min = min(curr_min + a[4], a[4]) = min(-9 + 10, 10) = 1
min_so_far = min(curr_min, min_so_far) = min(1, -9) = -9
At i = 5:

curr_max = max(curr_max + arr[5], arr[5]) = max(10 + (-11), -11) = -1
max_so_far = max(max_so_far, curr_max) = max(10, -1) = 10
curr_min = min(curr_min + a[5], a[5]) = min(1 + (-11), -11) = -11
min_so_far = min(curr_min, min_so_far) = min(-11, -9) = -11
At i = 6:

curr_max = max(curr_max + arr[6], arr[6]) = max(-1 + 12, 12) = 12
max_so_far = max(max_so_far, curr_max) = max(10, 12) = 12
curr_min = min(curr_min + a[6], a[6]) = min(-11+ 12, 12) = 1
min_so_far = min(curr_min, min_so_far) = min(1, -11) = -11
ans = max(max_so_far, sum – min_so_far) = (12, 11 – (-11)) = 22

Hence, maximum circular subarray sum is 22

Follow the steps below to solve the given problem:

We will calculate the total sum of the given array.
We will declare the variable curr_max, max_so_far, curr_min, min_so_far as the
first value of the array. Now we will use Kadane’s Algorithm to find the maximum
subarray sum and minimum subarray sum. Check for all the values in the array:-
If min_so_far is equaled to sum, i.e. all values are negative, then we return
max_so_far. Else, we will calculate the maximum value of max_so_far and (sum –
min_so_far) and return it.
 */

#include <bits/stdc++.h>
using namespace std;
int circularKadane(vector<int> &a) {
  int currmax = a[0];
  int maxSofar = a[0];
  int currmin = a[0];
  int minSofar = a[0];
  int sum = a[0];

  int n = a.size();
  for (int i = 1; i < n; ++i) {
    sum += a[i];
    currmax = max(currmax + a[i], a[i]);
    maxSofar = max(maxSofar, currmax);

    currmin = min(currmin + a[i], a[i]);
    minSofar = min(currmin, minSofar);
  }
  if (minSofar == sum)
    return maxSofar;

  return (max(maxSofar, sum - minSofar));
}

int main(int argc, char **argv) {
  vector<int> a{-1, 40, -14, 7, 6, 5, -4, -1};

  cout << circularKadane(a) << endl;
  return 0;
}
