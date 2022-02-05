#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves{
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1},
};

void display(vector<vector<int>>& a) {
  for (auto i : a) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

bool isValid(vector<vector<int>>& a, int x, int y, int oldColor,
             vector<vector<bool>>& visited) {
  if (x >= 0 && x < a.size() && y >= 0 && y <= a[0].size() &&
      a[x][y] == oldColor && !visited[x][y])
    return true;
  return false;
}

void paintFill(vector<vector<int>>& a, int x, int y, int newColor) {
  int oldColor = a[x][y];
  queue<pair<int, int>> Q;
  int m = a.size();
  int n = a[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  Q.push({x, y});
  visited[x][y] = true;

  while (!Q.empty()) {
    pair<int, int> frontt = Q.front();
    Q.pop();
    a[frontt.first][frontt.second] = newColor;
    for (auto k : moves) {
      if (isValid(a, x + k.first, y + k.second, oldColor, visited)) {
        Q.push({x + k.first, y + k.second});
        visited[x + k.first, y + k.second];
      }
    }
  }
}

int main() {
  vector<vector<int>> a = {
      {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 0, 1, 1, 0, 1, 1}, {1, 2, 2, 2, 2, 0, 1, 0},
      {1, 1, 1, 2, 2, 0, 1, 0}, {1, 1, 1, 2, 2, 2, 2, 0},
      {1, 1, 1, 1, 1, 2, 1, 1}, {1, 1, 1, 1, 1, 2, 2, 1},
  };

  cout << "\nInput Image\n------------------------" << endl;
  display(a);
  cout << "\n-------------------------\n" << endl;
  paintFill(a, 4, 4, 3);
  cout << "\nOutput Image\n------------------------" << endl;
  display(a);
  cout << "\n-------------------------\n" << endl;

  return 0;
}
