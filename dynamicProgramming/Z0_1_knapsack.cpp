/*

0 - 1 Knapsack ProblemSubmissions: 68847   Accuracy: 35.71%   Difficulty: Easy  
Marks: 2 Associated Course(s):   Must Do Interview Preparation
                              

Problems
You are given weights and values of N items, put these items in a knapsack of
capacity W to get the maximum total value in the knapsack. Note that we have
only one quantity of each item. In other words, given two integer arrays
val[0..N-1] and wt[0..N-1] which represent values and weights associated with N
items respectively. Also given an integer W which represents knapsack capacity,
find out the maximum value subset of val[] such that sum of the weights of this
subset is smaller than or equal to W. You cannot break an item, either pick the
complete item, or don’t pick it (0-1 property).

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of four lines. The first line
consists of N the number of items. The second line consists of W, the maximum
capacity of the knapsack. In the next line are N space separated positive
integers denoting the values of the N items, and in the fourth line are N space
separated positive integers denoting the weights of the corresponding items.

Output:
For each testcase, in a new line, print the maximum possible value you can get
with the given conditions that you can obtain for each test case in a new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

Example:
Input:
2
3
4
1 2 3
4 5 1
2
3
1 2 3
4 5 6
Output:
3
1

*/

#include <bits/stdc++.h>
#define printMat(x)                                                            \
  for (int i = 0; i < m; i++) {                                                \
    for (int j = 0; j <= n; j++) {                                             \
      cout << x[i][j] << " ";                                                  \
    }                                                                          \
    cout << endl;                                                              \
  }
using namespace std;

int main() {

  int t;
  //   cin >> t;
  t = 1;
  while (t--) {
    int nItems;
    int wCapacity;
    vector<int> profits;
    vector<int> weights;
    cin >> nItems;
    cin >> wCapacity;
    profits.push_back(0);
    weights.push_back(0);
    int tmp;
    for (int i = 0; i < nItems; i++) {
      cin >> tmp;
      profits.push_back(tmp);
    }
    for (int i = 0; i < nItems; i++) {
      cin >> tmp;
      weights.push_back(tmp);
    }
    nItems++;
    int knapsackMat[nItems][wCapacity + 1];
    for (int i = 0; i < nItems; i++) {
      knapsackMat[i][0] = 0;
    }
    for (int i = 0; i <= wCapacity; i++) {
      knapsackMat[0][i] = 0;
    }

    for (int i = 1; i < nItems; i++) {
      for (int j = 1; j <= wCapacity; j++) {
        if (weights[i] > j) {
          knapsackMat[i][j] = knapsackMat[i - 1][j];
        } else {
          knapsackMat[i][j] = max(knapsackMat[i - 1][j],
                                  profits[i] + knapsackMat[i - 1][j - i]);
        }
      }
    }
    for (int i = 0; i < nItems; i++) {
      for (int j = 0; j <= wCapacity; j++) {
        cout << knapsackMat[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}