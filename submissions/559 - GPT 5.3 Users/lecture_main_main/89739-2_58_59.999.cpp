#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int z = n+m+1;
    vector cc(z, vector<int>(z));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char _;
            cin >> _;
            if (_ == '-') cc[i+j][i-j+m] = 1;
        }
    }
    auto c = cc;
    for (int i = 0; i < z; i++) {
        for (int j = 0; j < z; j++) {
            if (i > 0) c[i][j] += c[i-1][j];
            if (j > 0) c[i][j] += c[i][j-1];
            if (i > 0 && j > 0) c[i][j] -= c[i-1][j-1];
        }
    }

    // solve
    auto cnt = [&](int l1, int l2, int r1, int r2) -> int {
        int r = c[l2][r2];
        if (l1 >= 0) r -= c[l1][r2];
        if (r1 >= 0) r -= c[l2][r1];
        if (l1 >= 0 && r1 >= 0) r += c[l1][r1];
        return r;
    };
    auto check = [&](int md) -> bool {
        for (int i = -1; i+md < z; i++) {
            for (int j = -1; j+md < z; j++) {
                if (cnt(i, i+md, j, j+md) >= k) {
                    return true;
                }
            }
        }
        return false;
    };
    int l = 1, r = n+m;
    while (l < r) {
        int md = (l + r) / 2;
        if (check(md)) r = md;
        else l = md + 1;
    }
    int md = l;
    for (int i = -1; i+md < z; i++) {
        for (int j = -1; j+md < z; j++) {
            if (cnt(i, i+md, j, j+md) >= k) {
                // find cells
                int t = 0;
                for (int x = i+1; x <= i+md; x++) {
                    for (int y = j+1; y <= j+md; y++) {
                        if (cc[x][y] == 1) {
                            if (t > k) break;
                            // u+v,u-v+m
                            int u = (x+y-m)/2;
                            int v = x-u;
                            cout << u << ' ' << v << '\n';
                            t++;
                        }
                    }
                }
                return;
            }
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}