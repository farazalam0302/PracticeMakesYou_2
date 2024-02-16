#include <bits/stdc++.h>
using namespace std;

int sumN(int n, int &sum) {
  if (n == 0)
    return 0;
  sum = sum + n;
  sumN(n - 1, sum);
  return sum;
}

int main(int argc, char const *argv[]) {
  int n;
  //   cin >> n;
  n = 10;
//   malloc(sizeof(char)*X + 2)
// stack smashing

  //   int sum = n * (n + 1) / 2;

  //   for (size_t i = 0; i <= n; i++) {
  //     sum += i;
  //   }
  int sum = 0;
  int res = sumN(n, sum);
  cout << res << "\n";
  return 0;
}
