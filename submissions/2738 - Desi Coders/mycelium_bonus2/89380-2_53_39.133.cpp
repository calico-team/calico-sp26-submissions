#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve_case(ll xg, ll yg, ll xm, ll ym) {
    ll dx = abs(xg - xm);
    ll dy = abs(yg - ym);
    ll d = dx + dy;

    if (d == 1) return 2;

    ll k = (d - 1) / 6;
    ll rem = (d - 1) % 6;

    ll ans = 1 + 3 * k * (k + 1);

    if (rem == 1) ans += (k + 1);
    else if (rem == 2) ans += 2 * (k + 1);
    else if (rem == 3) ans += 3 * (k + 1);
    else if (rem == 4) ans += 4 * (k + 1);
    else if (rem == 5) ans += 5 * (k + 1);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        ll xg, yg, xm, ym;
        if (!(cin >> xg >> yg >> xm >> ym)) break;
        cout << solve_case(xg, yg, xm, ym) << '\n';
    }

    return 0;
}