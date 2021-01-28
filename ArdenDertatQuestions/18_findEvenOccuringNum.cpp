

/*
 * http://www.ardendertat.com/2011/11/29/programming-interview-questions-18-find-even-occurring-element/
 *
 *
 * Programming Interview Questions 18: Find Even Occurring Element
Posted on November 29, 2011 by Arden
Given an integer array, one element occurs even number of times and all others
have odd occurrences. Find the element with even occurrences.


We can use a hashtable as we always do with problems that involve counting. Scan
the array and count the occurrences of each number. Then perform a second pass
from the hashtable and return the element with even count. Here’s the code:
 * */

#include <bits/stdc++.h>
using namespace std;

int main() {  //

  vector<int> a{1, 1, 1, 2, 2, 2, 3, 3};
  int xnorSum = 0;
  for (int i = 0; i < a.size(); ++i) {
    xnorSum = ~(xnorSum ^ a[i]);
  }

  cout << "\n\n evenfrequencyNumber = " << xnorSum << endl;

  return 0;
}
