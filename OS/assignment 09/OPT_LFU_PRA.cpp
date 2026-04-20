#include <bits/stdc++.h>
using namespace std;

int lfu(vector<int> v, int k) {
    unordered_map<int,int> f;
    vector<int> fr;
    int res = 0;

    for (int x : v) {
        if (find(fr.begin(), fr.end(), x) == fr.end()) {
            res++;
            if (fr.size() < k) fr.push_back(x);
            else {
                int y = fr[0];
                for (int z : fr) if (f[z] < f[y]) y = z;
                fr.erase(find(fr.begin(), fr.end(), y));
                fr.push_back(x);
            }
        }
        f[x]++;
    }
    return res;
}

int opt(vector<int> v, int k) {
    vector<int> fr;
    int res = 0;

    for (int i = 0; i < v.size(); i++) {
        if (find(fr.begin(), fr.end(), v[i]) == fr.end()) {
            res++;
            if (fr.size() < k) fr.push_back(v[i]);
            else {
                int idx = -1, far = i;
                for (int j = 0; j < fr.size(); j++) {
                    int t;
                    for (t = i + 1; t < v.size(); t++)
                        if (fr[j] == v[t]) break;

                    if (t == v.size()) {
                        idx = j;
                        break;
                    }
                    if (t > far) {
                        far = t;
                        idx = j;
                    }
                }
                fr[idx] = v[i];
            }
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> k;

    cout << lfu(v, k) << endl;
    cout << opt(v, k);
}