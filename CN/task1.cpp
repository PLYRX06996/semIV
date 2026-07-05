#include <bits/stdc++.h>
using namespace std;

const int HEADER = 20;

struct Fragment {
    int id;
    int dataSize;
    int offset; // in 8-byte units
    int mf;
};

vector<Fragment> fragmentPacket(int packetSize, int mtu, int id) {
    vector<Fragment> frags;

    int maxData = mtu - HEADER;
    int fragSize = (maxData / 8) * 8;

    int remaining = packetSize;
    int start = 0;

    while (remaining > 0) {
        Fragment f;
        f.id = id;

        if (remaining > fragSize) {
            f.dataSize = fragSize;
            f.mf = 1;
        } else {
            f.dataSize = remaining;
            f.mf = 0;
        }

        f.offset = start / 8;

        frags.push_back(f);

        start += f.dataSize;
        remaining -= f.dataSize;
    }

    return frags;
}

bool reassemble(vector<Fragment> frags, int originalSize) {
    int n = frags.size();
    for (int i = 0; i < n / 2; i++) {
        Fragment temp = frags[i];
        frags[i] = frags[n - i - 1];
        frags[n - i - 1] = temp;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (frags[j].offset > frags[j + 1].offset) {
                Fragment temp = frags[j];
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
    int packetSize, mtu, id;
    cin >> packetSize >> mtu >> id;

    vector<Fragment> fragments = fragmentPacket(packetSize, mtu, id);

    for (int i = 0; i < fragments.size(); i++) {
        cout << fragments[i].dataSize << " "
             << fragments[i].offset << " "
             << fragments[i].mf << endl;
    }

    cout << reassemble(fragments, packetSize) << endl;

    return 0;
}
