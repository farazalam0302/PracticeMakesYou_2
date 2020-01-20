/*

Egg Dropping PuzzleSubmissions: 27538   Accuracy: 41.45%   Difficulty: Medium  
Marks: 4 Associated Course(s):   Must Do Interview Preparation

Problems
Suppose you have N eggs and you want to determine from which floor in a K-floor
building you can drop an egg such that it doesn't break. You have to determine
the minimum number of attempts you need in order find the critical floor in the
worst case while using the best strategy.There are few rules given below.

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor
below. If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the
T lines contains two positive integer N and K where 'N' is the number of eggs
and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum
number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
3

** For More Input/Output Examples Use 'Expected Output' option **
Author: abhiraj26

*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int eggs, floors;
  cin >> eggs, cin >> floors;

  vector<vector<int>> dropDP(eggs + 1, vector<int>(floors + 1, 0));

  for (int i = 0; i <= eggs; i++) {
    dropDP[i][0] = 0;
    dropDP[i][1] = 1;
  }
  for (int i = 0; i <= floors; i++) {
    dropDP[0][i] = 0;
    dropDP[1][i] = i;
  }

  // printing dp array
  cout << "\n\nfL-> ";
  for (int j = 0; j <= floors; j++) {
    cout << j << " ";
  }
  cout << endl;

  for (int i = 0; i <= eggs; i++) {
    cout << i << " -> ";
    for (int j = 0; j <= floors; j++) {
      cout << dropDP[i][j] << " ";
    }
    cout << endl;
  }

  // printing dp array

  cout << "\n\n after dp populates \n\n" << endl;

  int res;
  for (int i = 2; i <= eggs; i++) {
    for (int j = 2; j <= floors; j++) {
      dropDP[i][j] = INT_MAX;
      for (int k = 1; k <= j; k++) {
        res = 1 + max(dropDP[i - 1][k - 1], dropDP[i][j - k]);
        dropDP[i][j] = min(dropDP[i][j], res);
      }
    }
  }

  // printing dp array
  cout << "\n\nfL-> ";
  for (int j = 0; j <= floors; j++) {
    cout << j << " ";
  }
  cout << endl;

  for (int i = 0; i <= eggs; i++) {
    cout << i << " -> ";
    for (int j = 0; j <= floors; j++) {
      cout << dropDP[i][j] << " ";
    }
    cout << endl;
  }

  // printing dp array

  cout << " answer  = " << dropDP[eggs][floors] << endl;

  return 0;
}
