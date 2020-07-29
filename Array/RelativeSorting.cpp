/*

reference link
https://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/

Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort
A1 in such a way that the relative order among the elements will be same as
those in A2. For the elements not present in A2, append them at last in sorted
order. It is also given that the number of elements in A2[] are smaller than or
equal to number of elements in A1[] and A2[] has all distinct elements.

Note: Expected time complexity is O(N log(N)).

Input:
First line of input contains number of testcases. For each testcase, first line
of input contains length of arrays N and M and next two line contains N and M
elements respectively.

Output:
Print the relatively sorted array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N,M  ≤ 106
1 ≤ A1[], A2[] <= 106

Example:
Input:
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3

Output:
2 2 1 1 8 8 3 5 6 7 9

Explanation:
Testcase 1: Array elements of A1[] are sorted according to A1[].
*/
#include <bits/stdc++.h>
using namespace std;

class RelativeSort {
public:
  void relativeSortViaBST_mapSTL(vector<int> &a, vector<int> b) {
    map<int, pair<int, bool>> mmap;
    int na = a.size();
    int nb = b.size();
    for (int i = 0; i < na; i++) {
      if (mmap.find(a[i]) == mmap.end()) {
        mmap[a[i]] = {1, false};
      } else {
        mmap[a[i]].first++;
      }
    }

    for (int i = 0; i < nb; i++) {
      if (mmap.find(b[i]) != mmap.end()) {
        mmap[b[i]].second = true;
        int c = mmap[b[i]].first;
        while (c--) {
          cout << b[i] << " ";
        }
        // mmap.erase(b[i]);

      } else {
        cout << b[i] << " ";
      }
    }
    for (auto i : mmap) {
      if (!i.second.second) {
        int c = i.second.first;
        while (c--)
          cout << i.first << " ";
      }
    }
    cout << endl;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int na, nb;
    cin >> na >> nb;
    int tmp;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < na; i++) {
      cin >> tmp;
      a.push_back(tmp);
    }
    for (int i = 0; i < nb; i++) {
      cin >> tmp;
      b.push_back(tmp);
    }
    RelativeSort rs;
    rs.relativeSortViaBST_mapSTL(a, b);
  }

  return 0;
}