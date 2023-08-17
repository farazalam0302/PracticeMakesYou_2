/*
 * Array int
 * {6,4,1,5}
 *
 * pair of (max sum )
 *
 * out
 * 6,5
 *
 */

#include <bits/stdc++.h>
using namespace std;

int maxPairSum(vector<int> &a) {
  int n = a.size();
  //    pair<int , int> maxPair;
  //  sort(a.begin(), a.end());
  int maX = -1000;
  int secondMax = -1001;
  for (int i = 0; i < n; ++i) {
    if (maX < a[i]) {
      secondMax = maX;
      maX = a[i];
    } else if (secondMax < a[i] && secondMax != maX) {
      secondMax = a[i];
    }
  }

  cout << secondMax << ", " << maX << endl;
}

int main(int argc, char **argv) {

  vector<int> a{6, 4, 1, 5};
  int r = maxPairSum(a);
  return 0;
}
