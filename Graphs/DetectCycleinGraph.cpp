#include <bits/stdc++.h>
using namespace std;
void displayGraph(vector<list<int>> &adjList)
    {
    int n = adjList.size();
    for (int i = 0; i < n; ++i)
	{
	cout << i << " -> ";
	for (auto adjV : adjList[i])
	    {
	    cout << adjV << ", ";

	    }

	cout << endl;
	}

    }

bool detectCycle(vector<list<int>> &adjList, int node, vector<bool> &visited,
	vector<bool> &recStack)
    {
    if (!visited[node])
	{
	visited[node] = true;
	recStack[node] = true;

	for (auto adjV : adjList[node])
	    {
	    if (!visited[adjV] && detectCycle(adjList, adjV, visited, recStack))
		{
		return true;
		}
	    else if (recStack[adjV])
		return true;
	    }
	}

    recStack[node] = false;

    return false;
    }

int main(int argc, char **argv)
    {

    vector<pair<int, int>> edges
	{
	    {
	    0, 1
	    },
	    {
	    1, 2
	    },
	    {
	    1, 3
	    },
	    {
	    4, 2
	    },
	    {
	    3, 4
	    },
	    {
	    4, 5
	    },
	    {
	    5, 1
	    }
	};

    int vertices = 6;
    vector<list<int>> adjList(vertices);

    for (auto ePair : edges)
	{
	adjList[ePair.first].push_back(ePair.second);

	}
    displayGraph(adjList);

    vector<bool> visited(vertices, false);

    vector<bool> recStack(vertices, false);

    bool result;

    for (int i = 0; i < vertices; ++i)
	{
	if (!visited[i])
	    result = detectCycle(adjList, i, visited, recStack);
	}
    result ? cout << "Yes cycle detected\n" : cout << "No cycle Detected\n";

    return 0;
    }
