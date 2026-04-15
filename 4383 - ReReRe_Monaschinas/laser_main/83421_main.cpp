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
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<pair<int,int>> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i].first >> v[i].second;
        }
        pair<int, int> pos = v[0];
        int ans = 0;
        while (true) {
            
            pos.first += q;
            pos.second += p;
            pos.first %= n;
            pos.second %= m;
            debug(pos.first, pos.second);
            bool ok = false;
            for (int i = 0; i < k; i++) {
                if (pos == v[i]) {
                    ans = i;
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        linea();
        cout << ans << '\n';

    }
    return 0;
}
