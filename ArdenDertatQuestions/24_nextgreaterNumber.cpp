/*
 *
 * Programming Interview Questions 24: Find Next Higher Number With Same Digits
Posted on January 2, 2012 by Arden
Given a number, find the next higher number using only the digits in the given
number. For example if the given number is 1234, next higher number with same
digits is 1243.


The naive approach is to generate the numbers with all digit permutations and
sort them. Then find the given number in the sorted sequence and return the next
number in sorted order as a result. The complexity of this approach is pretty
high though, because of the permutation step involved. A given number N has
logN+1 digits, so there are O(logN!) permutations. After generating the
permutations, sorting them will require O(logN!loglogN!) operations. We can
simplify this further, remember that O(logN!) is equivalent to O(NlogN). And
O(loglogN!) is O(logN). So, the complexity is O(N(logN)^2).





Following are few observations about the next greater number.
1) If all digits sorted in descending order, then output is always “Not
Possible”. For example, 4321. 2) If all digits are sorted in ascending order,
then we need to swap last two digits. For example, 1234. 3) For other cases, we
need to process the number from rightmost side (why? because we need to find the
smallest of all greater numbers)

You can now try developing an algorithm yourself.

Following is the algorithm for finding the next greater number.
I) Traverse the given number from rightmost digit, keep traversing till you find
a digit which is smaller than the previously traversed digit. For example, if
the input number is “534976”, we stop at 4 because 4 is smaller than next
digit 9. If we do not find such a digit, then output is “Not Possible”.



II) Now search the right side of above found digit ‘d’ for the smallest digit
greater than ‘d’. For “534976?, the right side of 4 contains “976”. The smallest
digit greater than 4 is 6.

III) Swap the above found two digits, we get 536974 in above example.

IV) Now sort all digits from position next to ‘d’ to the end of number. The
number that we get after sorting is the output. For above example, we sort
digits in bold 536974. We get “536479” which is the next greater number for
input 534976.

Following are the implementation of above approach.


 */

#include <bits/stdc++.h>
using namespace std;

string nextGreaterNumber(string& a) {
  int n = a.length();
  int pivot;
  int i;
  for (i = n - 1; i >= 0; --i) {
    if (a[i] > a[i - 1]) {
      pivot = i;
      break;
    }
  }
  if (i == 0) {
    cout << "\nnumber not possible\n" << endl;
    return "NOt possible";
  }

  char pivotkeleft = a[pivot - 1];
  int smallest = pivot;
  for (int j = pivot + 1; j < n; ++j) {
    if (pivotkeleft < a[j] && a[j] < a[smallest]) {
      smallest = j;
    }
  }
  char temp = a[pivot];
  a[pivot] = a[smallest];
  a[smallest] = temp;

  //  char* tosort = &a[i];
  sort(&a[i], &a[n]);
  //  sort(a + i, a + n);

  return a;
}

int main() {
  string a = "536479";
  cout << "\n\n\n\n" << nextGreaterNumber(a) << endl;

  //
  return 0;
}
