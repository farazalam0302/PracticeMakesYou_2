#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V) {
  cout << "\n\n";
  for (int i = 0; i < V; i++) {
    std::cout << "[" << i << "] --";
    for (auto k : adj[i]) {
      cout << "-> " << k;
    }
    cout << "-> Null" << endl;
  }
  cout << "\n\n";
}

int main(int argc, const char **argv) {
  int vertices = 5;
  vector<int> adjList[vertices];
  addEdge(adjList, 0, 1);
  addEdge(adjList, 0, 4);
  addEdge(adjList, 1, 2);
  addEdge(adjList, 1, 3);
  addEdge(adjList, 2, 3);
  addEdge(adjList, 3, 4);
  printGraph(adjList, vertices);

  return 0;
}
