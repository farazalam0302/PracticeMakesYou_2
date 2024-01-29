
/*
a = {3 4 5 1 2 7}
Number of steps/jumps

Ans 2

*/

#include <bits/stdc++.h>
using namespace std;

int minimumJumps(vector<int> &a, int l, int r) {

  if (a.size() == 0)
    return 0;
  if (l == r)
    return 0;

  int minjumps = INT_MAX;

  for (int i = l; i <= r && i <= l + a[l]; i++) {
    int mjumps = minimumJumps(a, i, r);
    if (mjumps >= 0 && mjumps != INT_MAX && mjumps + l < minjumps)
      minjumps = mjumps + l;
  }
  return minjumps;
}

int main(int argc, char const *argv[]) {
  vector<int> a{3, 4, 5, 1, 2, 7};
  int n = a.size();
  cout << "minimum jumps = " << minimumJumps(a, 0, n - 1) << endl;

  return 0;
}
