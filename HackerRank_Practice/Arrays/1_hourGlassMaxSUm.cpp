#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
  int rows = arr.size();
  int cols = arr[0].size();
  int MaxSum = INT_MIN;
  int sum = 0;
  for (int i = 0; i < rows - 2; ++i) {
    for (int j = 0; j < cols - 2; ++j) {
      sum = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] +
             arr[i + 2][j] + arr[i + 2][j + 1] + +arr[i + 2][j + 2]);
      cout << "\n sum at " << i << ", " << j << " = " << sum << endl;
      MaxSum = max(MaxSum, sum);
    }
  }

  return MaxSum;
}

int main() {
  //    ofstream fout(getenv("OUTPUT_PATH"));

  //clang-format off
  vector<vector<int>> arr{{1, 1, 1, 0, 0, 0},  {0, 1, 0, 0, 0, 0},
                          {1, 1, 1, 0, 0, 0},  {0, 9, 2, -4, -4, 0},
                          {0, 0, 0, -2, 0, 0}, {0, 0, -1, -2, -4, 0}};
  //clang-format on
  //  vector<vector<int>> arr(6);
  //  for (int i = 0; i < 6; i++) {
  //    arr[i].resize(6);
  //
  //    for (int j = 0; j < 6; j++) {
  //      cin >> arr[i][j];
  //    }
  //
  //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  //  }

  int result = hourglassSum(arr);

  cout << "\n result  = " << result << "\n";

  return 0;
}
