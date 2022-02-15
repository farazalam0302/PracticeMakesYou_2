// C++ program to demonstrate working of auto
// and type inference
#include <bits/stdc++.h>
using namespace std;

int main() {
  auto x = 4;
  auto y = 3.37;
  auto ptr = &x;
  auto f = 1.5f;
  auto s = (uint64_t)1;
  auto ptrF = &f;
  auto ptrD = &y;
  auto ptrptr = &ptr;
  auto ptrptrptr = &ptrptr;
  cout << typeid(x).name() << endl
       << typeid(y).name() << endl
       << typeid(ptr).name() << endl
       << typeid(f).name() << endl
       << typeid(s).name() << endl
       << typeid(ptrptr).name() << endl
       << typeid(ptrF).name() << endl
       << typeid(ptrD).name() << endl
       << typeid(ptrptrptr).name() << endl;

  return 0;
}
