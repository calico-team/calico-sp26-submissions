#include <bits/stdc++.h>
using namespace std;
using i2 = array<int, 2>;

int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};

struct Hash {
    size_t operator()(const i2 &x) const {
        return (x[0] * 9219372892389LL + x[1] * 172893721LL);
    }
};

void solve() {
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    
    // solve
    vector<i2> g{{xg, yg}}, m{{xm, ym}}, g2, m2;
    int ans = 0;
    unordered_map<i2, bool, Hash> done;
    auto ism = [&](int x, int y) {
        auto it = done.find({x, y});
        return it != done.end() && it->second;
    };
    auto adj4 = [&](int x, int y) {
        for (int d = 0; d < 4; d++) {
            if (ism(x + dx[d], y + dy[d])) return true;
        }
        return false;
    };
    auto adj8 = [&](int x, int y) {
        for (int ox = -1; ox <= 1; ox++) {
            for (int oy = -1; oy <= 1; oy++) {
                if (!ox && !oy) continue;
                if (ism(x + ox, y + oy)) return true;
            }
        }
        return false;
    };
    bool limit_grass = false;
    for (int i = 0; size(m); i++) {
        if (i % 2 == 0) {
            for (auto& [x, y] : g) {
                if (!done.emplace(i2{x, y}, false).second) continue;
                if (!limit_grass && adj4(x, y)) limit_grass = true;
                if (limit_grass && !adj8(x, y)) continue;
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
                if (!done.emplace(i2{x, y}, true).second) continue;
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