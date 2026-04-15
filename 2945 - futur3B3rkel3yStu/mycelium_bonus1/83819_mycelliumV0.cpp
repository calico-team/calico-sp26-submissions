#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll f(int x, int y, int x1, int y1) {
    ll a = x - x1;
    ll b = y - y1;
    ll d = abs(a) + abs(b);
    ll r = (2 * d - 1) / 5;
    ll z = 0;
    for (ll i = -r; i <= r; i++) {
        auto g = [&](ll j) {
            ll u = abs(i) + abs(j);
            ll v = abs(i - a) + abs(j - b);
            return 7 * u < 2 * v;
        };
        ll l = -r, h = r;
        ll L = r + 1, H = -r - 1;
        ll p = l, q = h;
        while (p <= q) {
            ll m = (p + q) >> 1;
            if (g(m)) {
                L = m;
                q = m - 1;
            } else p = m + 1;
        }
        p = l, q = h;
        while (p <= q) {
            ll m = (p + q) >> 1;
            if (g(m)) {
                H = m;
                p = m + 1;
            } else q = m - 1;
        }
        if (L <= H) z += (H - L + 1);
    }

    return z;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y, x1, y1;
        cin >> x >> y >> x1 >> y1;
        cout << f(x, y, x1, y1) << '\n';
    }
}