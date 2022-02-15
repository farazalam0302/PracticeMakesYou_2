#include <bits/stdc++.h>
using namespace std;
/*
 * Functional pointers in C/Cpp
 *
 * Syntax of function pointer

return type (*ptr_name)(type1, type2…);

int (*ip) (int);
In the above declaration, *ip is a pointer that points to a function which
returns an int value and accepts an integer value as an argument.


*
 */

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int add3Num(int (*fPtr)(int, int), int a, int b, int c) {
  int r = (*fPtr)(a, b);

  return (r + c);
}

void func1(void (*fPtr)()) {
  cout << "in func1\n" << endl;
  (*fPtr)();
}

void func2() { cout << "in func2\n" << endl; }

int main() {
  int a = 100;
  int b = 20;
  int (*fp[4])(int, int);
  fp[0] = add;
  fp[1] = sub;
  fp[2] = mul;
  fp[3] = divide;

  cout << "sum  = " << (*fp[0])(a, b) << endl;
  cout << "sub  = " << (*fp[1])(a, b) << endl;
  cout << "mul  = " << (*fp[2])(a, b) << endl;
  cout << "div  = " << (*fp[3])(a, b) << endl;

  /*
  int c = 30;
  int (*fPtr)(int, int);
  fPtr = add;

  cout << (*fPtr)(a, b) << endl;

  cout << add3Num(fPtr, a, b, c) << endl;

  func1(func2);
*/
  return 0;
}
