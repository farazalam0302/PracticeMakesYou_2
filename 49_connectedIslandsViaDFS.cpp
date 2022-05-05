/*
 * Find the number of islands | Set 1 (Using DFS)
Given a boolean 2D matrix, find the number of islands. A group of connected 1s
forms an island. For example, the below matrix contains 5 islands

Example:

Input : mat[][] = {{1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}
Output : 5
This is a variation of the standard problem: “Counting the number of connected
components in an undirected graph”.

Before we go to the problem, let us understand what is a connected component. A
connected component of an undirected graph is a subgraph in which every two
vertices are connected to each other by a path(s), and which is connected to no
other vertices outside the subgraph. For example, the graph shown below has
three connected components.
 */

#include <bits/stdc++.h>
using namespace std;

bool isValidMove(vector<vector<int>>& a, int x, int y) {}

void dfs(vector<vector<int>>& a, int x, int y) {
  int m = a.size();
  int n = a[0].size();
  if (!(x < m && x >= 0 && y < n && y >= 0 && a[x][y] == 1)) return;
  a[x][y] = 2;
  dfs(a, x + 1, y);
  dfs(a, x - 1, y);
  dfs(a, x, y + 1);
  dfs(a, x, y - 1);
  dfs(a, x + 1, y + 1);
  dfs(a, x - 1, y - 1);
  dfs(a, x + 1, y - 1);
  dfs(a, x - 1, y + 1);
}

int main(int argc, char** argv) {
  // clang-format off
	vector<vector<int>> a {
						   {1, 1, 0, 0, 0},
                           {0, 1, 0, 0, 1},
						   {1, 0, 0, 1, 1},
						   {0, 0, 0, 0, 0},
						   {1, 0, 1, 0, 1}
							};
  // clang-format on

  int count = 0;
  int m = a.size();
  int n = a[0].size();
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i < m && i >= 0 && j < n && j >= 0 && a[i][j] == 1)) {
        dfs(a, i, j);
        count++;
      }
    }
  }

  cout << "\nResult = " << count << endl;

  return 0;
}
