#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return llabs(x1 - x2) + llabs(y1 - y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll XG, YG, XM, YM;
        cin >> XG >> YG >> XM >> YM;

        ll D = dist(XG, YG, XM, YM);

        // Safe finite search box for main constraints
        ll LIM = 10 * D + 20;

        ll ans = 0;

        for (ll x = XM - LIM; x <= XM + LIM; x++) {
            for (ll y = YM - LIM; y <= YM + LIM; y++) {
                ll dM = dist(x, y, XM, YM);
                ll dG = dist(x, y, XG, YG);

                if (7 * dM < 2 * dG) ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}