/*
 * The shortest path problem is about finding a path between  vertices in a
graph such that the total sum of the edges weights is minimum.

This problem could be solved easily using (BFS) if all edge weights were (), but
here weights can take any value. Three different algorithms are discussed below
depending on the use-case.

Bellman Ford's Algorithm:
Bellman Ford's algorithm is used to find the shortest paths from the source
vertex to all other vertices in a weighted graph. It depends on the following
concept: Shortest path contains at most  edges, because the shortest path
couldn't have a cycle.

So why shortest path shouldn't have a cycle ?
There is no need to pass a vertex again, because the shortest path to all other
vertices could be found without the need for a second visit for any vertices.

Algorithm Steps:

The outer loop traverses from  0:n-1 .
Loop over all edges, check if the next node distance > current node distance +
edge weight, in this case update the next node distance to "current node
distance + edge weight". This algorithm depends on the relaxation principle
where the shortest distance for all vertices is gradually replaced by more
accurate values until eventually reaching the optimum solution. In the beginning
all vertices have a distance of "Infinity", but only the distance of the source
vertex = , then update all the connected vertices with the new distances (source
vertex distance + edge weights), then apply the same concept for the new
vertices with new distances and so on.
 *
 * */
#include <bits/stdc++.h>
using namespace std;

typedef struct Edge {
  int src, dest, weight;
} PII;  // <weight,edge(x,y)>

struct Graph {
  int V, E;
  //  vector<PII> edge;
  PII* edge;
};

struct Graph* createGraph(int V, int E) {
  struct Graph* graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new PII[E];
  return graph;
}

void BellmanFord(struct Graph* graph, int src) {
  int V = graph->V;
  int E = graph->E;
  vector<int> dist(V + 1, INT_MAX);

  dist[src] = 0;

  for (int i = 1; i <= V - 1; ++i) {
    for (int j = 0; j < E; ++j) {
      int u = graph->edge[j].src;
      int v = graph->edge[j].dest;
      int weight = graph->edge[j].weight;
      if (dist[u] != INT_MAX && (dist[u] + weight < dist[v])) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  // negative cycle check
  for (int j = 0; j < E; ++j) {
    int u = graph->edge[j].src;
    int v = graph->edge[j].dest;
    int weight = graph->edge[j].weight;
    if (dist[u] != INT_MAX && (dist[u] + weight < dist[v])) {
      cout << "\n\n Negative Weight Cycle Detetected \n " << endl;
      return;
      //      dist[v] = dist[u] + weight;
    }
  }

  cout << "\nVertex Distance from Source \n" << endl;
  for (int i = 0; i < V; ++i) {
    cout << i << "  \t\t " << dist[i] << endl;
  }
  cout << "\n\n" << endl;
}

int main(int argc, char** argv) {
  int V = 5;
  int E = 8;
  struct Graph* graph = createGraph(V, E);
  // add edge 0-1
  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->edge[0].weight = -1;

  graph->edge[1].src = 0;
  graph->edge[1].dest = 2;
  graph->edge[1].weight = 4;

  graph->edge[2].src = 1;
  graph->edge[2].dest = 2;
  graph->edge[2].weight = 3;

  graph->edge[3].src = 1;
  graph->edge[3].dest = 3;
  graph->edge[3].weight = 2;

  graph->edge[4].src = 1;
  graph->edge[4].dest = 4;
  graph->edge[4].weight = 2;

  graph->edge[5].src = 3;
  graph->edge[5].dest = 2;
  graph->edge[5].weight = 5;

  graph->edge[6].src = 3;
  graph->edge[6].dest = 1;
  graph->edge[6].weight = 1;

  graph->edge[7].src = 4;
  graph->edge[7].dest = 3;
  graph->edge[7].weight = -3;

  BellmanFord(graph, 0);
  return 0;
}
