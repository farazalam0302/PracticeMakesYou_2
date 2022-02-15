// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  // Function to find unit area of the largest region of 1s.

  bool isSafe(vector<vector<int>>& grid, int row, int col,
              vector<vector<bool>>& visited) {
    int nRows = grid.size();
    int nCols = grid[0].size();
    return (row >= 0 && row < nRows && col >= 0 && col < nCols &&
            grid[row][col] && !visited[row][col]);
  }

  void DFS(vector<vector<int>>& grid, int row, int col,
           vector<vector<bool>>& visited, int& count) {
    static vector<pair<int, int>> neighbours{
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int nRows = grid.size();
    int nCols = grid[0].size();

    visited[row][col] = true;

    for (auto i : neighbours) {
      if (isSafe(grid, row + i.first, col + i.second, visited)) {
        count++;
        DFS(grid, row + i.first, col + i.second, visited, count);
      }
    }
  }
  int findMaxArea(vector<vector<int>>& grid) {
    int nRows = grid.size();
    int nCols = grid[0].size();
    vector<vector<bool>> visited(nRows, (vector<bool>(nCols, false)));
    int result = -12345;
    for (int i = 0; i < nRows; i++) {
      for (int j = 0; j < nCols; j++) {
        if (grid[i][j] && !visited[i][j]) {
          int count = 1;
          DFS(grid, i, j, visited, count);

          result = max(result, count);
        }
      }
    }

    return result;
  }
};

// { Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    int ans = obj.findMaxArea(grid);
    cout << ans << "\n";
  }
  return 0;
}  // } Driver Code Ends
