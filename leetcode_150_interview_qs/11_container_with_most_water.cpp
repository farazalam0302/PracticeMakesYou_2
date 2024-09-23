/*
Container With Most Water
Medium
Topics
Companies
Hint
You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the
container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.



Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49. Example 2:

Input: height = [1,1]
Output: 1


Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &a) {
    int n = a.size();
    int maxArea = -1;
    int left = 0;
    int right = n - 1;
    while (left < right) {
      int tmp = min(a[left], a[right]) * (right - left);
      maxArea = max(maxArea, tmp);
      if (a[left] < a[right]) {
        left++;
      } else {
        right--;
      }
    }

    return maxArea;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> a{1, 8, 6, 2, 5, 4, 8, 3, 7};
  int x;
  x = s.maxArea(a);
  cout << x << endl;

  return 0;
}
