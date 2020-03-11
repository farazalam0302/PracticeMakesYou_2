/*
 * Place even numbers at even indexes and odd numbers at odd indexes, given that
the number of odd numbers may or may not be equal to the number of even numbers.
Extra odd/even number should be placed at the end of the array. Example Input :
arr[] = {3, 6, 12, 1, 5, 8} Output : 6 3 12 1 8 5

Input : arr[] = {10, 9, 7, 18, 12, 19, 4, 20, 6, 14}
Output : 10 9 18 7 20 19 4 12 14 6
For an equal number of odd numbers and even numbers –
even-numbers-even-index-odd-numbers-odd-index
 *
 * */

#include <bits/stdc++.h>
using namespace std;

void parityWiseOrdering(vector<int> &a) {
  cout << "\nbeforeSort" << endl;
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;

  int sz = a.size();
  int even = 0;
  int odd = 1;
  for (int i = 0; i < sz; ++i) {
    if (even >= sz || odd >= sz) break;
    if (a[i] % 2 == 0)  // a[i] is even
    {
      if (i % 2 == 1)  // position is odd
      {
        swap(a[i], a[even]);
        even += 2;
      }
    }
    if (a[i] % 2 == 1)  // a[i] is odd
    {
      if (i % 2 == 0)  // position is even
      {
        swap(a[i], a[odd]);
        odd += 2;
      }
    }
  }
  cout << "\nAfter Sort" << endl;
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
}

int main(int argc, char **argv) {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  parityWiseOrdering(a);

  return 0;
}
