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
        string a, b;
        cin >> a >> b;
        string ans = "";
        int xd = sz(a);
        while (xd--) ans += '#';
        debug(ans);
        int j = 0;
        for (int i = 0; i < sz(a); i++) {
            if (j < sz(b) && a[i] == b[j]) {
                ans[i] = a[i];
                j++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
