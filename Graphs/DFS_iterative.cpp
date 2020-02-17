/*
 * DFS_iterative.cpp
 *
 * Created on: 17-Feb-2020
 *      Author: faraz
 *
 *
 *      Depth First Search (DFS)

                The DFS algorithm is a recursive algorithm that uses the idea of
 backtracking. It involves exhaustive searches of all the nodes by going ahead,
 if possible, else by backtracking.

                Here, the word backtrack means that when you are moving forward
 and there are no more nodes along the current path, you move backwards on the
 same path to find nodes to traverse. All the nodes will be visited on the
 current path till all the unvisited nodes have been traversed after which the
 next path will be selected.

                This recursive nature of DFS can be implemented using stacks.
 The basic idea is as follows: Pick a starting node and push all its adjacent
 nodes into a stack. Pop a node from stack to select the next node to visit and
 push all its adjacent nodes into a stack. Repeat this process until the stack
 is empty. However, ensure that the nodes that are visited are marked. This will
 prevent you from visiting the same node more than once. If you do not mark the
 nodes that are visited and you visit the same node more than once, you may end
 up in an infinite loop.


 *
 *
 *
 *Unreachable Nodes
You have been given a graph consisting of N nodes and M edges. The nodes in this
graph are enumerated from 1 to N . The graph can consist of self-loops as well
as multiple edges. This graph consists of a special node called the head node.
You need to consider this and the entry point of this graph. You need to find
and print the number of nodes that are unreachable from this head node.

Input Format

The first line consists of a 2 integers N and M denoting the number of nodes and
edges in this graph. The next M lines consist of 2 integers a and b denoting an
undirected edge between node a and b. The next line consists of a single integer
x denoting the index of the head node.

*Output Format *:

You need to print a single integer denoting the number of nodes that are
unreachable from the given head node.

SAMPLE INPUT
10 10
8 1
8 3
7 4
7 5
2 6
10 7
2 8
10 9
2 10
5 10
2

##########

10
8
1 2
1 3
3 4
4 2
5 6
6 7
8 10
8 9
1
 *
 */

#include <bits/stdc++.h>
using namespace std;

void printGraph(vector<vector<int>> &adj) {
  cout << "\n\n";
  for (int i = 1; i < adj.size(); i++) {
    std::cout << "[" << i << "] --";
    for (auto k : adj[i]) {
      cout << "-> " << k;
    }
    cout << "-> Null" << endl;
  }
  cout << "\n\n";
}

void printGraphMatrix(vector<vector<int>> &adjMatrix) {
  int nodes = adjMatrix.size();
  for (auto i : adjMatrix) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}
int dfs_iterative(vector<vector<int>> &adjList, int root) {
  int nodes = adjList.size();
  vector<bool> visited(nodes, false);
  visited[0] = true;  // avoid zero index; to see only 1 to N
  stack<int> mstack;
  mstack.push(root);
  visited[root] = true;
  int t;
  while (!(mstack.empty())) {
    t = mstack.top();
    mstack.pop();
    for (auto i : adjList[t]) {
      if (visited[i] == false) {
        mstack.push(i);
        visited[i] = true;
      }
    }
  }
  int count = 0;
  for (auto i : visited) {
    if (!i) count++;
  }
  return count;
}

int dfs_iterative_adjMatrix(vector<vector<int>> &adjMatrix, int root) {
  int nodes = adjMatrix.size();
  vector<bool> visited(nodes, false);
  visited[0] = true;
  stack<int> mstack;
  mstack.push(root);
  visited[root] = true;
  int t;
  while (!(mstack.empty())) {
    t = mstack.top();
    mstack.pop();
    for (int i = 1; i <= nodes; ++i) {
      if (!visited[i] && adjMatrix[t][i] != 0) {
        mstack.push(i);
        visited[i] = true;
      }
    }
  }
  int count = 0;
  for (auto i : visited) {
    if (!i) count++;
  }
  return count;
}
// TO DO:
int No_of_components_dfs(vector<vector<int>> &adjList, int root) {
  int nodes = adjList.size();
  vector<bool> visited(nodes, false);
  visited[0] = true;  // avoid zero index; to see only 1 to N
  stack<int> mstack;
  mstack.push(root);
  visited[1] = true;
  int t;
  int i = 1;
  int connectedComponent = 0;
  while (i < nodes) {
    if (mstack.empty() && visited[i] == false) {
      connectedComponent++;
      i++;
      continue;
    }
    t = mstack.top();
    mstack.pop();

    for (auto i : adjList[t]) {
      if (visited[i] == false) {
        mstack.push(i);
        visited[i] = true;
      }
    }

    i++;
  }
  //  int count = 0;
  //  for (auto i : visited) {
  //    if (!i) count++;
  //  }
  return connectedComponent;
}

int main(int argc, char **argv) {
  int nodes, edges;
  //  cout << "\nenter #nodes " << endl;
  cin >> nodes;
  //  cout << "\nenter #edges " << endl;
  cin >> edges;
  vector<vector<int>> adjList(nodes + 1);

  vector<vector<int>> adjMatrix(nodes + 1, vector<int>(nodes + 1, 0));
  int x, y;
  for (int i = 0; i < edges; ++i) {
    cin >> x;
    cin >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
    adjMatrix[x][y] = 1;
    adjMatrix[y][x] = 1;
  }
  //  cout << "enter root" << endl;
  cin >> x;
  printGraph(adjList);
  printGraphMatrix(adjMatrix);

  int r = dfs_iterative(adjList, x);
  cout << "\n\n" << r << endl;

  r = dfs_iterative_adjMatrix(adjMatrix, x);
  cout << "\n\n" << r << endl;

  r = No_of_components_dfs(adjList, x);
  cout << "\n\n" << r << endl;
  return 0;
}
