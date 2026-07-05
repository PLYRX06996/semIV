#include <bits/stdc++.h>
using namespace std;

const int HEADER2 = 20;

struct Frag {
    int id;
    int dataSize;
    int offset;
    int mf;
};

vector<Frag> fragment(int packetSize, int mtu, int id, int baseOffset = 0) {
    vector<Frag> frags;

    int maxData = mtu - HEADER2;
    int fragSize = (maxData / 8) * 8;

    int remaining = packetSize;
    int start = 0;

    while (remaining > 0) {
        Frag f;
        f.id = id;

        if (remaining > fragSize) {
            f.dataSize = fragSize;
            f.mf = 1;
        } else {
            f.dataSize = remaining;
            f.mf = 0;
        }

        f.offset = (baseOffset + start) / 8;

        frags.push_back(f);

        start += f.dataSize;
        remaining -= f.dataSize;
    }

    return frags;
}

bool reassemble(vector<Frag> frags, int originalSize) {
    int n = frags.size();

    for (int i = 0; i < n / 2; i++) {
        Frag temp = frags[i];
        frags[i] = frags[n - i - 1];
        frags[n - i - 1] = temp;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (frags[j].offset > frags[j + 1].offset) {
                Frag temp = frags[j];
                frags[j] = frags[j + 1];
                frags[j + 1] = temp;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++)
        total += frags[i].dataSize;

    return total == originalSize;
}

int main() {
    int packetSize, id, mtu1, mtu2;
    cin >> packetSize >> id >> mtu1 >> mtu2;

    vector<Frag> r1 = fragment(packetSize, mtu1, id);

    vector<Frag> r2;
    for (int i = 0; i < r1.size(); i++) {
        int base = r1[i].offset * 8;
        vector<Frag> temp = fragment(r1[i].dataSize, mtu2, id, base);
        for (int j = 0; j < temp.size(); j++)
            r2.push_back(temp[j]);
    }

    for (int i = 0; i < r2.size(); i++) {
        cout << r2[i].dataSize << " "
             << r2[i].offset << " "
             << r2[i].mf << endl;
    }

    cout << reassemble(r2, packetSize) << endl;

    return 0;
}
