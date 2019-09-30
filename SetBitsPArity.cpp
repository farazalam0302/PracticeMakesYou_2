#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;
  int count1 = 0;
  while (n > 0) {
    if (n & 1 == 1)
      count1++;
    n = n >> 1;
  }
  if (count1 & 1)
    cout << "odd parity " << count1 << endl;
  else
    cout << "even parity " << count1 << endl;

  return 0;
}