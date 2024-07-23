/*
https://leetcode.com/problems/find-the-highest-altitude/?envType=study-plan-v2&envId=leetcode-75

Example 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int highest = 0;
    int high_local = 0;
    for (int i = 0; i < gain.size(); i++) {
      high_local += gain[i];
      if (high_local >= highest) {
        highest = high_local;
      }
    }
    return highest;
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  vector<int> a{-5, 1, 5, 0, -7};

  int r = sol.largestAltitude(a);
  std::cout << r << endl;
  return 0;
}
