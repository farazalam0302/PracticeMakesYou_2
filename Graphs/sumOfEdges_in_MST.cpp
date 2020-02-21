/*
 *
 *
 * Minimum Spanning Tree
Given a weighted undirected graph. Find the sum of weights of edges of a Minimum
Spanning Tree.

Input:
Given 2 integers N and M. N represents the number of vertices in the graph. M
represents the number of edges between any 2 vertices. Then M lines follow, each
line has 3 space separated integers  , ,  where  and  represents an edge from a
vertex  to a vertex  and  respresents the weight of that edge.

4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6


Output:
Print the summation of edges weights in the MST.




Constraints:
 *
 *
 *
 * */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> PII;
const int max1 = 1e5 + 5;

long long prims(vector<vector<PII>>& adjList, int x) {
  priority_queue<PII, vector<PII>, greater<PII>> Q;  // min heap
  int y;
  long long minimumCost = 0;
  PII p;
  int n = adjList.size();
  vector<bool> marked(n, false);
  Q.push(make_pair(0, x));
  while (!Q.empty()) {
    p = Q.top();
    Q.pop();
    x = p.second;
    if (marked[x] == true) continue;
    minimumCost = minimumCost + p.first;
    marked[x] = true;
    for (int i = 0; i < adjList[x].size(); i++) {
      y = adjList[x][i].second;
      if (marked[y] == false) {
        Q.push(adjList[x][i]);
      }
    }
  }
  return minimumCost;
}

int main(int argc, char** argv) {
  int n, m;
  cin >> n;
  cin >> m;
  int x, y, weight;
  vector<vector<PII>> adjList(max1);

  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> weight;
    adjList[x].push_back(make_pair(weight, y));
    adjList[y].push_back(make_pair(weight, x));
  }
  int minimumCost = prims(adjList, 1);

  cout << minimumCost << endl;

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
