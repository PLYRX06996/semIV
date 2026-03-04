#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int n, int cost[20][20], int dist[20], int nextHop[20]) {
    for (int i = 0; i < n; i++) {
        dist[i] = cost[0][i];
        nextHop[i] = i;
    }

    for (int k = 0; k < n - 1; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i] > dist[j] + cost[j][i]) {
                    dist[i] = dist[j] + cost[j][i];
                    nextHop[i] = j;
                }
            }
        }
    }
}

void printRoutingTable(int n, int dist[20], int nextHop[20]) {
    cout << "\nRouting Table for Router 0:\n";
    cout << "Destination\tCost\tNext Hop\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t\t" << dist[i] << "\t" << nextHop[i] << endl;
    }
}

int main() {
    int n;
    int cost[20][20], dist[20], nextHop[20];

    cout << "Enter number of routers: ";
    cin >> n;

    cout << "Enter cost matrix (use 999 for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    bellmanFord(n, cost, dist, nextHop);
    printRoutingTable(n, dist, nextHop);

    return 0;
}
