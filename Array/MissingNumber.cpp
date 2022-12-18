#include <bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> &a) {
  int n = a.size();

  for (int i = 0; i < n; ++i) {
    if (abs(a[i]) - 1 < n && a[abs(a[i]) - 1] > 0) {
      a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
    }
  }

  for (auto i : a) {
    cout << i << ", ";
  }
  cout << endl;

  for (int i = 0; i < n; ++i) {
    if (a[i] > 0)
      return (i + 1);
  }

  return -100;
}

int main(int argc, char **argv) {

  vector<int> a{1, 2, 5, 4};

  int result;
  result = findMissingNumber(a);
  cout << "\n The Missing Number = " << result << endl;

  return 0;
}
