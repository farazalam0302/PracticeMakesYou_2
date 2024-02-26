/*
mystring s1 = "Faraz";
{
  mystring s2 = s1;
}
s1 = "Alam";
s1[0] = 'a';
*/
#include <bits/stdc++.h>
using namespace std;

class mystring {
public:
  char *buf;
  int capacity;
  //   mystring(int n) { buf = new char[n]; }
  mystring(mystring &a) {
    capacity = strlen(a.buf);
    buf = new char[capacity];
    for (size_t i = 0; i < capacity; i++) {
      buf[i] = a.buf[i];
    }
  }

  mystring operator=(mystring a) {
    capacity = strlen(a.buf);
    buf = new char[capacity];
    for (size_t i = 0; i < capacity; i++) {
      buf[i] = a.buf[i];
    }
    return this;
  }

  void printMyString() {
    for (size_t i = 0; i < capacity; i++) {
      cout << buf[i];
    }
  }
};

int main(int argc, char const *argv[]) {
  mystring test = "Faraz";
  test.printMyString();

  return 0;
}
