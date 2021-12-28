#include <bits/stdc++.h>
using namespace std;
int* changeValue(int* a) {
  //  *a = *a + 10;
  int* b = new int;
  *b = *a * 10;
  return b;
}

int main() {
  int a = 1;
  int* b = changeValue(&a);

  cout << (*b) << " =b ; a = " << a << endl;

  *b = *b * 10;
  cout << (*b) << " =b ; a = " << a << endl;

  cout << hex << (b) << " =b ; a = " << &a << endl;

  delete (b);
  b = nullptr;
  if (b == nullptr) cout << hex << (b) << " NULL CHECK =b ; a = " << &a << endl;

  return 0;
}
