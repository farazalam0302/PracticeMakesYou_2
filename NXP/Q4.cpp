//#include <bits/stdc++.h>
// using namespace std;
//
// unsigned int NXP_byteReplace(unsigned int x) {
//  unsigned char *byte = (unsigned char *)(&x);
//  unsigned char tmp = *byte;
//  *byte = *(byte + 3);
//  *(byte + 3) = tmp;
//  tmp = *(byte + 1);
//  *(byte + 1) = *(byte + 2);
//  *(byte + 2) = tmp;
//
//  return x;
//}
//
// int main(int argc, char **argv) {
//
//  unsigned int input = 0x11223344;
//  cout << hex << NXP_byteReplace(input) << endl;
//
//  //  unsigned int a = 10 ;
//  //  unsigned int b = 5;
//  //  cout << a <<", " << b << endl;
//  //  a=a+b;
//  //  b=a-b;
//  //  a=a-b;
//  //  cout << a <<", " << b << endl;
//  //
//  //
//
//  return 0;
//}

// int sum(int a, int b)

// stl map <string -> structure (int a1, int *a2)>
// m1 and m2

#include <bits/stdc++.h>
using namespace std;

class X {
public:
  int a1;
  int *a2;
  X() {
    a1 = 0;
    a2 = nullptr;
  }
};

int main(int argc, char **argv) {

  map<string, &X> m1, m2_exist;

  for (auto i : m2_exist) {
    m1[i.first].a1 = m2_exist[i.first].a1;
    m1[i.first].a2 = m2_exist[i.first].a2;
  }

  return 0;
}
