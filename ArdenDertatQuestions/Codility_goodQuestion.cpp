/*
You are given a string S consisting of N lowercase letters. In one move you can
remove any substring (consistent fragment) from S, which starts and ends with
the same letter and is at least two letters long. What is the minimum number of
letters that may remain in S after any number of such moves?

Write a function:

int solution(string &S);

that, given a string S, returns the length of the shortest string that can be
obtained from S by applying any number of moves as described above.

Examples:

1. Given S = "abccac", the function should return 1. After removing the
substring "abcca", there will be a single letter "c" remaining.

2. Given S = "abcdabcdabcd" ("abcd" stated three times), the function should
return 2. To achieve that, you can, for example, remove the first five letters
from S ("abcda") in the first move, and the last five letters ("dabcd") in the
second move. The remaining fragment would be "bc".

3. Given S = "axaabyab", the function should return 0. It is possible to remove
all letters by removing the substring "axaa" in the first move, and then "byab"
in the second.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
string S consists only of lowercase letters (a−z).
*/

#include <bits/stdc++.h>
using namespace std;
int getMinimumLeftAfterRemove(string& a) {
  int n = a.size();
  if (n < 2) return -1;
  stack<char> myStack;
  //  unordered_map<char, int> mmap;
  myStack.push(a[0]);
  bool mmap[256] = {0};
  mmap[a[0]] = 1;
  char topp;
  for (int i = 1; i < n; ++i) {
    if (mmap[a[i]]) {
      topp = myStack.top();
      while (!myStack.empty() && a[i] != topp) {
        myStack.pop();
        mmap[topp] = false;
        topp = myStack.top();
      }
      if (topp == a[i]) {
        myStack.pop();

        mmap[topp] = false;
      }
    } else {
      myStack.push(a[i]);
      mmap[a[i]] = true;
    }
  }
  int minSiz = 0;
  while (!myStack.empty()) {
    minSiz++;
    myStack.pop();
  }

  for (auto i : a) {
    mmap[i] = false;
  }
  myStack.push(a[n - 1]);
  mmap[a[n - 1]] = true;

  for (int i = n - 2; i >= 0; --i) {
    if (mmap[a[i]]) {
      topp = myStack.top();
      while (!myStack.empty() && a[i] != topp) {
        myStack.pop();
        mmap[topp] = false;
        topp = myStack.top();
      }
      if (topp == a[i]) {
        myStack.pop();

        mmap[topp] = false;
      }
    } else {
      myStack.push(a[i]);
      mmap[a[i]] = true;
    }
  }

  int sz = 0;
  while (!myStack.empty()) {
    sz++;
    myStack.pop();
  }

  return (min(minSiz, sz));
}

int main() {  //

  string s1 = "abccac";
  string s2 = "abcdabcdabcd";
  string s3 = "axaabyab";

  int res;

  res = getMinimumLeftAfterRemove(s1);

  cout << "Result = " << res << endl;
  res = getMinimumLeftAfterRemove(s2);

  cout << "Result = " << res << endl;
  res = getMinimumLeftAfterRemove(s3);

  cout << "Result = " << res << endl;

  return 0;
}
