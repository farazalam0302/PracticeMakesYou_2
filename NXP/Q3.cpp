// textsection/code section ) Static
//
/// bss
//
// stack
//
// heap
//
// copy constru
//
// class X {
//  int a1;
//  int *a2;
//
// public:
//  X(X &obj) {
//    this->a1 = obj.a1;
//    this->a2 = new int;
//    *a2 = *(obj.a2);
//  }
//};
//
// obJ1, obj2
//
//          obj1 = obj2
//

// stl map <string -> structure (int a1, int *a2)>
// m1 and m2
//
//#include <bits/stdc++.h>
// using namespace std;
//
// class X {
// public:
//  int a1;
//  int *a2;
//  X() {
//    a1 = 0;
//    a2 = nullptr;
//  }
//};

#include <bits/stdc++.h>
using namespace std;

class myStruct {
public:
  int x;
  int *p;
  myStruct() {
    x = 0;
    p = NULL;
  }
  myStruct(int c) {
    x = c;
    p = new int(c * 10);
  }
  myStruct(myStruct &m) {
    x = m.x;
    p = new int(*(m.p));
  }

  void display() {
    cout << "Val X = " << x << endl;
    cout << "Val at P = " << *p << endl;
    cout << "P addr = " << p << endl;
  }
};

int main(int argc, char **argv) {
  map<int, myStruct> m1;
  map<int, myStruct> m2;

  for (int i = 1; i <= 5; i++) {
    myStruct tmp(i);
    m1[i] = tmp;
  }

  for (auto &i : m1) {
    m2.insert
  }

  return 0;
}
