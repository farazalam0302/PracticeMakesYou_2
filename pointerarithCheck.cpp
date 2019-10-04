#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[5] = {1, 2, 3, 4, 5};
  int *ptr = a;
  //   cout << " ptr value = " << *ptr << endl;
  for (int i = 0; i < 5; i++) {
    cout << " ptr value = " << ptr[0] << endl;
    ptr++;
  }
  return 0;
}