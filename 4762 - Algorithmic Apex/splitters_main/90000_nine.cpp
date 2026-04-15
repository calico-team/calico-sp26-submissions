#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvii = vector<vii>;

#define rep(i, a, b)  for (int i = int(a); i < int(b); i++)
#define repr(i, a, b) for (int i = int(a); i > int(b); i--)
#define cinn(a, n)    rep(_, 0, n) cin >> a[_];
#define all(x)        begin(x), end(x)
#define each(x, l)    for (auto x : l)

const int MOD = 1e9 + 7;

int n, m;

array<pii, 4> grid_moves {
    { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } }
};

bool bounds(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void solve() {
    cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<int>> indeg(n, vector<int>(m, 0));
    vector<vector<vector<pii>>> outs(n, vector<vii>(m));
    vector<vector<vector<pii>>> parents(n, vector<vii>(m));

    pii out_node = { -3, -3 };

    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> graph[i][j];
        }
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (graph[i][j] == 'v' || graph[i][j] == '^' ||
                graph[i][j] == '>' || graph[i][j] == '<') {
                int di = 0, dj = 0;
                if (graph[i][j] == 'v') {
                    di = 1;
                    dj = 0;
                }
                if (graph[i][j] == '^') {
                    di = -1;
                    dj = 0;
                }
                if (graph[i][j] == '>') {
                    di = 0;
                    dj = 1;
                }
                if (graph[i][j] == '<') {
                    di = 0;
                    dj = -1;
                }
                int ni = i + di;
                int nj = j + dj;
                outs[i][j].emplace_back(ni, nj);
                if (bounds(ni, nj)) {
                    indeg[ni][nj]++;
                    parents[ni][nj].emplace_back(i, j);
                } else {
                    out_node = { i, j };
                }
            }
        }
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (graph[i][j] == 'S') {
                for (auto [di, dj] : grid_moves) {
                    int ni = i + di;
                    int nj = j + dj;
                    if (bounds(ni, nj) && graph[ni][nj] != '.') {
                        if (size(outs[ni][nj]) == 1 &&
                            outs[ni][nj][0].first == i &&
                            outs[ni][nj][0].second == j) {
                            continue;
                        }
                        indeg[ni][nj]++;
                        parents[ni][nj].emplace_back(i, j);
                        outs[i][j].emplace_back(ni, nj);
                    }
                }
            }
        }
    }

    if (out_node.first == -3) {
        cout << "0 1\n";
        return;
    }

    queue<pii> q;

    q.emplace(0, 0);

    vii topo_sort;

    while (size(q)) {
        auto top = q.front();
        q.pop();

        int oi = top.first, oj = top.second;

        if (graph[oi][oj] == 'X') {
            // don't do anything on X
            continue;
        }

        topo_sort.push_back(top);

        for (auto [i, j] : outs[oi][oj]) {
            if (!bounds(i, j)) continue;
            indeg[i][j]--;
            if (indeg[i][j] == 0) q.emplace(i, j);
        }
    }

    vector<vector<pll>> fraction(n, vector<pll>(m, { 0, 1 }));
    fraction[0][0] = { 1, 1 };

    for (auto v : topo_sort) {
        ll mult = size(outs[v.first][v.second]);
        auto& vp = fraction[v.first][v.second];

        for (auto parent : parents[v.first][v.second]) {
            auto fp = fraction[parent.first][parent.second];

            ll num = vp.first * fp.second + vp.second * fp.first;
            ll den = (vp.second * fp.second) * mult;
            ll g = gcd(num, den);

            den /= g;
            num /= g;
            vp = { num, den };
        }
    }

    cout << fraction[out_node.first][out_node.second].first << " "
         << fraction[out_node.first][out_node.second].second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) solve();
}
