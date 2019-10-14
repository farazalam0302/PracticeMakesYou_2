#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l, r;
    cin >> l >> r;
    int one = 1;
    int mask = ((one << abs(l - r) + 1) -1 ) << (min(l, r));
    cout << (n ^ mask) << endl;
  }
  return 0;
}c