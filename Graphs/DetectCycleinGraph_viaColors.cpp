#include <bits/stdc++.h>
using namespace std;

enum Color
    {
    BLACK,
    GREY,
    WHITE
    };

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
bool detectCycle_viaColors(vector<list<int>> &adjList, int node,
	vector<int> &colour)
    {
    colour[node] = GREY;
    for (auto adjNode : adjList[node])
	{
	if (colour[adjNode] == GREY)
	    return true;

	if (colour[adjNode] == WHITE
		&& detectCycle_viaColors(adjList, adjNode, colour))
	    {
	    return true;
	    }

	}
    colour[node] = BLACK;
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
//	    {
//	    4, 2
//	    },
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

//    vector<bool> visited(vertices, false);
    vector<int> colour(vertices, WHITE);

    bool result;

    for (int node = 0; node < vertices; ++node)
	{
	if (colour[node] == WHITE)
	    {
	    result = detectCycle_viaColors(adjList, node, colour);
	    }
	}

    result ? cout << "Yes cycle detected\n" : cout << "No cycle Detected\n";

    return 0;
    }
