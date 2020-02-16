/*
 * DFS_inGraph.cpp
 *
 *  Created on: 16-Feb-2020
 *      Author: faraz
 *
 *
 *      https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
 *
 */
#include <bits/stdc++.h>
using namespace std;

class Graph {
  int vertices;
  list<int> *adjList;

 public:
  void DFS_util(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adjList[v].begin(); i != adjList[v].end(); i++) {
      if (!visited[*i]) {
        DFS_util(*i, visited);
      }
    }
  }

  void DFS(int v) {
    bool *visited = new bool[v];
    for (int i = 0; i < v; ++i) {
      visited[i] = false;
    }
    DFS_util(v, visited);
  }

  Graph(int n) {
    this->vertices = n;
    adjList = new list<int>[n];
  }
  void addEdge(int v, int w) {
    adjList[v].push_back(w);  // add w node to v's list
  }
};

int main(int argc, char **argv) {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "\n\nFollowing is Depth First Traversal"
          " (starting from vertex 2) \n";
  g.DFS(2);
  cout << "\n\n";

  return 0;
}
