#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, int cost[20][20], int dist[20], int source) {
    int visited[20];

    for (int i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for (int count = 1; count < n; count++) {
        int min = 999, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            return;

        visited[u] = 1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] > dist[u] + cost[u][i]) {
                dist[i] = dist[u] + cost[u][i];
            }
        }
    }
}

void printShortestPaths(int n, int dist[20]) {
    cout << "\nShortest paths from Router 0:\n";
    for (int i = 0; i < n; i++) {
        cout << "To Router " << i << " = " << dist[i] << endl;
    }
}

int main() {
    int n;
    int cost[20][20], dist[20];

    cout << "Enter number of routers: ";
    cin >> n;

    cout << "Enter adjacency matrix (use 999 for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    dijkstra(n, cost, dist, 0);
    printShortestPaths(n, dist);

    return 0;
}
