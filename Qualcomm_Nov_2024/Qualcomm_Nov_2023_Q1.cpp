/*
array = each element occcurs twice only one element occurs only once
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> a{1, 1, 3, 3, 4, 4, 5, 5, 6};
  int xorsum = 0;
  for (auto &i : a) {
    xorsum = xorsum ^ i;
  }

  cout << "answer = " << xorsum << endl;

  return 0;
}
