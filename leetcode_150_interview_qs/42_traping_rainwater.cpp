/*
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
are being trapped. Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    int localMax_L = -1;
    int localMax_R = -1;
    vector<int> local_max(n, 0);
    int res = 0;

    for (int i = 0; i < n; i++) {
      localMax_L = max(height[i], localMax_L);
      local_max[i] = localMax_L - height[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      localMax_R = max(height[i], localMax_R);
      local_max[i] = min(local_max[i], localMax_R - height[i]);
      res += local_max[i];
    }

    return res;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> a{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  Solution s;
  cout << (s.trap(a)) << endl;

  return 0;
}
