/*
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,1,0},
{1,0,1,0},
{1,1,1,0},
{1,1,1,1},
{1,1,1,1},

// evry step of row  if I get 1 , rowMin=INTMAX
rS  4352
    0123
*/

#include <bits/stdc++.h>
using namespace std;

// O(M+N) Solution using DFS
bool isValidMove(vector<vector<int>> &a, int x, int y) {
  int m = a.size();
  int n = a[0].size();
  if (x >= 0 && x < m && y >= 0 && y < n && a[x][y] == 1)
    return true;
  else
    return false;
}

void DFS(vector<vector<int>> &a, vector<vector<bool>> &visited,
         vector<int> &barsize, int x, int y) {
  if (!isValidMove(a, x, y) || (visited[x][y]))
    return;

  visited[x][y] = true;
  barsize[y] = a.size() - x;
  DFS(a, visited, barsize, x + 1, y);
  DFS(a, visited, barsize, x - 1, y);
  DFS(a, visited, barsize, x, y + 1);
  DFS(a, visited, barsize, x, y - 1);
}
vector<int> DFS_helper(vector<vector<int>> &a) {
  int m = a.size();
  int n = a[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  vector<int> barsize(n, 0);
  int x = m - 1;
  int y = 0;
  visited[x][y] = true;
  barsize[y] = m - x;
  for (; x >= 0; x--) {
    for (; y < n; y++) {
      if (visited[x][y] == false && isValidMove(a, x, y)) {

        DFS(a, visited, barsize, x, y);
      }
    }
  }

  return barsize;
}

vector<int> naiveSolution(vector<vector<int>> &a) {
  int m = a.size();
  int n = a[0].size();
  vector<int> ret(n, 0);
  for (size_t c = 0; c < n; c++) {
    for (size_t r = 0; r < m; r++) {
      ret[c] = ret[c] + a[r][c];
    }
  }
  return ret;
}

void printArray(vector<int> &a) {

  for (auto &i : a) {
    cout << i << "";
  }
  cout << endl;
  int count = 0;
  for (auto &i : a) {
    cout << count << "";
    count++;
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  // clang-format off
  vector<vector<int>> a{
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 1, 0},
      {1, 0, 1, 0},
      {1, 1, 1, 0},
      {1, 1, 1, 1},
      {1, 1, 1, 1},
  };
  // clang-format on
  // vector<int> ret = naiveSolution(a);
  vector<int> ret = DFS_helper(a);
  printArray((ret));
}
