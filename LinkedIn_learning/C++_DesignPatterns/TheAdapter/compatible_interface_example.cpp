#include <bits/stdc++.h>
using namespace std;

class Component {
public:
  virtual void run() = 0;
  virtual ~Component() = default;
};

class CompatibleClass1 : public Component {
public:
  virtual void run() override { cout << "\nCompatibleClass 1 run execute\n"; }
};

class CompatibleClass2 : public Component {
public:
  virtual void run() override { cout << "\nCompatibleClass 2 run execute\n"; }
};

class LegacyNonCompatibleClass {
public:
  void go() { cout << "\n LegacyNonCompatibleClass go execute\n"; };
};

class LegacyAdapter : public Component {
private:
  unique_ptr<LegacyNonCompatibleClass> m_adaptee;

public:
  LegacyAdapter() : m_adaptee(make_unique<LegacyNonCompatibleClass>()) {}
  virtual void run() override {
    cout << "Legacy Adapter Run called go in legacy" << endl;
    m_adaptee->go();
  }
};

int main(int argc, char const *argv[]) {
  // clang-format off
  const unique_ptr<Component> Components[]
  {
      make_unique<CompatibleClass1>(),
      make_unique<LegacyAdapter>(),
      make_unique<CompatibleClass2>()

   };
  // clang-format on
  for (auto &i : Components) {
    i->run();
  }

  return 0;
}
