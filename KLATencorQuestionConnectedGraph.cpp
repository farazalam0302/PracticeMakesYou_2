#include <bits/stdc++.h>
using namespace std;

void displayGraph(vector<list<int>> &G) {
	int n = G.size();
	for (int i = 0; i < n; ++i) {
		cout << i << " -> ";
		for (auto v : G[i]) {
			cout << v << " - ";
		}
		cout << endl;
	}
}

void dfsCompute(vector<list<int>> &G_adjList, int node, vector<bool> &visited,
		int &count) {
	if (visited[node])
		return;

	count++;
	visited[node] = true;
	if (G_adjList[node].size() == 0)
		return;
	for (auto it = G_adjList[node].begin(); it != G_adjList[node].end(); it++) {
		dfsCompute(G_adjList, *it, visited, count);
	}

}

int computeCost(int nodes, vector<int> &graph_from, vector<int> &graph_to) {
//	unordered_map<int, list<int>> G_adjList;
	vector<list<int>> G_adjList(nodes + 1);
	int edges = graph_from.size();
	for (int i = 0; i < edges; ++i) {

		G_adjList[graph_from[i]].push_back(graph_to[i]);
//		G_adjList[graph_to[i]].push_back(graph_from[i]);

	}

	displayGraph(G_adjList);
	vector<bool> visited(nodes + 1, false);

//	for (auto i : visited ) {
//		cout << i << ", ";
//
//	}
	cout << endl;
	int countInGroup;
	int computeCost = 0;
	for (int node = 1; node <= nodes; ++node) {
		if (!visited[node]) {
			countInGroup = 0;
			dfsCompute(G_adjList, node, visited, countInGroup);
//			cout << "countinGroup = " << countInGroup << endl;
			computeCost = computeCost + ceil(sqrt(countInGroup));
//			cout << "computeCost = " << computeCost << endl;

		}

	}
	return computeCost;

}
void displayMap(unordered_map<int, list<int>> &G_adjList) {
	for (auto pairr : G_adjList) {
		cout << pairr.first << " -> ";
		for (auto node : pairr.second) {
			cout << node << " - ";

		}
		cout << endl;

	}
}

void dfsCompute_Map(unordered_map<int, list<int>> &G_adjList, int node,
		vector<bool> &visited, int &count) {

	if (visited[node])
		return;
	visited[node] = true;
	count++;

	for (auto it : G_adjList[node]) {
		dfsCompute_Map(G_adjList, it, visited, count);
	}

}

int computeCost_Map(int nodes, vector<int> &graph_from, vector<int> &graph_to) {
	unordered_map<int, list<int>> G_adjList;
	int edges = graph_from.size();
	for (int i = 0; i < edges; ++i) {
		G_adjList[graph_from[i]].push_back(graph_to[i]);
//		G_adjList[graph_to[i]].push_back(graph_from[i]);

	}
	displayMap(G_adjList);

	int nodesTraversed = 0;
	int nodesCountInGroup = 0;
	int cost = 0;
	vector<bool> visited(nodes + 1, false);

	for (int node = 1; node <= nodes; ++node) {
		if (!visited[node]) {
			nodesCountInGroup = 0;
			dfsCompute_Map(G_adjList, node, visited, nodesCountInGroup);
			nodesTraversed += nodesCountInGroup;
			cost = cost + ceil(sqrt(nodesCountInGroup));
		}

	}
	cost = cost + (nodes - nodesTraversed);

	return cost;

}

int main(int argc, char **argv) {

	vector<int> graph_from /*{ 1, 1 };*/{ 1, 1, 2, 3, 7 };
	vector<int> graph_to /*{ 2, 4 };*/{ 2, 3, 4, 5, 8 };
	int nodes = 10;

	int result = computeCost(nodes, graph_from, graph_to);
	cout << "result  = " << result << endl;

	cout
			<< "\n\n--------------------------------------------------------------\n\n";
	result = computeCost_Map(nodes, graph_from, graph_to);
	cout << "\nresult  = " << result << endl;
	return 0;
}
