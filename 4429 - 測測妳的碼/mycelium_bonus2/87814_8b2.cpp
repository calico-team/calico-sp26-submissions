#include <bits/stdc++.h>

using namespace std;
using ll = long long;
inline ll ceil_div(ll a, ll b) {
    if (a >= 0) return (a + b - 1) / b;
    return a / b;
}

inline ll get_Sx(ll X0, ll Y0) {
    ll u2 = ceil_div(2 * (X0 + Y0), 9);
    if (u2 <= X0) return max(0LL, u2);
    ll u1 = ceil_div(2 * (Y0 - X0), 5);
    return max({0LL, X0, u1});
}

inline bool chk(ll x, ll y, ll X0, ll Y0, ll LXp, ll LYp, ll LXm, ll LYm) {
    ll dM = abs(x) + abs(y);
    ll dG = 0;
    
    if (x >= 0 && y >= 0) {
        dG = abs(x - X0) + abs(y - Y0);
    } else if (x >= 0 && y < 0) {
        ll xc = max({X0, x, LXp + 1});
        dG = (xc - X0) + Y0 + (xc - x) - y;
    } else if (x < 0 && y >= 0) {
        ll yc = max({Y0, y, LYp + 1});
        dG = (yc - Y0) + X0 + (yc - y) - x;
    } else {
        ll xc1 = max(X0, LXp + 1);
        ll yc1 = min(y, -(LYm + 1));
        ll d1 = (xc1 - X0) + Y0 + xc1 - yc1 - x + abs(y - yc1);

        ll yc2 = max(Y0, LYp + 1);
        ll xc2 = min(x, -(LXm + 1));
        ll d2 = (yc2 - Y0) + X0 + yc2 - xc2 - y + abs(x - xc2);

        dG = min(d1, d2);
    }
    return 7 * dM <= 2 * dG - 1;
}

void solve() {
    ll xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    ll X0 = abs(xg - xm);
    ll Y0 = abs(yg - ym);
    ll D = X0 + Y0;
    ll LXp = get_Sx(X0, Y0) - 1;
    ll LYp = get_Sx(Y0, X0) - 1;
    ll LXm = ceil_div(2 * D, 5) - 1;
    ll LYm = ceil_div(2 * D, 5) - 1;
    ll ans = 0;
    ll R = (2 * D) / 5 + 2; 
    ll xr = R;
    for (ll y = 0; y <= R; ++y) {
        if (!chk(0, y, X0, Y0, LXp, LYp, LXm, LYm)) break;
        while (xr >= 0 && !chk(xr, y, X0, Y0, LXp, LYp, LXm, LYm)) xr--;
        if (xr >= 0) ans += (xr + 1);
    }

    ll xl = -R;
    for (ll y = 0; y <= R; ++y) {
        if (!chk(-1, y, X0, Y0, LXp, LYp, LXm, LYm)) break;
        while (xl <= -1 && !chk(xl, y, X0, Y0, LXp, LYp, LXm, LYm)) xl++;
        if (xl <= -1) ans += (-xl);
    }

    xr = R;
    for (ll y = -1; y >= -R; --y) {
        if (!chk(0, y, X0, Y0, LXp, LYp, LXm, LYm)) break;
        while (xr >= 0 && !chk(xr, y, X0, Y0, LXp, LYp, LXm, LYm)) xr--;
        if (xr >= 0) ans += (xr + 1);
    }

    xl = -R;
    for (ll y = -1; y >= -R; --y) {
        if (!chk(-1, y, X0, Y0, LXp, LYp, LXm, LYm)) break;
        while (xl <= -1 && !chk(xl, y, X0, Y0, LXp, LYp, LXm, LYm)) xl++;
        if (xl <= -1) ans += (-xl);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}