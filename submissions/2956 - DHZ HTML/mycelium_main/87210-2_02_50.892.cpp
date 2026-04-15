#include <bits/stdc++.h>
using namespace std;
#define int long long
#define v vector
const int MAXN = 40;

bool che(int x, int y) {
        return (x < 2 * MAXN && x >= 0 && y < 2 * MAXN && y >= 0);
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve() {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v<v<int>> g(2 * MAXN, v<int>(2 * MAXN, -1));
        v<v<bool>> visit(2 * MAXN, v<bool>(2 * MAXN));
        queue<pair<int, int>> q1, q2;
        q1.push({a + MAXN, b + MAXN}); q2.push({c + MAXN, d + MAXN});
        visit[a + MAXN][b + MAXN] = true; visit[c + MAXN][d + MAXN] = true;
        int ans = 0, t = 0;
        while (!q1.empty() || !q2.empty()) {
                t++;
                if (t % 2 == 0 && !q1.empty()) {
                        int sz = q1.size();
                        while (sz--) {
                                auto [x, y] = q1.front(); q1.pop();
                                g[x][y] = 0;
                                for (int i = 0; i < 4; i++) {
                                        int nx = x + dx[i], ny = y + dy[i];
                                        if (!che(nx, ny) || visit[nx][ny]) continue;
                                        q1.push({nx, ny});
                                        visit[nx][ny] = true;
                                }
                        }
                }
                if (t % 7 == 0 && !q2.empty()) {
                        int sz = q2.size();
                        while (sz--) {
                                auto [x, y] = q2.front(); q2.pop();
                                if (g[x][y] == -1) { g[x][y] = 1; ans++; }
                                for (int i = 0; i < 4; i++) {
                                        int nx = x + dx[i], ny = y + dy[i];
                                        if (!che(nx, ny) || visit[nx][ny]) continue;
                                        q2.push({nx, ny});
                                        visit[nx][ny] = true;
                                }
                        }
                }
        }
        cout << ans << "\n";
}

int32_t main() {
        int T; cin >> T;
        while (T--) solve();
}