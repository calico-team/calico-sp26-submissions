#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, n, m, q, p;
        cin >> k >> n >> m >> p >> q;
        int plane[n][m];
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                plane[i][j] = -1;
        int lx, ly;
        cin >> lx >> ly;
        plane[lx][ly] = 0;
        for (int i = 0; i < k-1; i++) {
            int x, y;
            cin >> x >> y;
            plane[x][y] = i+1;
        }
        while (true) {
            lx += q;
            lx %= n;
            ly += p;
            ly %= m;
            if (plane[lx][ly] == -2) {
                cout << -1 << endl;
                break;
            } else if (plane[lx][ly] != -1) {
                cout << plane[lx][ly] << endl;
                break;
            }
            plane[lx][ly] = -2;
        }
    }
}