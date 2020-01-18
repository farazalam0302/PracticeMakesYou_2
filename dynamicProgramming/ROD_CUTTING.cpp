/*
https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

Cutting a Rod | DP-13
Given a rod of length n inches and an array of prices that contains prices of
all pieces of size smaller than n. Determine the maximum value obtainable by
cutting up the rod and selling the pieces. For example, if length of the rod is
8 and the values of different pieces are given as following, then the maximum
obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

Pieces = {1,2,3,4}
Profit = {2,5,9,6}
L = 5

*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char **argv) {
  int LENGTH, ROWS, tmp;
  vector<int> piece_lengths;
  vector<int> gains;
  piece_lengths.push_back(0);
  gains.push_back(0);
  cin >> LENGTH;
  cin >> ROWS;
  for (int i = 0; i < ROWS; i++) {
    cin >> tmp;
    piece_lengths.push_back(tmp);
  }
  for (int i = 0; i < ROWS; i++) {
    cin >> tmp;
    gains.push_back(tmp);
  }
  vector<vector<int>> dp(ROWS + 1, vector<int>(LENGTH + 1, 0));

  for (int i = 1; i <= ROWS; i++) {
    for (int j = 1; j <= LENGTH; j++) {
      if (piece_lengths[i] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], (gains[i] + dp[i][j - piece_lengths[i]]));
      }
    }
  }

  for (int i = 0; i <= ROWS; i++) {
    for (int j = 0; j <= LENGTH; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "maximum profit made = " << dp[ROWS][LENGTH] << endl;

  cout << "\n\n --------------------------second "
          "method---------------------------------- \n\n"
       << endl;

  vector<int> dps(LENGTH + 1, 0);

  int val[LENGTH + 1];
  val[0] = 0;
  int i, j;

  // Build the table val[] in bottom up manner and return the last entry
  // from the table
  for (i = 1; i <= LENGTH; i++) {
    int max_val = INT_MIN;
    for (j = 0; j < i; j++)
      max_val = max(max_val, gains[j] + val[i - j - 1]);
    val[i] = max_val;
  }

  for (auto i : val) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}