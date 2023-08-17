/*
 * denomination of coins {1,2,4}
 *
 * Min. no of coins required to get N
 *
 * eg 15
 * 3 4s , 1 2s and  1 1s
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {

  vector<int> deno{1, 4, 5};
  // array of denom is sorted

  int N;
  //  cin >> N;
  cout << "Enter N\n";
  cin >> N;
  int c = N;
  vector<int> ret(deno.size(), 0);
  for (int i = deno.size() - 1; i >= 0; --i) {
    ret[i] = c / deno[i];
    c = c % deno[i];
  }
  cout << "[1, 4, 5]" << endl;
  for (auto i : ret) {

    cout << i << ", ";
  }

  cout << endl;
  //  ;
  //
  //  int c = N;
  //  int f4;
  //  int f2;
  //  int f1;
  //  f4 = c / 4;
  //  c = c % 4;
  //  f2 = c / 2;
  //  c = c % 2;
  //  f1 = c;

  //  cout << "4s = " << f4 << ", 2s = " << f2 << ", 1s  = " << f1 << endl;

  return 0;
}
