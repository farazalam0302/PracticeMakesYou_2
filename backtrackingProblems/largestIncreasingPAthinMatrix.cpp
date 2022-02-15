/*
 * Rat in a Maze | Backtracking-2
We have discussed Backtracking and Knight’s tour problem in Set 1. Let us
discuss Rat in a Maze as another example problem that can be solved using
Backtracking. A Maze is given as N*N binary matrix of blocks where source block
is the upper left most block i.e., maze[0][0] and destination block is lower
rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach
the destination. The rat can move only in two directions: forward and down. In
the maze matrix, 0 means the block is a dead end and 1 means the block can be
used in the path from source to destination. Note that this is a simple version
of the typical Maze problem. For example, a more complex version can be that the
rat can move in 4 directions and a more complex version can be with a limited
number of moves.


 */

/* C/C++ program to solve Rat in
a Maze problem using backtracking */

#if 0
#include <stdio.h>

// Maze size
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) printf(" %d ", sol[i][j]);
    printf("\n");
  }
}

/* A utility function to check if x,
y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y) {
  // if (x, y outside maze) return false
  if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) return true;

  return false;
}

/* This function solves the Maze problem
using Backtracking. It mainly uses
solveMazeUtil() to solve the problem.
It returns false if no path is possible,
otherwise return true and prints the path
in the form of 1s. Please note that there
may be more than one solutions, this
function prints one of the feasible
solutions.*/
bool solveMaze(int maze[N][N]) {
  int sol[N][N] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  if (solveMazeUtil(maze, 0, 0, sol) == false) {
    printf("Solution doesn't exist");
    return false;
  }

  printSolution(sol);
  return true;
}

/* A recursive utility function
to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
  // if (x, y is goal) return true
  if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
    sol[x][y] = 1;
    return true;
  }

  // Check if maze[x][y] is valid
  if (isSafe(maze, x, y) == true) {
    // mark x, y as part of solution path
    sol[x][y] = 1;

    /* Move forward in x direction */
    if (solveMazeUtil(maze, x + 1, y, sol) == true) return true;

    /* If moving in x direction
    doesn't give solution then
    Move down in y direction */
    if (solveMazeUtil(maze, x, y + 1, sol) == true) return true;

    /* If none of the above movements
    work then BACKTRACK: unmark
    x, y as part of solution path */
    sol[x][y] = 0;
    return false;
  }

  return false;
}

// driver program to test above function
int main() {
  int maze[N][N] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};

  solveMaze(maze);
  return 0;
}
#endif

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& a, int x, int y) {
  if (x < a.size() && x >= 0 && y < a[0].size() && y >= 0) {
    return true;
  }
}
bool isValidRightMove(vector<vector<int>>& a, int x, int y) {
  if (isSafe(a, x, y + 1) && a[x][y + 1] > a[x][y]) return true;
  return false;
}
bool isValidDownMove(vector<vector<int>>& a, int x, int y) {
  if (isSafe(a, x, y + 1) && a[x + 1][y] > a[x][y]) return true;
  return false;
}
bool isValidDownDiagnolMove(vector<vector<int>>& a, int x, int y) {
  if (isSafe(a, x + 1, y + 1) && a[x + 1][y + 1] > a[x][y]) return true;
  return false;
}
// bool solveMaze(vector<vector<int>>& a, int x, int y, vector<vector<int>>&
// sol) {
//  if ((x == (a.size() - 1)) && (y == (a[0].size() - 1))) {
//    sol[x][y] = max(sol[x - 1][y - 1], max(sol[x][y - 1], sol[x - 1][y])) + 1;
//    return true;
//  }
//  if (isSafe(a, x, y)) {
//    if (solveMaze(a,x,y+1))
//
//  }
//}

int dpSolutionLIPath(vector<vector<int>>& a, vector<vector<int>>& dp, int x,
                     int y) {
  int m = a.size();
  int n = a[0].size();
  if (dp[x][y] < 0) {
    int result = 0;
    if (x == m - 1 && y == n - 1) {
      return dp[x][y] = 1;
    }
    if (x == m - 1 || y == n - 1) {
      result = 1;
    }
    if ((isSafe(a, x, y)) && (isSafe(a, x + 1, y)))
      if (a[x][y] < a[x + 1][y]) {
        result = 1 + dpSolutionLIPath(a, dp, x + 1, y);
      }
    if ((isSafe(a, x, y)) && (isSafe(a, x, y + 1)))
      if (a[x][y] < a[x][y + 1]) {
        result = max(result, 1 + dpSolutionLIPath(a, dp, x, y + 1));
      }
    dp[x][y] = result;
  }
  return dp[x][y];
}

void printMatrix(vector<vector<int>>& a) {
  for (auto i : a) {
    for (auto j : i) {
      cout << j << ", ";
    }
    cout << endl;
  }
}
int main() {  //  vector<vector<int>> maze{
  //      {1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};

  vector<vector<int>> maze{
      {1, 2, 3, 4}, {2, 2, 3, 4}, {3, 2, 3, 4}, {4, 5, 6, 7}};
  //{{3, 2, 1}, {5, 6, 7}, {4, 0, 8}};
  int n = maze.size();
  int m = maze[0].size();
  vector<vector<int>> sol(n, vector<int>(m, -1));
  cout << "solMatrix = " << endl;
  printMatrix(sol);
  //  if (solveMaze(maze, 0, 0, sol)) {
  //    for (auto i : sol) {
  //      for (auto j : i) {
  //        cout << j << " ";
  //      }
  //      cout << endl;
  //    }
  //  } else {
  //    cout << "\nNo Solution" << endl;
  //  }

  cout << "Maze = " << endl;
  printMatrix(maze);
  cout << "\n\n";

  int result = dpSolutionLIPath(maze, sol, 0, 0);
  cout << "solMatrix = " << endl;
  printMatrix(sol);
  cout << "\n\nsolution = " << result << endl;

  return 0;
}
