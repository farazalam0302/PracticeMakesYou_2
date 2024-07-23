/*

https://leetcode.com/problems/find-pivot-index/submissions/1331069717/?envType=study-plan-v2&envId=leetcode-75

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int> &a) {
    int n = a.size();
    int left = 0;
    int right = 0;
    for (auto &i : a) {
      right += i;
    }

    for (int i = 0; i < n; i++) {
      if (left == right - a[i]) {
        return i;
      }
      left = left + a[i];
      right = right - a[i];
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  vector<int> a{1, 2, 3};

  int r = sol.pivotIndex(a);
  std::cout << r << endl;
  return 0;
}
