/*
 * You are given a string S consisting of N lowercase letters. In one move you
can remove any substring (consistent fragment) from S, which starts and ends
with the same letter and is at least two letters long. What is the minimum
number of letters that may remain in S after any number of such moves?

Write a function:

class Solution { public int solution(String S); }

that, given a string S, returns the length of the shortest string that can be
obtained from S by applying any number of moves as described above.

Examples:

Given S = "abccac", the function should return 1. After removing the substring
"abcca", there will be a single letter "c" remaining.

Given S = "abcdabcdabcd" ("abcd" stated three times), the function should
return 2. To achieve that, you can, for example, remove the first five letters
from S ("abcda") in the first move, and the last five letters ("dabcd") in the
second move. The remaining fragment would be "bc".

Given S = "axaabyab", the function should return 0. It is possible to remove all
letters by removing the substring "axaa" in the first move, and then "byab" in
the second.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
string S consists only of lowercase letters (a?z).
 */

#include <bits/stdc++.h>
using namespace std;

void removeString(char* a, int n, int* res) {
  if (a == nullptr) return;
  if (n == 0) return;
  int mmap[256];
  for (int i = 0; i < 256; ++i) {
    mmap[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    if (mmap[a[i]] == -1)
      mmap[a[i]] = i;
    else {
      *res = max(*res, *res + (i + 1));
      removeString(a + i + 1, n - i - 1, res);
      return;
    }
  }
}

int main() {
  char* i1 = "abcdabcdabcd";
  char* i2 = "abccac";
  int n;
  int res;
  res = 0;
  n = strlen(i1);
  removeString(i1, n, &res);

  cout << "Result  = " << (n - res) << endl;

  res = 0;
  n = strlen(i2);
  removeString(i2, n, &res);
  res = n - res;
  cout << "Result  = " << res << endl;
  //
  return 0;
}
