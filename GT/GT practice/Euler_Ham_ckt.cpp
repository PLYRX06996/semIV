#include <iostream>
using namespace std;

// --- EULER CIRCUIT CHECK ---
bool checkEulerCircuit(int V, int graph[][100]) {
    for (int i = 0; i < V; i++) {
        int degree = 0;
        for (int j = 0; j < V; j++) {
            if (graph[i][j]) degree++;
        }
        if (degree % 2 != 0) {
            return false; // If any node has odd degree, no Euler circuit
        }
    }
    return true; // (Assuming graph is connected)
}

// --- HAMILTONIAN CIRCUIT CHECK ---
bool isSafe(int v, int graph[][100], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }
    return true;
}

bool hamCycleUtil(int graph[][100], int path[], int pos, int V) {
    // If all vertices are included
    if (pos == V) {
        // Check if there's an edge from last included vertex to the first
        if (graph[path[pos - 1]][path[0]] == 1) return true;
        else return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamCycleUtil(graph, path, pos + 1, V) == true) return true;
            path[pos] = -1; // Backtrack
        }
    }
    return false;
}

void checkHamiltonianCircuit(int V, int graph[][100]) {
    int path[100];
    for (int i = 0; i < V; i++) path[i] = -1;
    path[0] = 0; // Start at vertex 0

    if (hamCycleUtil(graph, path, 1, V) == false) {
        cout << "No Hamiltonian Circuit exists.\n";
    } else {
        cout << "Hamiltonian Circuit exists: ";
        for (int i = 0; i < V; i++) cout << path[i] << " ";
        cout << path[0] << "\n";
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
        graph[v][u] = 1;
    }

    if (checkEulerCircuit(V, graph)) cout << "Euler Circuit exists.\n";
    else cout << "No Euler Circuit exists.\n";

    checkHamiltonianCircuit(V, graph);

    return 0;
}