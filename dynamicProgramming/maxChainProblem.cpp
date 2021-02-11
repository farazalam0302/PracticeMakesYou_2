/*


Max length chainSubmissions: 22568   Accuracy: 43.55%   Difficulty: Medium  
Marks: 4


Problems
You are given N pairs of numbers. In every pair, the first number is always
smaller than the second number. A pair (c, d) can follow another pair (a, b) if
b < c. Chain of pairs can be formed in this fashion. Your task is to complete
the function maxChainLen which returns an integer denoting the longest chain
which can be formed from a given set of pairs.

Input:
The first line of input contains an integer T denoting the no of test cases then
T test cases follow .Then T test cases follow . The first line of input contains
an integer N denoting the no of pairs . In the next line are 2*N space separated
values denoting N pairs.

Output:
For each test case output will be the length of the longest chain formed.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11

Output
3
1
​
Explanation
(i) the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },the
longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27,
40}, {50, 90}} (ii) The max length chain possible is only of length one.


Note:The Input/Ouput format and Example given are used for system's internal
purpose, and should be used by a user for Expected Output only. As it is a
function problem, hence a user should not read any input from stdin/console. The
task is to complete the function specified, and not to write the full code.

** For More Input/Output Examples Use 'Expected Output' option **


*/

#include <bits/stdc++.h>
using namespace std;

bool mycompare(pair<int, int>& l, pair<int, int>& r) {
  return l.second < r.second;
}

int maxPairChainDP(vector<pair<int, int>>& a) {
  int aSize = a.size();
  sort(a.begin(), a.end(), mycompare);
  vector<int> LIS(aSize, 1);
  for (int i = 1; i < aSize; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j].second < a[i].first) {
        if (LIS[i] <= LIS[j] + 1) {
          LIS[i] = LIS[j] + 1;
        }
      }
    }
  }
  int maxlen = LIS[0];
  for (int i = 1; i < aSize; ++i) {
    maxlen = max(maxlen, LIS[i]);
  }
  return maxlen;
}

/*
 * Maximum Length Chain of Pairs | Set-2
Difficulty Level : Medium
 Last Updated : 07 Dec, 2020
Given an array of pairs of numbers of size N. In every pair, the first number is
always smaller than the second number. A pair (c, d) can follow another pair (a,
b) if b < c. The chain of pairs can be formed in this fashion. The task is to
find the length of the longest chain which can be formed from a given set of
pairs.

Examples:

Input: N = 5, arr={{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }
Output: 3
The longest chain that can be formed is of length 3, and the chain is {{5, 24},
{27, 40}, {50, 90}}.

Input : N = 2, arr={{5, 10}, {1, 11}}
Output :1

Recommended: Please try your approach on {IDE} first, before moving on to the
solution. Approach: A dynamic programming approach for the problem has been
discussed here. Idea is to solve the problem using the greedy approach which is
the same as Activity Selection Problem.



Sort all pairs in increasing order of second number of each pair.
Select first no as the first pair of chain and set a variable s(say) with the
second value of the first pair. Iterate from the second pair to last pair of the
array and if the value of the first element of the current pair is greater then
previously selected pair then select the current pair and update the value of
maximum length and variable s. Return the value of Max length of chain. Below is
the implementation of the above approach.
 */

int maxPairChainGreedy(vector<pair<int, int>>& a) {
  int aSize = a.size();
  sort(a.begin(), a.end(), mycompare);
  int maxChainLen = 1;
  int maxSecondSoFar = a[0].second;
  for (int i = 1; i < aSize; ++i) {
    if (a[i].first > maxSecondSoFar) {
      maxSecondSoFar = a[i].second;
      maxChainLen++;
    }
  }
  return maxChainLen;
}

int main(int argc, const char** argv) {
  vector<int> a{5, 24, 39, 13, 15, 12, 27, 11, 50, 10};
  vector<pair<int, int>> b;
  for (int i = 0; i < a.size(); i = i + 2) {
    b.push_back({a[i], a[i + 1]});
  }
  int result = maxPairChainDP(b);
  cout << "\n\nresult DP = " << result << endl;

  result = maxPairChainGreedy(b);
  cout << "\n\nresult Greedy = " << result << endl;

  return 0;
}
