// /home/falam/Dropbox/Placement_prep/leetcode/JewelsandStones.cpp

#include <bits/stdc++.h>
using namespace std;
class SubArraySum {
public:
  vector<int> subArraySum(vector<int> &A, int s) {
    int n = A.size();
    int start = 0;
    int curr_sum = A[0];
    int end = 0;
    for (int i = 1; i < n; i++) {
      while (curr_sum > s && start < i) {
        curr_sum = curr_sum - A[start];
        start++;
      }

      if (curr_sum == s) {
        end = i;
        break;
      }

      curr_sum += A[i];
    }

    vector<int> ret;
    for (int i = start; i < end; i++) {
      ret.push_back(A[i]);
    }

    return ret;
  }
};

int main() {
  int t;
  cin >> t;
  int k, n;
  while (t--) {
    cout << "Enter N ?" << endl;
    cin >> n;
    cout << "Enter sum ?? \n " << endl;
    cin >> k;
    vector<int> a(n);
    int temp;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      a.push_back(temp);
    }

    SubArraySum ss;

    vector<int> ret = ss.subArraySum(a, k);

    for (auto i : ret) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}
