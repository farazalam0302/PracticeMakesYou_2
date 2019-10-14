/*

problem link  :
https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0


Convert array into Zig-Zag fashionSubmissions: 17535   Accuracy: 50.11%  
Difficulty: Basic   Marks: 1
        


Problems
Given an array A (distinct elements) of size N. Rearrange the elements of array
in zig-zag fashion. The converted array should be in form a < b > c < d > e < f.
The relative order of elements is same in the output i.e you have to iterate on
the original array only.

Input:
The first line of input contains an integer T denoting the number of test cases.
T testcases follow. Each testcase contains two lines of input. The first line
contains a single integer N denoting the size of array. The second line contains
N space-separated integers denoting the elements of the array.

Output:
For each testcase, print the array in Zig-Zag fashion.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= Ai <= 10000

Example:
Input:
2
7
4 3 7 8 6 2 1
4
1 4 3 2
Output:
3 7 4 8 2 6 1
1 4 2 3

** For More Input/Output Examples Use 'Expected Output' option **
*/
#include <bits/stdc++.h>
using namespace std;
class ZigZag {
public:
  vector<int> zigZag1(vector<int> &a) {
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size() - 1; i += 2) {
      swap(a[i], a[i + 1]);
    }
    return a;
  }

  vector<int> zigZagO_n(vector<int> &a) {
    bool flag = true;
    for (int i = 0; i < a.size() - 1; i++) {
      if (flag) {
        if (a[i] > a[i + 1])
          swap(a[i], a[i + 1]);
        flag = false;
      } else {
        if (a[i] < a[i + 1])
          swap(a[i], a[i + 1]);
        flag = true;
      }
    }
    return a;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    ZigZag zg;
    vector<int> ret = zg.zigZagO_n(a);
    for (auto i : ret)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
