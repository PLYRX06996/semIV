#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int d, w;
};

class graph
{
private:
    vector<vector<Edge>> adjList;
    bool isDirected;

public:
    graph(int noOfver, bool directed = false)
    {
        adjList.resize(noOfver);
        isDirected = directed;
    }
    void addEdge(int source, int destination, int weight)
    {
        Edge e = {destination, weight};
        adjList[source].push_back(e);
        if ( !isDirected)
        {
            Edge temp = {source, weight};
            adjList[destination].push_back(temp);
        }
    }
    void printGraph()
    {
        if (isDirected)
            cout << "Directed graph Adjacency List:" << endl;
        else
            cout << "Undirected graph Adjacency List:" << endl;
        for (int i = 0; i < adjList.size(); i++)
        {
            cout << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++)
            {
                cout << "(" << adjList[i][j].d << ", " << adjList[i][j].w << ") -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    int numOfver;
    cout << "Enter the number of vertices of the graph: ";
    cin >> numOfver;
    int numOfedges;
    cout << "Enter the number of edges: ";
    cin >> numOfedges;
    bool isdirected;
    cout << "is the graph directed?: ";
    cin >> isdirected;
    graph g(numOfver, isdirected);
    cout << "Enter the edge as (source, destination, weight)" << endl;
    for(int i = 0; i < numOfedges; i++){
        int s, d, w;
        cin >> s >> d >> w;
        g.addEdge(s, d, w);
    }
    g.printGraph();
    return 0;
}


void test(){
    list<vector<int>> l;
    vector<list<int>> L;

}