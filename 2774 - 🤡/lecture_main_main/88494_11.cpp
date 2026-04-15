#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e3+5;

int p[2*mxN][2*mxN];

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s[n];
    for (auto &e : s) cin >> e;
    int mx = max(n, m) + 1;
    for (int i = 0; i <= 2*mx; i++) for (int j = 0; j <= 2*mx; j++) p[i][j] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (s[i][j] == '-') p[i+j+1][i-j+mx]++;
    }
    auto calc = [&] (int x, int y) {
        return make_pair(x+y+1, x-y+mx);
    };
    auto rec = [&] (int x, int y) {
        int xpy = x-1;
        int xmy = y-mx;
        return make_pair((xpy+xmy)/2, (xpy-xmy)/2);
    };
    // for (int i = 1; i <= 2*mx; i++) {
    //     for (int j = 1; j <= 2*mx; j++) {
    //         cout << p[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= 2*mx; i++) {
        for (int j = 1; j <= 2*mx; j++) p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    }
    auto cc = [&] (int x1, int y1, int x2, int y2) {
        x1 = max(0, x1);
        y1 = max(0, y1);
        x2 = min(2*mx, x2);
        y2 = min(2*mx, y2);
        return p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1];
    };
    int L = 0, R = mx, ans = 67;
    while (L <= R) {
        int x = L + (R-L)/2;
        int ok = 0;
        for (int p = 1; p <= 2*mx; p++) {
            if (ok) break;
            for (int q = 1; q <= 2*mx; q++) {
                if (cc(p-1, q-1, p+x-1, q+x-1) >= k) { /*cout << p << ' ' << q << '\n';*/ ok = 1; break; }
            }
        }
        if (ok) R = x-1, ans = x;
        else L = x+1;
    }
    // cout << ans << '\n';
    int x = ans;
    for (int p = 1; p <= 2*mx; p++) {
        for (int q = 1; q <= 2*mx; q++) {
            if (cc(p-1, q-1, p+x-1, q+x-1) >= k) {
                vector <pair <int, int>> ans;
                for (int i = p; i <= p+x-1; i++) {
                    for (int j = q; j <= q+x-1; j++) {
                        if (cc(i-1, j-1, i, j)) ans.emplace_back(rec(i, j));
                    }
                }
                for (int i = 0; i < k; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}

