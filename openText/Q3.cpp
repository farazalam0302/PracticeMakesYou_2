/*
 * Given a string s, sort it in decreasing order based on the frequency of the
characters. The frequency of a character is the number of times it appears in
the string.

Return the sorted string. If there are multiple answers, return any of them.

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
answer. Example 2:



Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc"
are valid answers. Note that "cacaca" is incorrect, as the same characters must
be together. Example 3:


Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 */
#include <bits/stdc++.h>
using namespace std;

bool mycompare(pair<char, int> &left, pair<char, int> &right) {
  return (left.second > right.second);
}

int main(int argc, char **argv) {
  string inp = "tree";
  int n = inp.size();

  unordered_map<char, int> mmap;
  for (int i = 0; i < n; ++i) {
    mmap[inp[i]]++;
  }
  vector<pair<char, int>> a;
  // first scan
  for (auto i : mmap) {
    a.push_back({i.first, i.second});
  }
  sort(a.begin(), a.end(), mycompare);
  int nA = a.size();
  for (int i = 0; i < nA; i++) {
    for (int j = 0; j < a[i].second; j++) {
      cout << a[i].first;
    }
  }
  cout << endl;
  return 0;
}
