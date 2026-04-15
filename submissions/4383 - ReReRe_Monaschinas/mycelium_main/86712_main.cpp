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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while(tt--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        map<pair<int, int>, int> mp;
        vector<pair<int, int>> pos, pos2;
        pos.push_back({x1, y1});
        pos2.push_back({x2, y2});
        mp[{x1, y1}] = true;
        mp[{x2, y2}] = true;
        int t = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        int ans = 1;
        while (true) {
            if (t % 2 == 0) {
                    vector<pair<int, int>> nu;
                for (int i = 0; i < sz(pos); i++) {
                    for (int j = 0; j < 4; j++) {
                        int nx = pos[i].first + dx[j];
                        int ny = pos[i].second + dy[j];
                        if (mp[{nx, ny}]) continue;
                        mp[{nx, ny}] = true;
                        nu.push_back({nx, ny});
                    }
                }
                pos = nu;
            }
            bool ya = false;
            if (t % 7 == 0) {
                vector<pair<int, int>> nu2;
                for (int i = 0; i < sz(pos2); i++) {
                    for (int j = 0; j < 4; j++) {
                        int nx = pos2[i].first + dx[j];
                        int ny = pos2[i].second + dy[j];
                        if (mp[{nx, ny}]) continue;
                        mp[{nx, ny}] = true;
                        ans++;
                        nu2.push_back({nx, ny});
                    }
                }
                if (sz(nu2) == 0) {
                    ya = true;
                    break;
                }
                pos2 = nu2;
            }
            if (ya) break;
            t++;
        }
        cout << ans << "\n";
    }

    return 0;
}
