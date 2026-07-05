#include <iostream>
#include <vector>

using namespace std;

int n, e;
vector<vector<int>> g;
vector<int> p, v;

bool ham(int u, int d, bool &c) {
    p.push_back(u); 
    v[u] = 1;
    if(d == n) {
        if(g[u][p[0]]) c = true;
        return true;
    }
    for(int i = 0; i < n; ++i) {
        if(g[u][i] && !v[i]) {
            if(ham(i, d + 1, c)) return true;
        }
    }
    p.pop_back(); 
    v[u] = 0;
    return false;
}

void solve() {
    cin >> n >> e;
    g.assign(n, vector<int>(n, 0));
    v.assign(n, 0); 
    p.clear();
    for(int i = 0; i < e; ++i) {
        int x, y; 
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    bool c = false;
    if(ham(0, 1, c)) cout << "Path: 1, Circuit: " << c << "\n";
    else cout << "Path: 0, Circuit: 0\n";
}

int main() {
    solve();
    return 0;
}   