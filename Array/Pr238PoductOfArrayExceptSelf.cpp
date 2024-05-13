#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &a) {
  cout << endl;
  for (auto &i : a) {
    cout << i << " ";
  }
  cout << endl;
}

vector<int> productExceptSelf(vector<int> &a) {
  int n = a.size();
  vector<int> ret;
  vector<int> left(n, 0);
  vector<int> right(n, 0);
  left[0] = a[0];
  for (int i = 1; i < n; i++) {
    left[i] = left[i - 1] * a[i];
  }
  right[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    right[i] = right[i + 1] * a[i];
  }
  cout << "\n input Array" << endl;
  printArray(a);
  cout << "\n left Array" << endl;
  printArray(left);
  cout << "\n right Array" << endl;
  printArray(right);

  a[0] = right[1];
  a[n - 1] = left[n - 2];

  for (int i = 1; i < n - 1; i++) {
    a[i] = left[i - 1] * right[i + 1];
  }

  printArray(a);

  return a;
}

int main(int argc, char const *argv[]) {
  vector<int> a{0, 1, 0, -3, 3};
  productExceptSelf(a);
  return 0;
}
