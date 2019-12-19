/*
https://www.geeksforgeeks.org/remove-minimum-coins-such-that-absolute-difference-between-any-two-piles-is-less-than-k/


https://practice.geeksforgeeks.org/problems/coin-piles/0




Coin PilesSubmissions: 13014   Accuracy: 29.76%   Difficulty: Medium   Marks: 4
Associated Course(s):   Must Do Interview Preparation
    
Problems
There are N piles of coins each containing  Ai (1<=i<=N) coins.  Now, you have
to adjust the number of coins in each pile such that for any two pile, if a be
the number of coins in first pile and b is the number of coins in second pile
then |a-b|<=K. In order to do that you can remove coins from different piles to
decrease the number of coins in those piles but you cannot increase the number
of coins in a pile by adding more coins. Now, given a value of N and K, along
with the sizes of the N different piles you have to tell the minimum number of
coins to be removed in order to satisfy the given condition. Note: You can also
remove a pile by removing all the coins of that pile.

Input
The first line of the input contains T, the number of test cases. Then T lines
follow. Each test case contains two lines. The first line of a test case
contains N and K. The second line of the test case contains N integers
describing the number of coins in the N piles.

Output
For each test case output a single integer containing the minimum number of
coins needed to be removed in a new line.

Constraints
1<=T<=50
1<=N<=100
1<=Ai<=1000
0<=K<=1000

Example
Input
3
4 0
2 2 2 2
6 3
1 2 5 1 1 1
6 3
1 5 1 2 5 1

Output
0
1
2

Explanation
1. In the first test case, for any two piles the difference in the number of
coins is <=0. So no need to remove any coins.
2. In the second test case if we remove one coin from pile containing 5 coins
then for any two piles the absolute difference in the number of coins is <=3.
3. In the third test case if we remove one coin each from both the piles
containing 5 coins , then for any two piles the absolute difference in the
number of coins is <=3.

** For More Input/Output Examples Use 'Expected Output' option **
Author: Arnab Deb
*/

#include <bits/stdc++.h>
using namespace std;
class CoinPiling {

public:
  int coinPilesRemoved(vector<int> &a, int k) {
    int n = a.size();
    int minimum = a[0];
    for (int i = 1; i < n; i++) {
      minimum = min(minimum, a[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      int diff = a[i] - minimum;
      if (diff > k) {
        count = count + (diff - k);
      }
    }
    return count;
  }
};

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x);
    }
    CoinPiling cp;
    cout << cp.coinPilesRemoved(a, k) << endl;
  }

  return 0;
}
