/*
 *
 *
 * Flood-fill Algorithm
TUTORIALPROBLEMS
Flood fill algorithm helps in visiting each and every point in a given area. It
determines the area connected to a given cell in a multi-dimensional array.
Following are some famous implementations of flood fill algorithm:

Bucket Fill in Paint:
Clicking in an area with this tool selected fills that area with the selected
color.

Solving a Maze:
Given a matrix with some starting point, and some destination with some
obstacles in between, this algorithm helps to find out the path from source to
destination

Minesweeper:
When a blank cell is discovered, this algorithm helps in revealing neighboring
cells. This step is done recursively till cells having numbers are discovered.

Flood fill algorithm can be simply modeled as graph traversal problem,
representing the given area as a matrix and considering every cell of that
matrix as a vertex that is connected to points above it, below it, to right of
it, and to left of it and in case of 8-connections, to the points at both
diagonals also. For example, consider the image given below.


Flood fill Algorithm – how to implement fill() in paint?
In MS-Paint, when we take the brush to a pixel and click, the color of the
region of that pixel is replaced with a new selected color. Following is the
problem statement to do this task. Given a 2D screen, location of a pixel in the
screen and a color, replace color of the given pixel and all adjacent same
colored pixels with the given color.

Example:

Input:
       screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };
    x = 4, y = 4, newColor = 3
The values in the given 2D screen indicate colors of the pixels.
x and y are coordinates of the brush, newColor is the color that
should replace the previous color on screen[x][y] and all surrounding
pixels with same color.

Output:
Screen should be changed to following.
       screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 3, 3, 3, 3, 0, 1, 0},
                      {1, 1, 1, 3, 3, 0, 1, 0},
                      {1, 1, 1, 3, 3, 3, 3, 0},
                      {1, 1, 1, 1, 1, 3, 1, 1},
                      {1, 1, 1, 1, 1, 3, 3, 1},
                      };

 *
 *
 * */
#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>& a) {
  for (auto i : a) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
void floodFill_DFS(vector<vector<int>>& a, int x, int y, int oldColor,
                   int newColor) {
  int m = a.size();
  int n = a[0].size();

  if (x < 0 || x >= m || y < 0 || y >= n) {
    return;
  }
  if (a[x][y] != oldColor) return;
  a[x][y] = newColor;

  floodFill_DFS(a, x + 1, y, oldColor, newColor);
  floodFill_DFS(a, x - 1, y, oldColor, newColor);
  floodFill_DFS(a, x, y + 1, oldColor, newColor);
  floodFill_DFS(a, x, y - 1, oldColor, newColor);
}

void floodFill(vector<vector<int>>& a, int x, int y, int newColor) {
  int oldColor = a[x][y];
  floodFill_DFS(a, x, y, oldColor, newColor);
}

int main(int argc, char** argv) {
  vector<vector<int>> a = {
      {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 0, 1, 1, 0, 1, 1}, {1, 2, 2, 2, 2, 0, 1, 0},
      {1, 1, 1, 2, 2, 0, 1, 0}, {1, 1, 1, 2, 2, 2, 2, 0},
      {1, 1, 1, 1, 1, 2, 1, 1}, {1, 1, 1, 1, 1, 2, 2, 1},
  };

  cout << "\nInput Image\n------------------------" << endl;
  display(a);
  cout << "\n-------------------------\n" << endl;

  floodFill(a, 4, 4, 3);

  cout << "\nOutput Image\n------------------------" << endl;
  display(a);
  cout << "\n-------------------------\n" << endl;

  return 0;
}
