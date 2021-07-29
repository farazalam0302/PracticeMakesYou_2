#include <bits/stdc++.h>
using namespace std;

// void fun() { cout << "\nnon parameter fun\n" << endl; }

void fun(int a) { cout << "\n parameter fun(a)\n" << a << endl; }

void fun(int a, int b = 0) {
  cout << "\n parameter fun(a,b=0)\n" << (a + b) << endl;
}

// void fun(int a = 0, int b = 0, int c = 0) {
//  cout << "\n parameter fun(a,b=0,c=0)\n" << (a + b + c) << endl;
//}

int main() {  //

  int a = 10;
  int b = 20;
  int c = 30;

  //  fun();
  fun(a, b);
  return 0;
}
