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


        queue<pair<int, int>> q;
        queue<pair<int, int>> p;
        q.push({x1, y1});
        p.push({x2, y2});
        int t = 1;
        int ans = 1;

        set<pair<int, int>> st;

        st.insert({x2, y2});
        st.insert({x1, y1});
        while (!p.empty()) {

            int aux = sz(q);
            if (t % 2 == 0) {
                while (aux--) {
                    auto [cx, cy] = q.front();
                    q.pop();
                    for (int j = 0; j < 4; j++) {
                        int nx = cx + dx[j];
                        int ny = cy + dy[j];
                        if (!st.count({nx, ny})) {
                            st.insert({nx, ny});
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
                        if (!st.count({nx, ny})) {
                            st.insert({nx, ny});
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
