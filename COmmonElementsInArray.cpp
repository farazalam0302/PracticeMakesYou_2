/*
 * Given three increasingly sorted arrays A, B, C of sizes N1, N2, and N3
respectively, you need to print all common elements in these arrays.

Note: Please avoid printing the same common element more than once.

Input:
First line contains a single integer T denoting the total number of test cases.
T testcases follow. Each testcase contains four lines of input. First line
consists of 3 integers N1, N2 and N3, denoting the sizes of arrays A, B, C
respectively. The second line contains N1 elements of A array. The third lines
contains N2 elements of B array. The fourth lines contains N3 elements of C
array.

Output:
For each testcase, print the common elements of array. If not possible then
print -1.

Constraints:
1 <= T <= 100
1 <= N1, N2, N3 <= 107
1 <= Ai, Bi, Ci <= 1018

Example:
Input:
1
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
Output:
20 80

Explanation:
Testcase1:  20 and 80 are the only common elements

** For More Input/Output Examples Use 'Expected Output' option **
 * */

#include <bits/stdc++.h>
using namespace std;
class CommonElementsInArray {
public:
  vector<int> commonsInABC(vector<int> &a, vector<int> &b, vector<int> &c) {
    vector<int> ret;
    int na, nb, nc;
    na = a.size();
    nb = b.size();
    nc = c.size();
    map<int, int> mapp;
    for (auto i : a) {
      mapp[i] = 0;
    }
    for (auto i : b) {
      if (mapp.find(i) != mapp.end())
        mapp[i] = 1;
    }
    for (auto i : c) {
      if (mapp.find(i) != mapp.end()) {
        if (mapp[i] == 1)
          ret.push_back(i);
      }
    }
    return ret;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int na, nb, nc, x;
    cin >> na >> nb >> nc;
    vector<int> a, b, c;
    for (int i = 0; i < na; i++) {
      cin >> x;
      a.push_back(x);
    }
    for (int i = 0; i < nb; i++) {
      cin >> x;
      b.push_back(x);
    }
    for (int i = 0; i < nc; i++) {
      cin >> x;
      c.push_back(x);
    }
    CommonElementsInArray ae;
    vector<int> ret = ae.commonsInABC(a, b, c);
    for (auto i : ret) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}