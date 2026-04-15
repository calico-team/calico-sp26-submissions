#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i2 = array<int, 2>;

int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};

struct Hash {
    size_t operator()(const i2 &x) const {
        return (size_t)(x[0] * 1000003LL ^ (x[1] + 0x9e3779b97f4a7c15ULL));
    }
};

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
};

int dim_cnt(int r) {
    if (r < 0) return 0;
    return 1 + 2 * r * (r + 1);
};

vector<i2> ring(int sx, int sy, int r) {
    vector<i2> res;
    for (int dx0 = -r; dx0 <= r; dx0++) {
        int dy0 = r - abs(dx0);
        res.push_back({sx + dx0, sy + dy0});
        if (dy0) res.push_back({sx + dx0, sy - dy0});
    }
    return res;
};

void solve() {
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;

    // find border
    int d = dist(xg, yg, xm, ym);

    auto touch = [&](int t) {
        return t / 2 + t / 7 >= d - 1;
    };

    int lo = 0, hi = 2 * d + 5;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (touch(mid)) hi = mid;
        else lo = mid + 1;
    }
    int t = lo;
    int rg = t / 2;
    int rm = t / 7;

    // bfs
    unordered_map<i2, bool, Hash> grid;

    auto get = [&](int x, int y) -> int {
        if (dist(x, y, xg, yg) <= rg) return 0;
        if (dist(x, y, xm, ym) <= rm) return 1;
        auto it = grid.find({x, y});
        if (it != end(grid)) return it->second;
        return -1;
    };

    auto adj4 = [&](int x, int y) {
        for (int d = 0; d < 4; d++) {
            if (get(x + dx[d], y + dy[d]) == 1) return true;
        }
        return false;
    };

    auto adj8 = [&](int x, int y) {
        for (int ox = -1; ox <= 1; ox++) {
            for (int oy = -1; oy <= 1; oy++) {
                if (get(x + ox, y + oy) == 1) return true;
            }
        }
        return false;
    };

    vector<i2> g = ring(xg, yg, rg + 1), m = ring(xm, ym, rm + 1), g2, m2;
    int ans = dim_cnt(rm);

    bool adj = false;
    for (int i = t + 1; size(m); i++) {
        if (i % 2 == 0) {
            for (auto &[x, y] : g) {
                if (get(x, y) != -1) continue;
                if (adj && !adj8(x, y)) continue;
                grid[{x, y}] = 0;
                if (!adj && adj4(x, y)) adj = true;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (get(nx, ny) == -1) g2.push_back({nx, ny});
                }
            }
            swap(g, g2);
            g2.clear();
        }
        if (i % 7 == 0) {
            for (auto &[x, y] : m) {
                if (get(x, y) != -1) continue;
                grid[{x, y}] = 1;
                ans++;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (get(nx, ny) == -1) m2.push_back({nx, ny});
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