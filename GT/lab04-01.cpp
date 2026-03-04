#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int S, D, W;
    Edge(int s,int d,int w): S(s), D(d), W(w) {}  
};

class DSU{
    private:
    vector<int> rank, parent;

    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int findParent(int v){
        if(parent[v] != v) parent[v] = findParent(parent[v]);
        return parent[v];
    }
    void unite(int r1,int r2){
        int p1 = findParent(r1), p2 = findParent(r2);

        if(p1 == p2) return;
        if(rank[p1] > rank[p2]) parent[p2] = p1;
        else if(rank[p2] > rank[p1]) parent[p1] = p2;
        else parent[p2] = p1;
    }
};

vector<Edge> kruskal(int modV, vector<Edge>& edges){
    sort(edges.begin(), edges.end());

    DSU T(modV);
    vector<Edge> mst;
    int mstWeight = 0;
    int edgesUsed = 0;
     for (const Edge& edge : edges) {
        if (T.findParent(edge.S) != T.findParent(edge.D)) {
            mst.push_back(edge);
            mstWeight += edge.W;
            T.unite(edge.S, edge.D);
            edgesUsed++;
            
            if (edgesUsed == modV - 1) {
                break;
            }
        }
    }
     cout << "Total MST Weight: " << mstWeight << endl;
    return mst;
}