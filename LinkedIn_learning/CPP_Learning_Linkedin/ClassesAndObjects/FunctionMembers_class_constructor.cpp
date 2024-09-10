#include <bits/stdc++.h>
#include <fmt/format.h>
using namespace std;

class C1 {
private:
  /* data */
  int c1val{};

public:
  void setValue(int value) { c1val = value; }
  int getValue() const;
  int getValue();
};

int C1::getValue() const { return c1val; }
int C1::getValue() { return c1val; }

int main(int argc, char const *argv[]) {
  C1 o1;
  o1.setValue(100);
  const C1 o2 = o1;
  cout << format("\no1 value is {}\n", o1.getValue());
  cout << format("o2 value is {}\n", o2.getValue());

  return 0;
}
