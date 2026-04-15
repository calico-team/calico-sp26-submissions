#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long

ll T, N, X, Y, P, Q, gx, gy, x0, y0, mk, ans;

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

ll egcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll f(ll n, ll m) {
    return ((n % m) + m) % m;
}

ll qpow(ll b, ll p, ll m) {
    if (!p) return 1;
    if (p == 1) return b;
    ll sq = qpow(b, p / 2, m);
    if (p % 2 == 0) return f(sq * sq, m);
    return f(f(sq * sq, m) * b, m);
}

ll imod(ll n, ll m) {
    return qpow(n, m - 2, m);
}

void solve() {
    cin >> N >> X >> Y >> P >> Q;
    mk = (ll)(1e18);
    ans = 0;
    gx = gcd(X, Q);
    gy = gcd(Y, P);
    X /= gx, Q /= gx;
    Y /= gy, P /= gy;
    cin >> x0 >> y0;
    for (int i = 1; i < N; i++) {
        ll x, y, kx, ky, dx, dy;
        cin >> x >> y;
        dx = x - x0;
        dy = y - y0;
        if (dx % gx == 0 && dy % gy == 0) {
            dx /= gx, dy /= gy;
            kx = f(f(dx, X) * imod(Q, X), X);
            ky = f(f(dy, Y) * imod(P, Y), Y);
            ll xeff, yeff;
            ll g = egcd(X, Y, xeff, yeff);
            if ((ky - kx) % g == 0) {
                ll mod = (X / g) * Y;
                ll tar = (ky - kx) / g;
                ll res = ((__int128)tar * xeff) % (Y / g);
                ll k = ((__int128)res * X + kx) % mod;
                if (k < 0) k += mod;
                if (k == 0) k = mod;
                if (k < mk) {
                    mk = k;
                    ans = i;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}