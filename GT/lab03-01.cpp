#include<bits/stdc++.h>
using namespace std;

bool isSafe(int vertex, vector<vector<int>> &adjMat, vector<int> &path, int pos) {
    
    if (!adjMat[path[pos - 1]][vertex]) {
        return false;
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == vertex) {
            return false;
        }
    }

    return true;
}

bool hamCycleUtil(vector<vector<int>> &adjMat, vector<int> &path, int pos, int n) {
    
    if (pos == n) {
        
        return adjMat[path[pos - 1]][path[0]];
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, adjMat, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(adjMat, path, pos + 1, n)) {
                return true;
            }

            path[pos] = -1;
        }
    }

    return false;
}

vector<int> hamCycle(vector<vector<int>> &adjMat) {
    int n = adjMat.size();
    vector<int> path(n, -1);

    path[0] = 0;

    if (!hamCycleUtil(adjMat, path, 1, n)) {
        return {-1};
    }

    return path;
}

int main(){
    int V;
    cin >> V;
    vector<vector<int>> adjMat(V, vector<int>(V, 0));
    int E;
    cin >> E;
    for(int e = 0; e < E; e++){
        int i, j;
        cin >> i >> j;
        adjMat[i][j] = 1;
        adjMat[j][i] = 1;
    }
    vector<int> path = hamCycle(adjMat);
    
    if(path[0] == -1) {
        cout << "Solution does not Exist";
    }
    else {
        cout << "hamiltonian Cycle: ";
        for (int i = 0; i < path.size(); i++) {
           cout << path[i] << " ";
        }
        cout << path[0];
        cout << "hamiltonina path: ";
        for (int i = 0; i < path.size(); i++) {
           cout << path[i] << " ";
    }
}
    return 0;
}