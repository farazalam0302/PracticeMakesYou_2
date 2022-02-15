#if 0

// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

#define N 8

int solveKTUtil(int x, int y, int movei,
				int sol[N][N], int xMove[],
				int yMove[]);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
	return (x >= 0 && x < N && y >= 0 &&
			y < N && sol[x][y] == -1);
}

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
			cout << " " << setw(2)
						<< sol[x][y] << " ";
		cout << endl;
	}
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
int solveKT()
{
	int sol[N][N];

	/* Initialization of solution matrix */
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			sol[x][y] = -1;

	/* xMove[] and yMove[] define next move of Knight.
	xMove[] is for next value of x coordinate
	yMove[] is for next value of y coordinate */
	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	// Since the Knight is initially at the first block
	sol[0][0] = 0;

	/* Start from 0,0 and explore all tours using
	solveKTUtil() */
	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
	{
		cout << "Solution does not exist";
		return 0;
	}
	else
		printSolution(sol);

	return 1;
}

/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei,
				int sol[N][N], int xMove[N],
				int yMove[N])
{
	int k, next_x, next_y;
	if (movei == N*N)
		return 1;

	/* Try all next moves from
	the current coordinate x, y */
	for (k = 0; k < 8; k++)
	{
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if (isSafe(next_x, next_y, sol))
		{
			sol[next_x][next_y] = movei;
			if (solveKTUtil(next_x, next_y,
							movei + 1, sol,
							xMove, yMove) == 1)
				return 1;
			else
				// backtracking
				sol[next_x][next_y] = -1;
		}
	}
	return 0;
}

// Driver Code
int main()
{
	solveKT();
	return 0;
}

// This code is contributed by ShubhamCoder

#endif

#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>& a) {
  for (auto i : a) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
bool isSafe(vector<vector<int>>& a, int x, int y) {
  int m = a.size();
  int n = a[0].size();
  if (x >= 0 && y >= 0 && x < m && y < n && a[x][y] == -1) return true;
  return false;
}
bool SolveKnightsTour(int x, int y, int moveI, vector<vector<int>>& chess,
                      vector<pair<int, int>>& Moves) {
  int n = chess.size();
  int nextY, nextX;
  if (moveI == (n * n)) {
    return true;
  }
  for (int i = 0; i < 8; ++i) {
    nextX = x + Moves[i].first;
    nextY = y + Moves[i].second;
    if (isSafe(chess, nextX, nextY)) {
      chess[nextX][nextY] = moveI;
      if (SolveKnightsTour(nextX, nextY, moveI + 1, chess, Moves)) {
        return true;
      }
      chess[nextX][nextY] = -1;
    }
  }
  return false;
}

int main() {
  int n = 8;
  vector<vector<int>> chess(n, vector<int>(n, -1));
  vector<pair<int, int>> Moves{{-1, 2},  {-2, 1}, {1, 2},   {2, 1},
                               {-2, -1}, {2, -1}, {-1, -2}, {1, -2}};

  chess[0][0] = 0;  // knight placed
  if (SolveKnightsTour(0, 0, 1, chess, Moves)) {
    printMatrix(chess);
  } else {
    cout << "\n\nNO SOLUTION \n" << endl;
  }
  return 0;
}
