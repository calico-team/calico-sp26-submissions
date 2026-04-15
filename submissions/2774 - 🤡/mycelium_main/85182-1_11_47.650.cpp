#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void solve() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int hs = 1, ans = 0;
    priority_queue <tuple <int, int, int, int>> q;
    q.emplace(0, 0, x1, y1);
    q.emplace(0, -1, x2, y2);
    map <pair <int, int>, bool> vis;
    int cnt = 0;
    while (hs) {
        auto [t, w, x, y] = q.top(); q.pop();
        hs += w;
        cnt++;
        // cerr << t << '\n';
        // cerr << ' ' << hs << ' ' << x << ' ' << y << ' ' << w << '\n';
        if (vis[make_pair(x, y)]) continue;
        vis[make_pair(x, y)] = 1;
        ans -= w;
        for (auto &[dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (vis[make_pair(nx, ny)]) continue;
            q.emplace(t+(w == 0 ? -2 : -7), w, nx, ny);
            hs -= w;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}

