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

bool isValid(vector<vector<int>> &a, int x, int y,
             vector<vector<bool>> &visited) {
  if (x >= 0 && x < a.size() && y >= 0 && y < a[0].size() && !visited[x][y])
    return true;
  return false;
}

int dfs_height(vector<vector<int>> &a, int x, int y, int &minX,
               vector<vector<bool>> &visited) {}

int dfs_helper()

    int main(int argc, char const *argv[]) {

  vector<vector<int>> a{
      {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0},
      {1, 0, 1, 0}, {1, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1},
  };

  int maxHeight = return 0;
}
