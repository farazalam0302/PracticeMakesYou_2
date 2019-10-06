/*
link :
https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0/


Problems
Given a sorted array of positive integers. Your task is to rearrange  the array
elements alternatively i.e first element should be max value, second should be
min value, third should be second max, fourth should be second min and so on...

Note: O(1) extra space is allowed. Also, try to modify the input array as
required.

Input:
First line of input conatins number of test cases T. First line of test case
contain an integer denoting the array size N and second line of test case
contain N space separated integers denoting the array elements.

Output:
Output the modified array with alternated elements.

Constraints:
1 <=T<= 100
1 <=N<= 107
1 <=arr[i]<= 107

Example:
Input:
2
6
1 2 3 4 5 6
11
10 20 30 40 50 60 70 80 90 100 110

Output:
6 1 5 2 4 3
110 10 100 20 90 30 80 40 70 50 60

Explanation:
Testcase 1: Max element = 6, min = 1, second max = 5, second min = 2, and so
on... Modified array is : 6 1 5 2 4 3.
 



** For More Input/Output Examples Use 'Expected Output' option **
Author: atharv


*/
#include <bits/stdc++.h>
using namespace std;
class ReArrangeItem {
public:
  void reArrange(vector<long long int> &a) {
    int n = a.size();
    if (n == 0)
      return;
    vector<int> ret;
    int max_index = n - 1;
    int min_index = 0;
    int maximum = a[max_index] + 1;
    for (int i = 0; i < n; i++) {
      if ((i % 2 == 0)) {
        a[i] = a[i] + (a[max_index] % maximum) * maximum;

        max_index--;
      } else {
        a[i] = a[i] + (a[min_index] % maximum) * maximum;
        min_index++;
      }
      //   a[i] = a[i] * maximum;
    }
    for (int i = 0; i < n; i++) {
      a[i] = a[i] / maximum;
    }

    return;
  }
}

;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long int> a;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    ReArrangeItem la;
    la.reArrange(a);
    for (auto i = a.begin(); i != a.end(); i++) {
      cout << *i << " ";
    }
    cout << endl;
  }

  return 0;
}