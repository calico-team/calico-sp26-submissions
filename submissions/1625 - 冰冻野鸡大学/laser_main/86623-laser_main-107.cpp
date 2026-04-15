
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// helper function to encode asteroid coordinates into a single key
long long encode(int x, int y, int M) {
    return (long long)x * (M + 1) + y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<int> a(K), b(K); // asteroid coordinates
        for (int i = 0; i < K; i++) {
            cin >> a[i] >> b[i];
        }

        // starting position is the first asteroid
        int x = a[0], y = b[0];

        // store asteroid positions for quick lookup
        unordered_map<long long, int> pos;
        for (int i = 0; i < K; i++) {
            pos[encode(a[i], b[i], M)] = i;
        }

        // simulate laser movement
        while (true) {
            x = (x + Q) % N;
            y = (y + P) % M;

            long long key = encode(x, y, M);
            if (pos.count(key)) {
                cout << pos[key] << "\n";
                break;
            }
        }
    }
    return 0;
}

