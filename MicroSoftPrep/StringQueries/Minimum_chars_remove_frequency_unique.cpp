/*
 * Minimum characters required to be removed to make frequency of each character
unique Difficulty Level : Easy Last Updated : 24 Jun, 2021 Given string str, the
task is to find the minimum count of characters that need to be deleted from the
string such that the frequency of each character of the string is unique.

Examples:

Input: str = “ceabaacb”
Output: 2
Explanation:
The frequencies of each distinct character are as follows:
c —> 2
e —> 1
a —> 3
b —> 2
Possible ways to make frequency of each character unique by minimum number of
moves are:

Removing both occurrences of ‘c’ modifies str to “eabaab”
Removing an occurrence of ‘c’ and ‘e’ modifies str to “abaacb”
Therefore, the minimum removals required is 2.

Input: S = “abbbcccd”
Output: 2


Recommended: Please try your approach on {IDE} first, before moving on to the
solution. Approach: The problem can be solved using Greedy technique. The idea
is to use Map and Priority Queue. Follow the steps below to solve the problem:

Initialize a Map, say mp, to store the frequency of each distinct character of
the string. Initialize a variable, say cntChar to store the count of characters
required to be removed to make frequency of each character of the string unique.
Create a priority_queue, say pq to store the frequency of each character such
that the largest frequency obtained is present at the top of the priority queue
pq. Iterate over the priority_queue until pq is empty and check if the topmost
of element of pq is equal to the second topmost element of pq or not. If found
to be true, then decrement the value of topmost element of pq by 1 and increment
the value of cntChar by 1. Otherwise, pop the topmost element of pq. Finally,
print the value of cntChar.
 */

#include <bits/stdc++.h>
using namespace std;

int minRemovals(string& input) {
  int len = input.length();
  if (len == 1) return 0;
  if (len == 0) return -1;

  unordered_map<char, int> mmap;
  priority_queue<int> pq;

  for (auto i : input) {
    mmap[i]++;
  }
  for (auto i : mmap) {
    pq.push(i.second);
  }
  int cntRemovals = 0;
  int mostfrequent;
  while (!pq.empty()) {
    mostfrequent = pq.top();
    pq.pop();
    if (pq.empty()) return cntRemovals;
    if (mostfrequent == pq.top()) {
      if (mostfrequent > 1) pq.push(mostfrequent - 1);
      cntRemovals++;
    }
  }
  return cntRemovals;
}

int main() {
  //
  string in1 = "ceabaacb";
  string in2 = "abbbcccd";

  cout << "\n minimum number of removals of chars for " << in1 << " = "
       << minRemovals(in1) << endl;

  cout << "\n minimum number of removals of chars for " << in2 << " = "
       << minRemovals(in2) << endl;
  return 0;
}
