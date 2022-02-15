#if 0
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 4

void printSolution(int color[]);

// check if the colored
// graph is safe or not
bool isSafe(
	bool graph[V][V], int color[])
{
	// check for every edge
	for (int i = 0; i < V; i++)
		for (int j = i + 1; j < V; j++)
			if (
				graph[i][j] && color[j] == color[i])
				return false;
	return true;
}

/* This function solves the m Coloring
problem using recursion. It returns
false if the m colours cannot be assigned,
otherwise, return true and prints
assignments of colours to all vertices.
Please note that there may be more than
one solutions, this function prints one
of the feasible solutions.*/
bool graphColoring(
	bool graph[V][V], int m,
	int i, int color[V])
{
	// if current index reached end
	if (i == V) {
		// if coloring is safe
		if (isSafe(graph, color)) {
			// Print the solution
			printSolution(color);
			return true;
		}
		return false;
	}

	// Assign each color from 1 to m
	for (int j = 1; j <= m; j++) {
		color[i] = j;

		// Recur of the rest vertices
		if (graphColoring(
				graph, m, i + 1, color))
			return true;

		color[i] = 0;
	}

	return false;
}

/* A utility function to print solution */
void printSolution(int color[])
{
	printf(
		"Solution Exists:"
		" Following are the assigned colors \n");
	for (int i = 0; i < V; i++)
		printf(" %d ", color[i]);
	printf("\n");
}

// Driver program to test above function
int main()
{
	/* Create following graph and
	test whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)
	*/
	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	int m = 3; // Number of colors

	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	if (!graphColoring(
			graph, m, 0, color))
		printf("Solution does not exist");

	return 0;
}

#endif

#include <bits/stdc++.h>
using namespace std;
#define N 4
bool isValidColoring(vector<vector<int>>& G, vector<int>& coloredVertices) {
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (G[i][j] && coloredVertices[i] == coloredVertices[j]) return false;
    }
  }
  return true;
}
bool isgraphColoringDone(vector<vector<int>>& G, vector<int>& coloredVertices,
                         int colors, int i) {
  if (i == N) {
    if (isValidColoring(G, coloredVertices)) return true;
    return false;
  }

  for (int j = 1; j <= colors; ++j) {
    coloredVertices[i] = j;
    if (isgraphColoringDone(G, coloredVertices, colors, i + 1)) return true;
    coloredVertices[i] = 0;
  }
  return false;
}

int main() {
  //
  //  vector<vector<int>> G(N, vector<int>(N, 0));
  vector<vector<int>> G{{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
  vector<int> coloredVertices(N, 0);
  int colors = 3;
  if (isgraphColoringDone(G, coloredVertices, colors, 0)) {
    for (auto i : coloredVertices) {
      cout << i << " ";
    }
  } else
    cout << "\n No Solution " << endl;

  return 0;
}
#if 0
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 4

void printSolution(int color[]);

/* A utility function to check if
the current color assignment
is safe for vertex v i.e. checks
whether the edge exists or not
(i.e, graph[v][i]==1). If exist
then checks whether the color to
be filled in the new vertex(c is
sent in the parameter) is already
used by its adjacent
vertices(i-->adj vertices) or
not (i.e, color[i]==c) */
bool isSafe(
	int v, bool graph[V][V],
	int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (
			graph[v][i] && c == color[i])
			return false;
	return true;
}

/* A recursive utility function
to solve m coloring problem */
bool graphColoringUtil(
	bool graph[V][V], int m,
	int color[], int v)
{
	/* base case: If all vertices are
	assigned a color then return true */
	if (v == V)
		return true;

	/* Consider this vertex v and
	try different colors */
	for (int c = 1; c <= m; c++) {
		/* Check if assignment of color
		c to v is fine*/
		if (isSafe(
				v, graph, color, c)) {
			color[v] = c;

			/* recur to assign colors to
			rest of the vertices */
			if (
				graphColoringUtil(
					graph, m, color, v + 1)
				== true)
				return true;

			/* If assigning color c doesn't
			lead to a solution then remove it */
			color[v] = 0;
		}
	}

	/* If no color can be assigned to
	this vertex then return false */
	return false;
}

/* This function solves the m Coloring
problem using Backtracking. It mainly
uses graphColoringUtil() to solve the
problem. It returns false if the m
colors cannot be assigned, otherwise
return true and prints assignments of
colors to all vertices. Please note
that there may be more than one solutions,
this function prints one of the
feasible solutions.*/
bool graphColoring(
	bool graph[V][V], int m)
{
	// Initialize all color values as 0.
	// This initialization is needed
	// correct functioning of isSafe()
	int color[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (
		graphColoringUtil(
			graph, m, color, 0)
		== false) {
		printf("Solution does not exist");
		return false;
	}

	// Print the solution
	printSolution(color);
	return true;
}

/* A utility function to print solution */
void printSolution(int color[])
{
	printf(
		"Solution Exists:"
		" Following are the assigned colors \n");
	for (int i = 0; i < V; i++)
		printf(" %d ", color[i]);
	printf("\n");
}

// driver program to test above function
int main()
{
	/* Create following graph and test
	whether it is 3 colorable
	(3)---(2)
	| / |
	| / |
	| / |
	(0)---(1)
	*/
	bool graph[V][V] = {
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};
	int m = 3; // Number of colors
	graphColoring(graph, m);
	return 0;
}

#endif
