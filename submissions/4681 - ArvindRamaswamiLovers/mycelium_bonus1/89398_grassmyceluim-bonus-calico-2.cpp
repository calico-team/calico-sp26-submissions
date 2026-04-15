#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
    inline size_t operator()(const pair<int, int> &v) const {
        return v.first * 31 + v.second;
    }
};
void solve() {
    int xg, yg, xm, ym;
    if (!(cin >> xg >> yg >> xm >> ym)) return;
    // 0: empty (not in map), 1: grass, 2: mycelium
    unordered_map<long long, int> grid;
    // coordinates into a single long long for speed
    auto pack = [](int x, int y) {
        return ((long long)x << 32) | (unsigned int)y;
    };
    grid[pack(xg, yg)] = 1;
    grid[pack(xm, ym)] = 2;
    vector<pair<int, int>> front_g = {{xg, yg}};
    vector<pair<int, int>> front_m = {{xm, ym}};
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    long long count_m = 1;
    int tick = 1;

    while (!front_m.empty()) {
        vector<pair<int, int>> next_g, next_m;
        // 1. Grass expansion
        if (tick % 2 == 0) {
            for (auto& p : front_g) {
                for (int i = 0; i < 4; i++) {
                    int nx = p.first + dx[i], ny = p.second + dy[i];
                    long long id = pack(nx, ny);
                    if (grid.find(id) == grid.end()) {
                        grid[id] = 1;
                        next_g.push_back({nx, ny});
                    }
                }
            }
            front_g = next_g;
        }
        // 2. Mycelium expansion
        if (tick % 7 == 0) {
            for (auto& p : front_m) {
                for (int i = 0; i < 4; i++) {
                    int nx = p.first + dx[i], ny = p.second + dy[i];
                    long long id = pack(nx, ny);
                    if (grid.find(id) == grid.end()) {
                        grid[id] = 2;
                        next_m.push_back({nx, ny});
                        count_m++;
                    }
                }
            }
            front_m = next_m;
        }
        tick++;
    }
    cout << count_m << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}