#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int t;
        cin >> t;

        while (t --> 0) {
                int n, m;
                cin >> n >> m;

                vector<vector<char>> c(n + 2, vector<char>(m + 2, '.'));
                for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= m; j++) {
                                cin >> c[i][j];
                        }
                }
                
                vector<vector<int>> dir(n + 2, vector<int>(m + 2));
                for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= m; j++) {
                                int k = -1;
                                if (c[i][j] == '^') {
                                        k = 2;
                                } else if (c[i][j] == '>') {
                                        k = 1;
                                } else if (c[i][j] == 'v') {
                                        k = 0;
                                } else if (c[i][j] == '<') {
                                        k = 3;
                                }
                                dir[i][j] = k;
                        }
                }

                vector<vector<int>> in(n + 2, vector<int>(m + 2));
                for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= m; j++) {
                                for (int k = 0; k < 4; k++) {
                                        if (k == dir[i][j]) continue;

                                        int cx = i + dx[k];
                                        int cy = j + dy[k];
                                        if (c[cx][cy] == 'S' || (c[cx][cy] != '.' && c[cx][cy] != 'X' && dir[cx][cy] == (k + 2) % 4)) {
                                                in[i][j] += 1;
                                        }
                                }
                        }
                }

                vector<pair<int, int>> q(1, {1, 1});
                vector<vector<pair<int, int>>> val(n + 2, vector<pair<int, int>>(m + 2, {0, 1}));
                val[1][1] = {1, 1};
                for (int i = 0; i < (int)q.size(); i++) {
                        auto [x, y] = q[i];
                        if (x < 1 || x > n || y < 1 || y > m) continue;

                        int k = -1;
                        if (c[x][y] == '^') {
                                k = 2;
                        } else if (c[x][y] == '>') {
                                k = 1;
                        } else if (c[x][y] == 'v') {
                                k = 0;
                        } else if (c[x][y] == '<') {
                                k = 3;
                        }

                        if (k != -1) {
                                int cx = x + dx[k];
                                int cy = y + dy[k];
                                
                                auto add = [&](int cx, int cy, int x, int y) {
                                        int g = lcm(val[cx][cy].se, val[x][y].se);
                                        val[cx][cy] = {val[cx][cy].fi * (g / val[cx][cy].se) + val[x][y].fi * (g / val[x][y].se), g};
                                };

                                add(cx, cy, x, y);
                                in[cx][cy] -= 1;
                                if (in[cx][cy] == 0) {
                                        q.push_back({cx, cy});
                                }
                        } else if (c[x][y] == 'S') {
                                int cnt = 0;
                                for (int k = 0; k < 4; k++) {
                                        int cx = x + dx[k];
                                        int cy = y + dy[k];
                                        if (c[cx][cy] == 'X' || (c[cx][cy] != '.' && c[cx][cy] != 'X' && dir[cx][cy] != (k + 2) % 4)) {
                                                cnt += 1;
                                        }
                                }

                                auto add = [&](int cx, int cy, int x, int y) {
                                        int g = lcm(val[cx][cy].se, y);
                                        val[cx][cy] = {val[cx][cy].fi * (g / val[cx][cy].se) + x * (g / y), g};
                                };

                                for (int k = 0; k < 4; k++) {
                                        int cx = x + dx[k];
                                        int cy = y + dy[k];
                                        if (c[cx][cy] == 'X' || (c[cx][cy] != '.' && c[cx][cy] != 'X' && dir[cx][cy] != (k + 2) % 4)) {
                                                add(cx, cy, val[x][y].fi, val[x][y].se * cnt);
                                                in[cx][cy] -= 1;
                                                if (in[cx][cy] == 0) {
                                                        q.push_back({cx, cy});
                                                }
                                        }
                                }
                        }
                }

                auto add = [&](int cx, int cy, int x, int y) {
                        int g = lcm(val[cx][cy].se, y);
                        val[cx][cy] = {val[cx][cy].fi * (g / val[cx][cy].se) + x * (g / y), g};
                };

                for (int i = 0; i <= n + 1; i++) {
                        for (int j = 0; j <= m + 1; j++) {
                                if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
                                        add(0, 0, val[i][j].fi, val[i][j].se);
                                }
                        }
                }

                int g = gcd(val[0][0].fi, val[0][0].se);
                val[0][0].fi /= g;
                val[0][0].se /= g;

                cout << val[0][0].fi << " " << val[0][0].se << '\n';
        }
        
        return 0;
}