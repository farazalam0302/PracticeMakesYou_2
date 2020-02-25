/*
 *
 * Floyd–Warshall's Algorithm
Floyd–Warshall's Algorithm is used to find the shortest paths between between
all pairs of vertices in a graph, where each edge in the graph has a weight
which is positive or negative. The biggest advantage of using this algorithm is
that all the shortest distances between any  vertices could be calculated in ,
where  is the number of vertices in a graph.

The Algorithm Steps:

For a graph with  vertices:

Initialize the shortest paths between any  vertices with Infinity.
Find all pair shortest paths that use  intermediate vertices, then find the
shortest paths that use  intermediate vertex and so on.. until using all
vertices as intermediate nodes. Minimize the shortest paths between any  pairs
in the previous operation. For any  vertices  , one should actually minimize the
distances between this pair using the first  nodes, so the shortest path will
be: . represents the shortest path that only uses the first  vertices,
represents the shortest path between the pair . As the shortest path will be a
concatenation of the shortest path from  to , then from  to .
 *
 * */
#include <bits/stdc++.h>
using namespace std;
#define MAXX 99999

// typedef struct Edge
void display(vector<vector<int>>& a) {
  int sz = a.size();
  for (auto i : a) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
///////////////
void floyd_warshall_algo(vector<vector<int>>& adjMatrix) {
  int vertices = adjMatrix.size();
  vector<vector<int>> dist = adjMatrix;
  //  vector<vector<int>> dist(vertices);
  //  copy(adjMatrix.begin(), adjMatrix.end(), dist.begin());
  for (int k = 0; k < vertices; ++k) {
    for (int i = 0; i < vertices; ++i) {
      for (int j = 0; j < vertices; ++j) {
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  display(dist);
  //  cout << "\n\n";
  //  display(adjMatrix);
}

int main(int argc, char** argv) {
  int vertices;
  cin >> vertices;
  int x, y, w;
  vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, MAXX));
  for (int i = 0; i < vertices; ++i) {
    cin >> x >> y >> w;
    //    for (int j = 0; j < vertices; ++j) {
    adjMatrix[x][y] = w;
    adjMatrix[x][x] = 0;
    adjMatrix[y][y] = 0;
    //    }
  }
  display(adjMatrix);
  cout << "\n\n";
  floyd_warshall_algo(adjMatrix);

  return 0;
}
