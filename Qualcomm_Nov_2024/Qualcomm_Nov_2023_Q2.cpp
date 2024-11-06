/*
sorted array
target sum = 70;
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> a{1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 6, 6, 6};
  int target = 8;

  int l = 0;

  int r = a.size() - 1;

  while (l < r) {
    int actualSum = a[l] + a[r];
    if (actualSum == target) {
      cout << a[l] << " at " << l << " + " << a[r] << " at " << r << "= "
           << actualSum << endl;
    } else if (actualSum < target) {
      l++;
    } else {
      r--
    }
  }

  return 0;
}
