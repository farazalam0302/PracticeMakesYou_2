#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  n = 10;
  vector<int> a(1024, 0);
  vector<int> hashMap(n + 1, 0);
  a[1] = n;
  int i = 1;
  while (n >= 0) {
    int k = i * 2;
    a[k] = a[i] - 1;
    a[k + 1] = a[i] - 2;
    i = i + 1;
    n = n - 1;
  }

  for (size_t i = 1; i < 1024; i++) {
    cout << i << "->" << a[i] << " : ";
    if (i % 16 == 0)
      cout << "\n";
    // hashMap[i]++;
  }
  cout << endl;

  return 0;
}
