#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> a{0, 1, 0, 2, 0, 1, 2, 1, 1, 1, 2, 2, 2, 0, 0, 0, 1, 2, 2, 1, 0};

  int t0 = 0;
  int t2 = a.size() - 1;
  int tmp;
  for (int i = t2; t0 < t2 && i >= 0; i--) {
    if (a[i] == 0) {
      tmp = a[i];
      a[i] = a[t0];
      a[t0] = tmp;
      t0++;
    }
    if (a[i] == 2) {
      tmp = a[i];
      a[i] = a[t2];
      a[t2] = tmp;
      t2--;
    }
  }

  // for (int i = 0; i < a.size(); i++) {
  //   if (a[i] == 0) {
  //     tmp = a[i];
  //     a[i] = a[t0];
  //     a[t0] = tmp;
  //     t0++;
  //   }
  // }
  // for (int i = t0; i < a.size(); i++) {
  //   if (a[i] == 1) {
  //     tmp = a[i];
  //     a[i] = a[t0];
  //     a[t0] = tmp;
  //     t0++;
  //   }
  // }

  for (auto &&i : a) {
    cout << i << ", ";
  }

  cout << endl;

  return 0;
}
