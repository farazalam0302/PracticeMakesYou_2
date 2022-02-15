#include <bits/stdc++.h>
using namespace std;

int main() {
  bitset<20> bs1;
  bitset<20> bs2(0x7f);
  bitset<20> bs3(("1100"));
  string a = "101010";
  bitset<20> bs4(a);
  cout << "\n bs1 = " << bs1 << endl;
  cout << "\n bs2 = " << bs2 << endl;
  cout << "\n bs3 = " << bs3 << endl;
  cout << "\n bs4 = " << bs4 << endl;
  cout << "\n bs3 & bs4 = " << (bs3 & bs4) << endl;
  cout << "\n bs3 | bs4 = " << (bs3 | bs4) << endl;
  cout << "\n set bits in bs1.count() =  " << (bs1.count()) << endl;
  cout << "\n set bits in bs2.count() =  " << (bs2.count()) << endl;
  cout << "\n unset bits in bs1.count() =  " << (bs1.size() - bs1.count())
       << endl;
  cout << "\n unset bits in bs2.count() =  " << (bs2.size() - bs2.count())
       << endl;
  // test function return 1 if bit is set else returns 0
  cout << "bool representation of " << bs4 << " : ";
  for (int i = 0; i < bs4.size(); i++) cout << bs4.test(i) << " ";
  cout << endl;
  cout << "\n  bs1.any() =  " << (bs1.any()) << endl;
  cout << "\n  bs3.any() =  " << (bs3.any()) << endl;
  cout << "\n  bs1.none() =  " << (bs1.none()) << endl;
  cout << "\n  bs3.none() =  " << (bs3.none()) << endl;
  cout << "\n  bs1.set() =  " << (bs1.set()) << endl;
  cout << "\n  bs1 = " << bs1 << endl;
  cout << "\n  bs1.reset() =  " << (bs1.reset()) << endl;
  cout << "\n  bs1.set(3,1) =  " << (bs1.set(3, 1)) << endl;
  cout << "\n  bs1.set( ) =  " << (bs1.set()) << endl;
  cout << "\n  bs1.reset(3) =  " << (bs1.reset(3)) << endl;
  cout << "\n  bs1.reset() =  " << (bs1.reset()) << endl;
  cout << "\n  bs1.flip() =  " << (bs1.flip()) << endl;
  cout << "\n  bs1.flip() =  " << (bs1.flip()) << endl;
  cout << "\n  bs1.flip(3) =  " << (bs1.flip(3)) << endl;

  int x = 0x7f7f7f7f;
  cout << "\n Decimal Number = " << hex << x
       << " \n Binary no. = " << (bitset<32>(x)) << endl;

  return 0;
}
