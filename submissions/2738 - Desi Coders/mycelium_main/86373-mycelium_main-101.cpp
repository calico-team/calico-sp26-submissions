#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// count points in diamond |x| + |y| <= R
static inline ll diamond(ll R) {
    if (R < 0) return 0;
    return 1 + 2 * R * (R + 1);
}

// count points where 7*distM < 2*distG
ll solve_one(ll xg, ll yg, ll xm, ll ym) {
    ll dx = xg - xm;
    ll dy = yg - ym;

    // We transform inequality:
    // 7(|x|+|y|) < 2(|x-dx|+|y-dy|)

    // critical boundary radius approximation:
    ll D = llabs(dx) + llabs(dy);

    ll R = (2 * D - 1) / 5; // derived from balance 7r < 2(D-r)

    ll ans = 0;

    // count all points in diamond of radius R around mycelium
    // that satisfy full inequality
    for (ll x = -R; x <= R; x++) {
        ll rem = R - llabs(x);
        for (ll y = -rem; y <= rem; y++) {

            ll dm = llabs(x) + llabs(y);
            ll dg = llabs(x - dx) + llabs(y - dy);

            if (7 * dm < 2 * dg) ans++;
        }
    }

    return ans;
}

void read_your_input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        cout << solve_one(xg, yg, xm, ym) << "\n";
    }
}

int main() {
    read_your_input();
    return 0;
}