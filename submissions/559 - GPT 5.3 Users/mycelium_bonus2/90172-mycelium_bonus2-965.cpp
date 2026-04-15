#include <bits/stdc++.h>
using namespace std;
using i2 = array<int, 2>;

int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};

void solve() {
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    
    // solve
    vector<i2> g{{xg, yg}}, m{{xm, ym}}, g2, m2;
    int ans = 0;
    set<i2> done;
    for (int i = 0; size(m); i++) {
        if (i % 2 == 0) {
            for (auto& [x, y] : g) {
                if (done.count({x, y})) continue;
                done.insert({x, y});
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (!done.count({nx, ny})) {
                        g2.push_back({nx, ny});
                    }
                }
            }
            swap(g, g2);
            g2.clear();
        }
        if (i % 7 == 0) {
            for (auto& [x, y] : m) {
                if (done.count({x, y})) continue;
                done.insert({x, y});
                ans++;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (!done.count({nx, ny})) {
                        m2.push_back({nx, ny});
                    }
                }
            }
            swap(m, m2);
            m2.clear();
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}