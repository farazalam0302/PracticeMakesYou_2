#include <bits/stdc++.h>
using namespace std;

class MultBy {
private:
  int mult{};

public:
  MultBy(int n = 1) : mult(n) {}
  int operator()(int n) const { return mult * n; }

  ~MultBy() {}
};

int main(int argc, char const *argv[]) {
  const MultBy times10(10);
  const MultBy times100(100);
  const MultBy times1000(1000);
  const auto times2000 = [](int n) { return n * 2000; };

  cout << "times10(5) is " << times10(5) << endl;
  cout << "times100(5) is " << times100(5) << endl;
  cout << "times1000(5) is " << times1000(5) << endl;
  cout << "times2000(5) is (lambda called here) = " << times2000(5) << endl;
  //   cout << "times10(5) is " << times10(5) << endl;

  return 0;
}
