#if 1
/*
 * WAP to permute string upto length 20
 */

#include <bits/stdc++.h>
using namespace std;

void permuteString(string& s, int l, int r) {
  if (l == r)
    cout << s << endl;
  else {
    for (int i = l; i <= r; ++i) {
      swap(s[l], s[i]);
      permuteString(s, l + 1, r);
      swap(s[l], s[i]);
    }
  }
  return;
}

int main() {
  string s = "ABC";
  int n = s.length() - 1;
  permuteString(s, 0, n);  //
  return 0;
}
#endif
