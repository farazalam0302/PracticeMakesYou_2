/**
 * Consider the directed graph given above. Let's create this graph using an
 * adjacency matrix and then show all the edges that exist in the graph.
 *
 * Input file
 * 4  // nodes
 * 5 //edges
 * 1 2  //showing edge from node 1 to node 2
 * 2 4  //showing edge from node 2 to node 4
 * 3 1  //showing edge from node 3 to node 1
 * 3 4  //showing edge from node 3 to node 4
 * 4 2  //showing edge from node 4 to node 2
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> &a) {
  int r = a.size();
  int c = a[0].size();

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

int main(int argc, char **argv) {
  int nodes;
  cin >> nodes;
  int edges;
  cin >> edges;
  vector<vector<int>> adjMatrix(nodes + 1, vector<int>(nodes + 1, 0));
  displayMatrix(adjMatrix);
  int x, y;
  for (int i = 0; i < 5; ++i) {
    cin >> x;
    cin >> y;
    adjMatrix[x][y] = 1;
  }
  cout << "\n\n\n after filling\n\n " << endl;

  displayMatrix(adjMatrix);

  return 0;
}
