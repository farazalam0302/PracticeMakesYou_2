#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& a) {
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
}

bool myCompare(int& lhs, int& rhs) { return (lhs >= rhs); }

int luckBalance(int k, vector<vector<int>>& contests) {
  int n = contests.size();
  vector<int> a;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (contests[i][1] == 0) {
      ans += contests[i][0];
    } else {
      a.push_back(contests[i][0]);
    }
  }
  sort(a.begin(), a.end(), myCompare);
  cout << "\n\n Array A =  \n\n";
  printArray(a);
  //  reverse(a.begin(), a.end());
  cout << "\n\n Reverse \n\n";
  printArray(a);
  for (int i = 0; i < min(n, k); i++) {
    ans += a[i];
  }
  for (int i = k; i < n; i++) {
    ans -= a[i];
  }

  return ans;
}

int main() {
  vector<vector<int>> c{{5, 1}, {4, 0}, {6, 1}, {2, 1}, {8, 0}};
  int k = 2;

  int luckB = luckBalance(k, c);

  cout << "\n\n result  = " << luckB << endl;

  return 0;
}
