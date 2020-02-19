/*
 *
 *
 * https://www.geeksforgeeks.org/union-find/
 *
 * Disjoint Set (Or Union-Find) | Set 1 (Detect Cycle in an Undirected Graph)
A disjoint-set data structure is a data structure that keeps track of a set of
elements partitioned into a number of disjoint (non-overlapping) subsets. A
union-find algorithm is an algorithm that performs two useful operations on such
a data structure:

Find: Determine which subset a particular element is in. This can be used for
determining if two elements are in the same subset.

Union: Join two subsets into a single subset.



In this post, we will discuss the application of Disjoint Set Data Structure.
The application is to check whether a given graph contains a cycle or not.

Union-Find Algorithm can be used to check whether an undirected graph contains
cycle or not. Note that we have discussed an algorithm to detect cycle. This is
another method based on Union-Find. This method assumes that the graph doesn’t
contain any self-loops. We can keep track of the subsets in a 1D array, let’s
call it parent[].

Let us consider the following graph:
 *
 *
 *
 * */

#include <bits/stdc++.h>
using namespace std;

class Edge {
 public:
  int src, dest;
};

class Graph {
 public:
  int Nedges, Nvertices;
  vector<pair<int, int>> EdgeSet;
  Edge* edge;
};

Graph* createGraph(int V, int E) {
  Graph* graph = new Graph();
  graph->Nvertices = V;
  graph->Nedges = E;
  graph->EdgeSet = vector<pair<int, int>>(E);
  graph->edge = new Edge[E * sizeof(Edge)];
}

int find(vector<int>& parent, int i) {
  if (parent[i] == -1) {
    return i;
  }
  return find(parent, parent[i]);
}

void Union_(vector<int>& parent, int x, int y) {
  int xset = find(parent, x);
  int yset = find(parent, y);
  if (xset != yset) {
    parent[xset] = yset;
  }
}

int isCycle(Graph* graph) {
  vector<int> parent(graph->Nvertices, -1);

  for (int i = 0; i < graph->Nedges; ++i) {
    //    int x = find(parent, graph->edge[i].src);
    //    int y = find(parent, graph->edge[i].dest);
    int xx = find(parent, ((graph->EdgeSet)[i]).first);
    int yy = find(parent, ((graph->EdgeSet)[i]).second);

    if (xx == yy) return 1;
    Union_(parent, xx, yy);
  }
  return 0;
}

int main(int argc, char** argv) {
  int V = 3;
  int E = 3;
  Graph* graph = createGraph(V, E);
  //  add edge 0-1
  graph->edge[0].src = 0;
  graph->edge[0].dest = 1;
  graph->EdgeSet.push_back(make_pair(0, 1));
  // add edge 1-2
  graph->edge[0].src = 1;
  graph->edge[0].dest = 2;
  graph->EdgeSet.push_back(make_pair(1, 2));

  // add edge 0-2
  graph->edge[0].src = 0;
  graph->edge[0].dest = 2;
  graph->EdgeSet.push_back(make_pair(0, 2));
  cout << (isCycle(graph) ? "\ngraph contains cycle\n"
                          : "\ngraph contains no cycle\n")
       << endl;
  return 0;
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
