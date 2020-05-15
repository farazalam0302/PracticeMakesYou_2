#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &a) {
    int n = a.size();
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      if (a[abs(a[i]) - 1] < 0)
        continue;

      a[abs(a[i]) - 1] = a[abs(a[i]) - 1] * (-1);
    }
    for (int i = 0; i < n; i++) {
      if (a[i] > 0) {
        ret.push_back(i + 1);
      }
    }

    return ret;
  }
};

int main() {
  string line;
  //   while (getline(cin, line)) {
  vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1}; //= stringToIntegerVector(line);

  vector<int> ret = Solution().findDisappearedNumbers(nums);

  for (auto i : ret)
    cout << i << " ";
  cout << endl;

  //   }
  return 0;
}