// vector-test.cpp by Bill Weinman [bw.org]
// version of 2022-10-26
#include <format>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
void disp_v(auto &v, const string &label = "") {
  if (!label.empty())
    cout << label << endl;
  if (v.empty())
    cout << "[empty]" << endl;
  else
    for (auto &s : v)
      cout << s << " ";
  cout << endl;
}

template <typename T> void swap(T &a, T &b) {
  cout << "::swap\n";
  T _tmp(std::move(a));
  a = std::move(b);
  b = std::move(_tmp);
}

int main() {
  vector<string> v1 = {"one", "two", "three", "four", "five"};
  vector<string> v2 = {"six", "seven", "eight", "nine", "ten"};

  disp_v(v1, "v1");
  disp_v(v2, "v2");

  //   v2 = v1;
  //   disp_v(v1, "v1");
  //   disp_v(v2, "v2");

  // below move is used
  //   v2 = std::move(v1);
  //   disp_v(v1, "v1");
  //   disp_v(v2, "v2");

  ::swap(v1, v2);
  disp_v(v1, "v1");
  disp_v(v2, "v2");
}
