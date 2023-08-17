#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static bool mycomp(vector<int> &a, vector<int> &b) { return (a[0] <= b[0]); }
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals[0].size();
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), mycomp);
    for (int i = 0; i < n; i++) {
      cout << "intervals:: " << intervals[i][0] << ", " << intervals[i][1]
           << endl;
    }
    res.push_back(intervals[0]);

    int count = 0;
    for (int i = 1; i < n; i++) {
      // cout << intervals[i][0] << ", " << intervals[i][1] << endl;
      if (res[count][1] >= intervals[i][0]) {
        // cout << intervals[i][0] << ", " << intervals[i][1] << endl;
        res[count][0] = min(res[count][0], intervals[i][0]);
        res[count][1] = max(res[count][1], intervals[i][1]);
      } else {
        res.push_back(intervals[i]);
        count++;
      }
    }
    return res;
  }
};

void printVector(vector<vector<int>> &v) {
  cout << endl;
  for (auto k : v) {
    cout << k[0] << ", " << k[1] << "]";
  }
  cout << endl;
}

int main(int argc, char **argv) {

  Solution s;
  vector<vector<int>> input{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  printVector(input);
  vector<vector<int>> ret;
  ret = s.merge(input);
  cout << "ret =\n";
  printVector(ret);

  return 0;
}
