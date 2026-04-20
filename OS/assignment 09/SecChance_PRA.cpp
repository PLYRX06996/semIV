#include <bits/stdc++.h>
using namespace std;

pair<int,double> sc(vector<int> v, int k) {
    vector<int> fr(k, -1), ref(k, 0);
    int p = 0, f = 0;

    for (int x : v) {
        bool ok = false;
        for (int i = 0; i < k; i++) {
            if (fr[i] == x) {
                ref[i] = 1;
                ok = true;
                break;
            }
        }
        if (!ok) {
            while (ref[p] == 1) {
                ref[p] = 0;
                p = (p + 1) % k;
            }
            fr[p] = x;
            ref[p] = 1;
            p = (p + 1) % k;
            f++;
        }
    }
    return {f, (double)f / v.size()};
}

int main() {
    int n, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> k;

    auto ans = sc(v, k);
    cout << ans.first << endl;
    cout << ans.second;
}