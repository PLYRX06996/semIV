#include <bits/stdc++.h>
using namespace std;

vector<int> bestFit(vector<int> b, vector<int> p) {
    int m = b.size(), n = p.size();
    vector<int> a(n, -1);

    for (int i = 0; i < n; i++) {
        int idx = -1;
        for (int j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                if (idx == -1 || b[j] < b[idx]) idx = j;
            }
        }
        if (idx != -1) {
            a[i] = idx;
            b[idx] -= p[i];
        }
    }
    return a;
}

vector<int> worstFit(vector<int> b, vector<int> p) {
    int m = b.size(), n = p.size();
    vector<int> a(n, -1);

    for (int i = 0; i < n; i++) {
        int idx = -1;
        for (int j = 0; j < m; j++) {
            if (b[j] >= p[i]) {
                if (idx == -1 || b[j] > b[idx]) idx = j;
            }
        }
        if (idx != -1) {
            a[i] = idx;
            b[idx] -= p[i];
        }
    }
    return a;
}

int main() {
    int m, n;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> bf = bestFit(b, p);
    vector<int> wf = worstFit(b, p);

    for (int x : bf) cout << x + 1 << " ";
    cout << endl;
    for (int x : wf) cout << x + 1 << " ";
}