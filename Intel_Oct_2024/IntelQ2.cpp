// Compute Fact (N) print ; no float and range 1 <= n <= 100
// 158 digits  9.332622e+157
#include <bits/stdc++.h>
using namespace std;

int a[158];
int factorial(int n) {
  int lsb = 157;
  a[lsb] = n;
  int carry = 0;
  int tmp = 0;
  for (int i = n - 1; i >= 1; i--) {
    tmp = a[lsb] * i + carry;
    a[lsb - 1] == tmp % 10;
    carry = tmp / 10;
    lsb--;
    // a[lsb-1]=a[lsb]*i/10;ls
  }
}

int main(int argc, char const *argv[]) {

  int n = 8;
  int r = factorial(100);
  cout << "result = " << r << endl;
  return 0;
}
