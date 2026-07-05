#include <iostream>
using namespace std;

void DFS(int u, int V, int graph[][100], bool visited[]) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < V; v++) {
        if (graph[u][v] == 1 && !visited[v]) {
            DFS(v, V, graph, visited);
        }
    }
}

void BFS(int start, int V, int graph[][100]) {
    bool visited[100] = {false};
    int queue[100];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        cout << u << " ";
        for (int v = 0; v < V; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int graph[100][100] = {0};
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start, V, graph);
    cout << "\nDFS Traversal: ";
    
    bool visited[100] = {false};
    DFS(start, V, graph, visited);
    cout << "\n";

    return 0;
}