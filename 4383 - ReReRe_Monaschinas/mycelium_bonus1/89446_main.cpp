#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
#define sz(v) ((int)((v).size()))
#define linea() cerr << "---------------------------" << '\n'
int32_t main() {
    ios::sync_with_stdio(false);
   cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        auto dist2 = [&] (int x, int y) {
            return abs(x - x1) + abs(y - y1);
        };
        auto dist1 = [&] (int x, int y) {
            return abs(x - x2) + abs(y - y2);
        };

        queue<pair<int, int>> q;
        queue<pair<int, int>> p;
        q.push({x1, y1});
        p.push({x2, y2});
        int t = 1;
        int ans = 1;

        vector<vector<bool>> vis(3500, vector<bool>(3500, false));

        vis[x2 + 1700][y2 + 1700]= true;
        vis[x1 + 1700][y1 + 1700]= true;
        while (!p.empty()) {

            int aux = sz(q);
            if (t % 2 == 0) {
                while (aux--) {
                    auto [cx, cy] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; j++) {
                        int nx = cx + dx[j];
                        int ny = cy + dy[j];
                        if (!vis[nx + 1700][ny + 1700]) {
                            vis[nx + 1700][ny + 1700] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            aux = sz(p);
            if (t % 7 == 0) {
                while (aux--) {
                    auto [cx, cy] = p.front();
                    p.pop();
                    for (int j = 0; j < 4; j++) {
                        int nx = cx + dx[j];
                        int ny = cy + dy[j];
                        if (!vis[nx + 1700][ny + 1700]) {
                            vis[nx + 1700][ny + 1700] = true;
                            ans++;
                            p.push({nx, ny});
                        }
                    }
                }
            }
            t++;
        }
        cout << ans << "\n";
    }

    return 0;
}
