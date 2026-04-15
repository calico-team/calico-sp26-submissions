#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

struct Point { int x, y; };

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1; y = 0; return a; }
    ll x1, y1, g = extgcd(b, a % b, x1, y1);
    x = y1; y = x1 - a / b * y1;
    return g;
}

// solve ax = b (mod m), return r and mod or -1 if no soln
pll linear_congruence(ll a, ll b, ll m) {
    ll x, y;
    ll g = extgcd(a % m, m, x, y);
    if (b % g) return {-1, -1};
    ll mod = m / g;
    ll r = (b / g % mod * (x % mod) % mod + mod) % mod;
    return {r, mod};
}

pll crt(ll r1, ll m1, ll r2, ll m2) {
    ll x, y;
    ll g = extgcd(m1, m2, x, y);
    if ((r2 - r1) % g) return {-1, -1};
    ll lcm = m1 / g * m2;
    ll mod = m2 / g;
    ll k = ((r2 - r1) / g % mod * (x % mod) % mod + mod) % mod;
    return {(r1 + m1 * k) % lcm, lcm};
}

void solve() {
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;

    vector<Point> asteroids(k);
    for (int i = 0; i < k; i++) {
        cin >> asteroids[i].x >> asteroids[i].y;
    }

    ll x0 = asteroids[0].x, y0 = asteroids[0].y;
    ll best_t = LLONG_MAX;
    int best_idx = -1;

    for (int i = 0; i < k; i++) {
        ll dx = ((asteroids[i].x - x0) % n + n) % n;
        ll dy = ((asteroids[i].y - y0) % m + m) % m;

        // t*q = dx (mod n)
        auto [r1, m1] = linear_congruence(q, dx, n);
        if (r1 < 0) continue;

        // t*p = dy (mod m)
        auto [r2, m2] = linear_congruence(p, dy, m);
        if (r2 < 0) continue;

        // find crt soln, t = r (mod lcm)
        auto [r, mod] = crt(r1, m1, r2, m2);
        if (r < 0) continue;

        ll t = r > 0 ? r : mod;
        if (t < best_t) {
            best_t = t; best_idx = i;
        }
    }

    cout << best_idx << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc; cin >> tc;
    while (tc--) solve();
}
