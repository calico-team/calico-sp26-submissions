#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast")
#pragma GGC target("avx2")

using namespace std;

pair <int, int> d[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void solve() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int hs = 1, ans = 0;
    queue <tuple <int, int, int, int>> q, q2;
    q.emplace(0, 0, x1, y1);
    q2.emplace(0, -1, x2, y2);
    unordered_map <ll, int> vis;
    // int cnt = 0;
    auto calc = [&] (ll x, ll y) {
        return x * 1e9 + y;
    };
    while (hs) {
        int t, w, x, y;
        if (q.empty() || (q.size() && q2.size() && get<0>(q2.front()) > get<0>(q.front()))) {
            tie(t, w, x, y) = q2.front(); q2.pop();
        } else {
            tie(t, w, x, y) = q.front(); q.pop();
        }
        // cout << "BRUh\n";
        hs += w;
        // cnt++;
        // cerr << t << '\n';
        // cerr << ' ' << hs << ' ' << x << ' ' << y << ' ' << w << '\n';
        if (vis[calc(x, y)] == 2) continue;
        vis[calc(x, y)] = 2;
        ans -= w;
        for (auto &[dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (vis[calc(nx, ny)]) continue;
            if (w == 0) q.emplace(t+(w == 0 ? -2 : -7), w, nx, ny);
            else q2.emplace(t+(w == 0 ? -2 : -7), w, nx, ny);
            hs -= w;
            if (w == 0) vis[calc(nx, ny)] = 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}

