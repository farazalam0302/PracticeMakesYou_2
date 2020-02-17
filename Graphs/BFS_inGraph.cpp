/*
 * https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
 *
 * Level Nodes
 * You have been given a Tree consisting of N nodes. A tree is a fully-connected
 * graph consisting of N nodes and  edges. The nodes in this tree are indexed
 * from 1 to N. Consider node indexed 1 to be the root node of this tree. The
 * root node lies at level one in the tree. You shall be given the tree and a
 * single integer x . You need to find out the number of nodes lying on level x.
 *
 *
 * Input Format
 * The first line consists of a single integer N denoting the number of nodes in
 * the tree. Each of the next  lines consists of 2 integers a and b denoting an
 * undirected edge between node a and node b. The next line consists of a single
 * integer x.
 *
 * Output Format
 * You need to print a single integers denoting the number of nodes on level x.
 *
 * Constraints
 * Note: It is guaranteed that atleast one node shall lie on level x
 *
 */
#include <bits/stdc++.h>
using namespace std;

int bfs_nodes_in_level(vector<vector<int>> &adjList);

void printTree(vector<vector<int>> &adjList) {
  cout << "\n\n";
  int nodes = adjList.size();
  for (int i = 1; i < nodes; i++) {
    std::cout << "[" << i << "] --";
    for (auto k : adjList[i]) {
      cout << "-> " << k;
    }
    cout << "-> Null" << endl;
  }
  cout << "\n\n";
}

int bfs_nodes_in_level(vector<vector<int>> &adjList, int queryLevel, int root) {
  int nodes = adjList.size();
  vector<int> levelMap(nodes, 0);
  queue<int> Q;
  vector<bool> visited(nodes, false);
  Q.push(root);
  int level = 1;
  levelMap[level] = 1;

  visited[root] = true;

  while (!(Q.empty()) && level < queryLevel) {
    int p = Q.front();
    Q.pop();
    level++;
    for (int i = 0; i < adjList[p].size(); ++i) {
      if (visited[adjList[p][i]] == false) {
        Q.push(adjList[p][i]);
        visited[adjList[p][i]] = true;
        levelMap[level]++;
      }
    }
  }
  cout << "\n\n" << endl;
  for (int i = 0; i < nodes; ++i) {
    cout << levelMap[i] << " ";
  }
  cout << "\n\n" << endl;
  return levelMap[queryLevel];
}

int main(int argc, char **argv) {
  int nodes;
  cin >> nodes;
  int edges = nodes - 1;
  vector<vector<int>> adjList(nodes + 1);
  int x, y;
  for (int i = 1; i <= edges; ++i) {
    cin >> x;
    cin >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  int levelNo;
  cin >> levelNo;

  //  printTree(adjList);

  int res = bfs_nodes_in_level(adjList, levelNo, 1);
  cout << res << endl;
  printTree(adjList);

  return 0;
}
