#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll xg, yg, xm, ym;
    if (!(cin >> xg >> yg >> xm >> ym)) return;

    ll ans = 0;
    ll X_diff = abs(xg - xm), Y_diff = abs(yg - ym);
    ll dist_start = X_diff + Y_diff;
    ll lim = dist_start + 10; 

    for (ll x = xm - lim; x <= xm + lim; ++x) {
        for (ll y = ym - lim; y <= ym + lim; ++y) {
            ll dM = abs(x - xm) + abs(y - ym);
            ll dG = abs(x - xg) + abs(y - yg);
            if (7 * dM < 2 * dG) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}