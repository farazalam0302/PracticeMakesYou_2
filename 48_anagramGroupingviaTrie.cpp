#include <iostream>

struct A {
  virtual int foo() = 0;
};

int A::foo() { return 100; }

struct B : A {
  int foo() override;
};

int B::foo() { return 200; }

int main() {
  B bar;
  std::cout << bar.foo();
  std::cout << ((A&)bar).foo();
}
