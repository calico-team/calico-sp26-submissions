#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return llabs(x1 - x2) + llabs(y1 - y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll XG, YG, XM, YM;
        cin >> XG >> YG >> XM >> YM;

        queue<pair<ll,ll>> q;
        set<pair<ll,ll>> vis;

        q.push({XM, YM});
        vis.insert({XM, YM});

        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                ll nx = x + dx[dir];
                ll ny = y + dy[dir];

                if (vis.count({nx, ny})) continue;

                ll dM = dist(nx, ny, XM, YM);
                ll dG = dist(nx, ny, XG, YG);

                // mycelium must strictly arrive earlier
                if (7 * dM < 2 * dG) {
                    vis.insert({nx, ny});
                    q.push({nx, ny});
                }
            }
        }

        cout << vis.size() << '\n';
    }

    return 0;
}