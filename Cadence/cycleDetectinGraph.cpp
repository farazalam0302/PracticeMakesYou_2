#include <bits/stdc++.h>
using namespace std;

enum status { underProcess, Processed, unTouched };

void displayGraph(vector<list<int>> &adjList) {
  int n = adjList.size();
  for (int i = 0; i < n; ++i) {
    cout << i << " -> ";
    for (auto adjV : adjList[i]) {
      cout << adjV << ", ";
    }
    cout << endl;
  }
}

bool dfsUtility(vector<list<int>> &adjList, int node, vector<int> &Status,
                int parentNode) {

  Status[node] = status::underProcess;

  for (auto adjacentNode : adjList[node]) {
    if (Status[adjacentNode] == status::underProcess) {
      return true;
    }
    if (Status[adjacentNode] == status::unTouched &&
        dfsUtility(adjList, adjacentNode, Status, adjacentNode)) {
      return true;
    } else if (parentNode != adjacentNode)
      return true;
  }

  //  dfsUtility(adjList, node, Status)
  Status[node] = status::Processed;
  return false;
}

/*
 *  for (int node = 0; node < vertices; ++node)
        {
        if (colour[node] == WHITE)
            {
            result = detectCycle_viaColors(adjList, node, colour);
            }
        }
 */

bool cycleDetected(vector<list<int>> &adjList) {
  int vertices = adjList.size();
  vector<int> Status(vertices, unTouched);

  bool result = false;
  for (int node = 0; node < vertices; ++node) {
    if (Status[node] == unTouched) {
      result = dfsUtility(adjList, node, Status, -1);
    }
  }

  return result;
}

int main(int argc, char **argv) {

  vector<pair<int, int>> edges{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
  int vertices = 5;
  vector<list<int>> adjList(vertices);

  for (auto edge : edges) {
    adjList[edge.first].push_back(edge.second);
    adjList[edge.second].push_back(edge.first);
  }

  displayGraph(adjList);

  if (cycleDetected(adjList)) {
    cout << "Yes cycle is there\n";
  } else {
    cout << "No cycle isn't  there\n";
  }

  return 0;
}
