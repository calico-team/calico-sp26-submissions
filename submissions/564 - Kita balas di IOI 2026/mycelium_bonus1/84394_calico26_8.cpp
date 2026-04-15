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
                int xg, yg, xm, ym;
                cin >> xg >> yg >> xm >> ym;

                int m = 1400;
                vector<vector<int>> vis(2800, vector<int>(2800));
                vis[xg + m][yg + m] = vis[xm + m][ym + m] = 1;

                int ans = 1;
                vector<pair<int, int>> vg, vm;
                vg.push_back({xg, yg});
                vm.push_back({xm, ym});
                for (int i = 1; !vm.empty(); i++) {
                        if (i % 2 == 0) {
                                vector<pair<int, int>> ng;
                                for (auto [x, y] : vg) {
                                        for (int k = 0; k < 4; k++) {
                                                int cx = x + dx[k];
                                                int cy = y + dy[k];
                                                if (!vis[cx + m][cy + m]) {
                                                        vis[cx + m][cy + m] = 1;
                                                        ng.push_back({cx, cy});
                                                }
                                        }
                                }

                                vg = ng;
                        }

                        if (i % 7 == 0) {
                                vector<pair<int, int>> nm;
                                for (auto [x, y] : vm) {
                                        for (int k = 0; k < 4; k++) {
                                                int cx = x + dx[k];
                                                int cy = y + dy[k];
                                                if (!vis[cx + m][cy + m]) {
                                                        vis[cx + m][cy + m] = 1;
                                                        nm.push_back({cx, cy});
                                                        ans += 1;
                                                }
                                        }
                                }

                                vm = nm;
                        }
                }

                cout << ans << '\n';
        }
        
        return 0;
}