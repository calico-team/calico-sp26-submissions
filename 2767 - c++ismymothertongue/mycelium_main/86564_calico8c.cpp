#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_c(ll A, ll B) {
    ll c = max(0LL, (2*A - 2*B + 4) / 5);
    return (c >= B) ? c : (2*A + 2*B + 8) / 9;
}

void solve() {
    ll xg, yg, xm, ym;
    if (!(cin >> xg >> yg >> xm >> ym)) return;
    ll XG = abs(xg - xm), YG = abs(yg - ym);
    if (!(XG + YG)) { cout << "0\n"; return; }

    ll xp = get_c(YG, XG), yp = get_c(XG, YG), sl = (2*(XG + YG) + 4) / 5;
    ll dxp = abs(xp - XG) + YG, dxm = XG + sl;
    ll dyp = XG + abs(yp - YG), dym = XG + sl;

    auto TG = [&](ll x, ll y) {
        ll res = 4e18;
        bool ok = 1;
        if ((!XG && !x && YG*y < 0) || (XG > 0 && x <= 0) || (XG < 0 && x >= 0))
            if (max(YG, y) < yp && min(YG, y) > -sl) ok = 0;
        if ((!YG && !y && XG*x < 0) || (YG > 0 && y <= 0) || (YG < 0 && y >= 0))
            if (max(XG, x) < xp && min(XG, x) > -sl) ok = 0;
        if (ok) res = 2 * (abs(x - XG) + abs(y - YG));
        return min({res, 2*(dxp+abs(x-xp)+abs(y)), 2*(dxm+abs(x+sl)+abs(y)), 
                         2*(dyp+abs(x)+abs(y-yp)), 2*(dym+abs(x)+abs(y+sl))});
    };

    ll ans = 0, lim = (2*(XG + YG)) / 5 + 100;
    for (ll y = -lim; y <= lim; ++y) {
        ll ay = abs(y);
        if (7 * ay >= TG(0, y)) continue;
        ll L = 1, R = -1, lo = 0, hi = lim;
        while (lo <= hi) {
            ll m = lo + (hi - lo) / 2;
            if (7 * (m + ay) < TG(m, y)) { R = m; lo = m + 1; }
            else hi = m - 1;
        }
        lo = -lim, hi = 0;
        while (lo <= hi) {
            ll m = lo + (hi - lo) / 2;
            if (7 * (abs(m) + ay) < TG(m, y)) { L = m; hi = m - 1; }
            else lo = m + 1;
        }
        if (R >= L) ans += (R - L + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; if (cin >> t) while (t--) solve();
}