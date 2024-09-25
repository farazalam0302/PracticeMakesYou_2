#include <bits/stdc++.h>
using namespace std;
#include <fmt/format.h>

class Num {
private:
  int value{};

public:
  Num(int x = 0) : value{x} {}
  int getValue() const { return value; }
  void setValue(int x) { value = x; }
  operator int() { return value; }
  Num &operator++();
  Num operator++(int);
  Num &operator--();
  Num operator--(int);
  ~Num() {}
};
// pre-increment opertor
Num &Num::operator++() {
  cout << "pre increment: ";
  value += 1;
  return *this;
}
// post-increment operatos
Num Num::operator++(int) {
  cout << "post increment: ";
  auto temp = *this;
  value += 1;
  return temp;
}
// pre-increment opertor
Num &Num::operator--() {
  cout << "pre decrement: ";
  value -= 1;
  return *this;
}
// post-increment operatos
Num Num::operator--(int) {
  cout << "post decrement: ";
  auto temp = *this;
  value -= 1;
  return temp;
}

int main(int argc, char const *argv[]) {
  Num n(10);
  cout << "value is " << (n) << endl;
  cout << "value is " << (n--) << endl;
  cout << "value is " << (n++) << endl;
  cout << "value is " << (++n) << endl;
  cout << "value is " << (n) << endl;
  return 0;
}
