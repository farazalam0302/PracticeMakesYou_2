/*
 *
 * Dijkstra's Algorithm
Dijkstra's algorithm has many variants but the most common one is to find the
shortest paths from the source vertex to all other vertices in the graph.

Algorithm Steps:

> Set all vertices distances = infinity except for the source vertex, set the
source distance = 0.

> Push the source vertex in a min-priority queue in the form
(distance , vertex), as the comparison in the min-priority queue will be
according to vertices distances.

> Pop the vertex with the minimum distance from the priority queue (at first the
popped vertex = source).

> Update the distances of the connected vertices to the popped vertex in case of
"current vertex distance + edge weight < next vertex distance", then push the
vertex with the new distance to the priority queue.

> If the popped vertex is visited before, just continue without using it.

> Apply the same algorithm again until the priority queue is empty.
 *
 *
 *
 * */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
class Graph {
  int V;
  list<iPair>* adjList;

 public:
  Graph(int V);
  void addEdge(int u, int v, int weight);
  void shortestPath(int s);
};

Graph::Graph(int V) {
  this->V = V;
  adjList = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int weight) {
  adjList[u].push_back(make_pair(v, weight));
  adjList[v].push_back(make_pair(u, weight));
}

void Graph::shortestPath(int src) {
  priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
  vector<int> dist(V, INT_MAX);
  pq.push(make_pair(0, src));
  dist[src] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (auto i : adjList[u]) {
      int v = i.first;
      int weight = i.second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  cout << "\n\nVertex Distance From Source\n\n" << endl;
  int pos = 0;
  for (auto i : dist) {
    cout << pos << "\t\t\t" << i << endl;
    pos++;
  }
}

int main(int argc, char** argv) {
  int V = 9;
  Graph g(V);

  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);
  g.shortestPath(0);

  return 0;
}
