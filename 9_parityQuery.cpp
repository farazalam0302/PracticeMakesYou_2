#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;
  int result = 1;
  while (n) {
    if (n & 1 == 1)
      result = (result ^ 1);
    n = n & (n - 1);
  }

  cout << " parity " << result << endl;
  //    cout << "even parity " << result << endl;

  return 0;
}