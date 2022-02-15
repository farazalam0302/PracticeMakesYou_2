#include <bits/stdc++.h>
using namespace std;
void reverseArray(vector<int>& a) {
  int n = a.size();
  //  int nCols = a[0].size();

  int l = 0;
  int r = n - 1;
  while (l < r) {
    swap(a[l], a[r]);
    l++;
    r--;
  }
}

void printArray(vector<int>& a) {
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> a{1, 2, 3, 4, 5};
  vector<int> b{1, 2, 3, 4};

  reverseArray(a);
  printArray(a);

  reverseArray(b);
  printArray(b);

  return 0;
}
