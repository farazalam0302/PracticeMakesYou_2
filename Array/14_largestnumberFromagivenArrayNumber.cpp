/*

refrence link :-
https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0

Given a list of non negative integers, arrange them in such a manner that they
form the largest number possible.The result is going to be very large, hence
return the result in the form of a string.

Input:
The first line of input consists number of the test cases. The description of T
test cases is as follows: The first line of each test case contains the size of
the array, and the second line has the elements of the array.

Output:
In each separate line print the largest number formed by arranging the elements
of the array in the form of a string.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 102
0 ≤ A[i] ≤ 103

Example:
Input:
2
5
3 30 34 5 9
4
54 546 548 60

Output:
9534330
6054854654

** For More Input/Output Examples Use 'Expected Output' option **

*/

#include <bits/stdc++.h>
using namespace std;
bool mycomp(string a, string b) {

  if ((a + b).compare(b + a) > 0)
    return true;
  else
    return false;
}

class LargestNumberString {
public:
  string largestNumber(vector<int> &a) {
    vector<string> s;
    for (auto i : a) {
      string tmp = "" + to_string(i);
      s.push_back(tmp);
    }
    int k = 1;
    sort(s.begin(), s.end(), mycomp);
    string ret = "";
    for (auto i : s) {
      ret = ret + i;
    }

    return ret;
  }
};

int main() {
  int t;
  cin >> t;
  //   t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x);
    }
    LargestNumberString lnr;
    cout << lnr.largestNumber(a) << endl;
  }
  return 0;
}