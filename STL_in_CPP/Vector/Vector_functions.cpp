#include <bits/stdc++.h>
using namespace std;

class MyFunctionClass {
public:
  void operator()(int i) {
    cout << i << " ";
    // cout << endl;
  }
};

void myFunction(int i) {
  cout << i << " ";
  //   cout << endl;
}

int main(int argc, char const *argv[]) {

  vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> b{9, 8, 7, 6, 5, 4, 3, 2, 1};
  vector<int> c{1, 2, 3, 4, 9, 8, 7, 6, 5};
  vector<int> odd{1, 3, 9, 7, 5};

  // all_of example
  if (std::all_of(odd.begin(), odd.end(), [](int i) { return i % 2; })) {
    cout << "\nAll elements are odd numbers\n";
  } else {
    cout << "\nAll elements are not odd numbers\n";
  }

  // any_of example

  if (std::any_of(odd.begin(), odd.end(), [](int i) { return i % 2 == 0; })) {
    cout << "\nSome elements are even numbers\n";
  } else {
    cout << "\nSome elements are not even numbers\n";
  }

  // none_of example

  if (std::none_of(a.begin(), a.end(), [](int i) { return i % 2 == 0; })) {
    cout << "\nNo elements are even numbers\n";
  } else {
    cout << "\nSome elements are even numbers\n";
  }

  // for_each example
  cout << "\n forEach example \n";
  for_each(b.begin(), b.end(), myFunction);
  cout << "\n";

  return 0;
}
