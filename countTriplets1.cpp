/*

Given an array of distinct integers. The task is to count all the triplets such
that sum of two elements equals the third element.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines. First line of
each test case contains an Integer N denoting size of array and the second line
contains N space separated elements.

Output:
For each test case, print the count of all triplets, in new line. If no such
triplets can form, print "-1".

Constraints:
1 <= T <= 100
3 <= N <= 105
1 <= A[i] <= 106

Example:
Input:
2
4
1 5 3 2
3
3 2 7
Output:
2
-1

Explanation:
Testcase 1: There are 2 triplets: 1 + 2 = 3 and 3 +2 = 5

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
using namespace std;
class CountTriplets {
public:
  int retreiveFromMap(unordered_map<int, int> &mm, int key) {
    if (mm.find(key) == mm.end())
      return 0;
    else
      return mm[key];
  }
  int countTriplets(vector<int> &A) {
    int n = A.size();

    unordered_map<int, int> mmap;
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (mmap.find(A[i]) == mmap.end()) {
        mmap[A[i]] = 1;
      } else {
        mmap[A[i]] = mmap[A[i]] + 1;
      }
      maximum = max(maximum, A[i]);
    }
    int ans = 0;

    // case 1  :  0 + 0 = 0  ; ans = n(0)C3
    int n0 = retreiveFromMap(mmap, 0);
    ans += n0 * (n0 - 1) * (n0 - 2) / 6;

    // case 2 : 0 + x = x ; ans = n(0) * n(x)C2
    for (int i = 1; i <= maximum; i++) {
      int nx = retreiveFromMap(mmap, i);
      ans += n0 * nx * (nx - 1) / 2;
    }
    // case 3 :  x + x = 2x ; ans = nxC2 * n(2x)
    for (int i = 1; i <= maximum; i++) {

      int nx = retreiveFromMap(mmap, i);
      int n2x = retreiveFromMap(mmap, i + i);
      ans += nx * (nx - 1) * n2x / 2;
    }

    // case 4 : x + y = z ; ans = nx * ny * n(x+y);

    for (int i = 1; i <= maximum; i++) {
      int nx = retreiveFromMap(mmap, i);
      for (int j = i + 1; i + j <= maximum; j++) {
        int ny = retreiveFromMap(mmap, j);
        int nxy = retreiveFromMap(mmap, j + i);

        ans += nx * ny * nxy;
      }
    }
    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  int k, n;
  while (t--) {
    // cout << "Enter N ?" << endl;
    cin >> n;
    // cout << "Enter sum ?? \n " << endl;
    // cin >> k;
    vector<int> a;
    int temp;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      a.push_back(temp);
    }

    CountTriplets ss;

    int ret = ss.countTriplets(a);

    cout << "Answer = " << ret << endl;

    // for (auto i : ret) {
    //   cout << i << " ";
    // }
    cout << endl;
  }

  return 0;
}
