#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

string order = "v>^<";
pii dirs[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

pll simplify(pll frac) {
    auto [a, b] = frac;
    if (a == 0 || b == 0) return frac;
    ll g = gcd(a, b);
    return {a / g, b / g};
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string& s : grid) cin >> s;
    if (grid[0][0] == 'X') {
        cout << "0 1\n";
        return;
    }
    vector<vector<pii>> next(n, vector<pii>(m, {-1, -1}));
    vector<vector<bool>> visited(n, vector<bool>(m));
    map<pii, vector<pii>> adj;
    
    vector<pii> topo = {{n, m}, {n, -1}};
    function<pii(int, int)> dfs = [&](int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return make_pair(n, m);
        }
        if (visited[i][j]) {
            return next[i][j];
        }
        visited[i][j] = true;
        if (grid[i][j] == 'X') {
            next[i][j] = {n, -1};
            return make_pair(n, -1);
        }
        if (grid[i][j] == 'S') {
            for (auto [di, dj] : dirs) {
                int ni = i + di, nj = j + dj;
                if (visited[ni][nj]) continue;
                if (grid[ni][nj] == '.') continue;
                {
                    int index = order.find(grid[ni][nj]);
                    int mi = ni + dirs[index].first, mj = nj + dirs[index].second;
                    if (mi == i && mj == j) continue;
                }
                adj[{i, j}].push_back(dfs(ni, nj));
            }
            topo.push_back({i, j});
            next[i][j] = {i, j};
            return make_pair(i, j);
        }
        int index = order.find(grid[i][j]);
        int ni = i + dirs[index].first, nj = j + dirs[index].second;
        next[i][j] = dfs(ni, nj);
        if (i == 0 && j == 0) adj[{i, j}].push_back(next[i][j]);
        return next[i][j];
    };
    dfs(0, 0);

    // for (auto& [p, others] : adj) {
    //     cout << p.first << " " << p.second << ":\n";
    //     for (pii other : others) {
    //         cout << "  " << other.first << " " << other.second << "\n";
    //     }
    // }

    topo.push_back({0, 0});
    reverse(topo.begin(), topo.end());

    map<pii, pll> fracs;
    fracs[{0, 0}] = {1, 1};
    fracs[{n, m}] = {0, 1};
    for (pii p : topo) {
        pll frac = fracs[p];
        frac.second *= adj[p].size();
        frac = simplify(frac);
        for (pii other : adj[p]) {;
            if (fracs.find(other) == fracs.end()) {
                fracs[other] = {0, 1};
            }
            ll g = gcd(fracs[other].second, frac.second);
            ll mult = fracs[other].second / g;
            fracs[other].first *= frac.second / g;
            fracs[other].second *= frac.second / g;
            fracs[other].first += frac.first * mult;
            fracs[other] = simplify(fracs[other]);
        }
    }

    auto [a, b] = fracs[{n, m}];
    cout << a << " " << b << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}