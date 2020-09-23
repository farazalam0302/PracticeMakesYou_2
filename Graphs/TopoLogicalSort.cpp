/*
 * Topological sorting of vertices of a Directed Acyclic Graph is an ordering of
the vertices  in such a way, that if there is an edge directed towards vertex
from vertex , then  comes before . For example consider the graph given below:

enter image description here

A topological sorting of this graph is:
There are multiple topological sorting possible for a graph. For the graph given
above one another topological sorting is: In order to have a topological sorting
the graph must not contain any cycles. In order to prove it, let's assume there
is a cycle made of the vertices . That means there is a directed edge between
and   and between  and . So now, if we do topological sorting then  must come
before  because of the directed edge from  to . Clearly,  will come after ,
because of the directed from  to , that means  must come before . Well, clearly
we've reached a contradiction, here. So topological sorting can be achieved for
only directed and acyclic graphs.

Le'ts see how we can find a topological sorting in a graph. So basically we want
to find a permutation of the vertices in which for every vertex , all the
vertices  having edges coming out and directed towards  comes before . We'll
maintain an array  that will denote our topological sorting. So, let's say for a
graph having  vertices, we have an array  of size  whose  element tells the
number of vertices which are not already inserted in  and there is an edge from
them incident on vertex numbered . We'll append vertices  to the array , and
when we do that we'll decrease the value of  by  for every edge from  to . Doing
this will mean that we have inserted one vertex having edge directed towards .
So at any point we can insert only those vertices for which the value of  is .
The algorithm using a BFS traversal is given below:
 */

#include <bits/stdc++.h>
using namespace std;

class Graph {
 public:
  int V;
  list<int>* adjList;
  //  vector<list<int>> adjList;
  bool isUndirected;

  Graph(int n, bool isunDirected) {
    V = n;
    adjList = new list<int>[n];
    //    adjList = new vector<list<int>>(n);
    isUndirected = isunDirected;
  }
  void addEdge(int a, int b) {
    adjList[a].push_back(b);  // directed graph
                              //       adjList
    if (isUndirected) {
      adjList[b].push_back(a);
    }
  }

  //  const list<int>*& getAdj_List() const { return adjList; }

  //  bool isIs_Undirected() const { return isUndirected; }

  //  int getV() const { return V; }
};
void printVector(vector<int>& a) {
  cout << "\n";
  for (auto i : a) {
    cout << i << " ";
  }
  cout << "\n";
}
void topologicalSOrt_BFS(Graph& g) {
  vector<bool> visited(g.V, false);
  vector<int> T;
  vector<int> indegree(g.V, 0);
  for (int i = 0; i < g.V; ++i) {
    for (auto j : g.adjList[i]) {
      indegree[j]++;
    }
  }
  printVector(indegree);

  queue<int> Q;
  for (int i = 0; i < g.V; ++i) {
    if (indegree[i] == 0) {
      Q.push(i);
      visited[i] = true;
    }
  }
  int vertex;
  while (!Q.empty()) {
    vertex = Q.front();
    Q.pop();
    T.push_back(vertex);
    for (auto i : g.adjList[vertex]) {
      if (!visited[i]) {
        indegree[i]--;
        if (indegree[i] == 0) {
          Q.push(i);
          visited[i] = true;
        }
      }
    }
  }
  cout << "\nTopoSort =\n";
  printVector(T);
}

/*
 * Solution using a DFS traversal, unlike the one using BFS, does not need any
special  array. Following is the pseudo code of the DFS solution:

T = []
visited = []

topological_sort( cur_vert, N, adj[][] ){
    visited[cur_vert] = true
    for i = 0 to N
        if adj[cur_vert][i] is true and visited[i] is false
        topological_sort(i)
    T.insert_in_beginning(cur_vert)
}
The following image of shows the state of stack and of array  in the above code
for the same graph shown above.
 *
 */

void topologicalSortUtility_DFS(int currentVertex, Graph& g,
                                vector<bool>& visited, list<int>& T) {
  visited[currentVertex] = true;
  for (auto i : g.adjList[currentVertex]) {
    if (visited[i] == false) {
      topologicalSortUtility_DFS(i, g, visited, T);
    }
    T.push_front(currentVertex);
  }
}

void topologicalSort_DFS(Graph& g) {
  vector<bool> visited(g.V, false);
  list<int> T;
  for (int i = 0; i < g.V; ++i) {
    topologicalSortUtility_DFS(i, g, visited, T);
  }

  for (auto j : T) {
    cout << j << " ";
  }
  cout << '\n';
}
int main(int argc, char** argv) {
  Graph g(5, false);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  topologicalSOrt_BFS(g);
  cout << "\n\n\n\nnext graph\n";
  Graph g1(6, false);
  g1.addEdge(0, 1);
  g1.addEdge(0, 3);
  g1.addEdge(1, 2);
  g1.addEdge(1, 3);
  g1.addEdge(2, 3);
  g1.addEdge(2, 4);
  g1.addEdge(2, 5);
  g1.addEdge(3, 4);
  g1.addEdge(3, 5);
  g1.addEdge(4, 5);

  topologicalSOrt_BFS(g1);
  cout << "\n\n\n DFS based Topoogical Sorting\n";
  cout << "\n Graph 1\n\n";
  topologicalSort_DFS(g);
  cout << "\n Graph 1\n\n";

  cout << "\n Graph 2\n\n";
  topologicalSort_DFS(g1);
  cout << "\n Graph 2\n\n";

  return 0;
}
