#include<bits/stdc++.h>
using namespace std;

class graph{
    private:
    vector<vector<int>> G;
    int N;
    public:
    graph(int n){
        N = n;
        G.resize(N);
    }
    void addEdge(int source, int destination, int weight)
};



int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int graph[n][n] = {};
    for(int i = 0; i < n; i++) graph[i][i] = 0;
    cout << "Enter number of edges: ";
    int e;
    cin >> e;
    cout << "Enter the edge weight(w) for i to j where i, j <= n:(i j w) " << endl;
    while(e > 0){
        int i, j, w;
        cin >> i >> j >> w;
        graph[i][j] = w;
        e--;
    }
    
    cout << "printing the entered graph: " <<  endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] == 0 && i != j) cout << "INF" << "\t";
            else cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
            
    return 0;
}