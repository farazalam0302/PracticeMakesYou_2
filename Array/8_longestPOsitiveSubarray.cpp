// /home/falam/Dropbox/Placement_prep/leetcode/JewelsandStones.cpp

#include <bits/stdc++.h>
using namespace std;
class LongestPositivesubArray {
public:
  vector<int> longestPositivesubArray(vector<int> &A) {
    int n = A.size();
    int start = 0;
    int curr_length = 0;
    int max_length = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
      if (A[i] >= 0) {
        curr_length++;
        // end = i;

      } else {
        curr_length = 0;
        // start = i + 1;
      }
      if (curr_length > max_length) {
        max_length = curr_length;
        end = i;
      }

      // max_length = max(max_length, curr_length);
    }
    start = end - max_length + 1;
    cout << "max_length = " << max_length << endl;

    // return max_length;
    cout << "start = " << start << "\nend = " << end << endl;
    vector<int> ret;
    for (int i = start; i <= end; i++) {
      ret.push_back(A[i]);
    }
    // ret.push_back(max_length);

    return ret;
  }
};

int main() {
  int t;
  cin >> t;
  int k, n;
  while (t--) {
    // cout << "Enter N ?" << endl;
    cin >> n;
    // cout << "Enter sum ?? \n " << endl;
    // cin >> k;
    vector<int> a;
    int temp;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      a.push_back(temp);
    }

    LongestPositivesubArray ss;

    vector<int> ret = ss.longestPositivesubArray(a);
    // cout << "return Value = " << ret << endl;

    for (auto i : ret) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
