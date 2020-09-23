
// priority_queue::emplace
#include <bits/stdc++.h>
using namespace std;

#include <typeinfo>
#if 0


int main() {
  std::priority_queue<int, vector<int>, greater<int>> mypq;

  mypq.emplace(1);
  mypq.emplace(2);
  mypq.emplace(3);
  mypq.emplace(4);

  std::cout << "mypq contains:";
  while (!mypq.empty()) {
    std::cout << ' ' << mypq.top();
    mypq.pop();
  }
  std::cout << '\n';

  return 0;
}
#endif

#if 0
int main() {
  int a[] = {1, 2, 3, 4, 5};
  int len = *(&a + 1) - a;
  cout << "&a = " << hex << (&a) << '\n';
  cout << "&a+1 = " << hex << (&a + 1) << '\n';
  cout << "a = " << hex << (a) << '\n';
  cout << "\nlen = " << len << '\n';

  int b[3][2] = {{1, 2}, {4, 5}, {7, 8}};
  int rows = *(&b + 1) - b;
  int cols = *(&b[0] + 1) - b[0];
  ;
  cout << "&b = " << hex << (&b) << '\n';
  cout << "&b+1 = " << hex << (&b + 1) << '\n';
  cout << "b = " << hex << (b) << '\n';

  cout << "typeid(&b).name() = " << typeid(&b).name() << '\n';
  cout << "typeid(&b[0]).name() = " << typeid(&b[0]).name() << '\n';
  //  cout << "b = " << hex << (b) << '\n';
  cout << "\nrows = " << rows << '\n';

  cout << "\ncols = " << cols << '\n';

  return 0;
}

#endif

#if 0
#include <typeinfo>
//#include <iostream>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};

  std::cout << typeid(&arr).name() << "\n";
  std::cout << typeid(&arr[0]).name() << "\n";
  std::cout << &arr << " " << &arr + 1;
}
#endif

#if 1

int main() {
  int aa[4] = {10, 20, 30, 40};
  int *p = aa;
  int *q = aa + 2;
  cout << "\np = " << *p << endl;
  cout << "\nq = " << *q << endl;
  cout << "\n *p++ =  " << *p++ << endl;
  cout << "\n *++q = " << *++q << endl;
  cout << "\np = " << *p << endl;
  cout << "\nq = " << *q << endl;
  //(*p)++;
  //++(*q); cout << "\np = " << *p << endl;
  // cout << "\nq = " << *q << endl;
  int a = 10;
  int b = 20;
  int res = a++ + a++;
  cout << "\n a = " << a << endl;
  cout << "\n res = " << res << endl;

  res = ++a + ++a;
  cout << "\n a = " << a << endl;
  cout << "\n res = " << res << endl;
}

#endif
