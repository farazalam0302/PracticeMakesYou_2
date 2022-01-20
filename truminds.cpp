#include <bits/stdc++.h>
using namespace std;

// int function1(a, b)

int main() {  //

  //	int (*func)(int, int);

  unsigned char b[20];
  unsigned char *x;
  x = b + 5;
  cout << (x - b) << endl;

  unsigned int *p = (unsigned int *)b;

  cout << *(p + 2) << endl;

  //  int a = 16;  // 10000
  //
  //  int mask =  0x1 << n;
  //  a = a & ~mask;
  //
  //  cout << hex << a << endl;

  return 0;
}
