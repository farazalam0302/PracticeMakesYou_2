/*

https://leetcode.com/problems/move-zeroes/?envType=study-plan-v2&envId=leetcode-75
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &a) {
    for (int nonzero = 0, i = 0; i < a.size(); i++) {
      if (a[i] != 0) {
        swap(a[nonzero++], a[i]);
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  vector<int> a{3, 0, 0, 0, 3, 4, 2};

  sol.moveZeroes(a);
  for (auto &&i : a) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
