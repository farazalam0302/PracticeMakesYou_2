#include <bits/stdc++.h>
#include <fmt/format.h>
#include <iostream>
using namespace std;
using namespace std;
using std::cout;
using std::format;

int main(int argc, char const *argv[]) {

  string s = "12354";
  int x;
  stringstream strStream(s);
  strStream >> x;

  // cout << "\nHello World\n"; //<< endl;
  // cout << "\n x+ 1 =" << (x + 1) << endl;
  // cout << format("\nHi Faraz Alam Lucky number is {}\n", 30);
  x = 1;
  cout << format("\ncheckresult = {}\n", x++ + ++x);
  x = 1;
  cout << format("\ncheckresult = {}\n", x++ + x++);
  x = 1;
  cout << format("\ncheckresult = {}\n", ++x + ++x);
  x = 1;
  cout << format("\ncheckresult = {}\n", ++x + x++);
  return 0;
}
