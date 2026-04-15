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
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        int g = (2 * l) + (2 * w);
        g *= r;
        int ans = (e / g);
        debug(g);
        if (e % g != 0) ans++;
        cout << ans << '\n';

    }

    return 0;
}
