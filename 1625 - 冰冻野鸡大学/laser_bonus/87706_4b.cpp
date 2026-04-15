#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q; 
        vector<int> a(K), b(K); // asteroid coordinate 
        
        vector<vector<int> > grid(N, vector<int>(M, -1));

        for (int i = 0; i < K; i++) {
            cin >> a[i] >> b[i];
            grid[a[i]][b[i]] = i; // mark asteroid index at its position
        }

        // simulate laser movement
        int x = a[0], y = b[0];

        // simulate laser movement until it hits an asteroid
        while (true) {
            x = (x + Q) % N;
            y = (y + P) % M;

            if (grid[x][y] != -1) {
                cout << grid[x][y] << "\n";
                break;
            }
        }
    }
    return 0;
}

