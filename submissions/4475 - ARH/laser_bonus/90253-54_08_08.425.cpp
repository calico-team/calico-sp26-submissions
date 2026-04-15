// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdExtended(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
ll inv(ll a, ll m) {
    ll x, y;
    gcdExtended(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}
ll crt(ll a, ll m, ll b, ll n) {
    ll x, y;
    ll g = gcdExtended(m, n, x, y);
    if ((a - b) % g != 0) return -1;
    ll lcm = m / g * n;
    ll t = (a + (b - a) / g * x % (n / g) * m) % lcm;
    if (t < 0) t += lcm;
    return t;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int k;
        ll n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<pair<ll, ll>> asteroids(k);
        for (int i = 0; i < k; ++i) {
            cin >> asteroids[i].first >> asteroids[i].second;
        }
        ll sx = asteroids[0].first;
        ll sy = asteroids[0].second;
        ll minimum = LLONG_MAX;
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ll x = asteroids[i].first;
            ll y = asteroids[i].second;

            ll dx = (x - sx) % n;
            if (dx < 0) dx += n;

            ll dy = (y - sy) % m;
            if (dy < 0) dy += m;
            ll a, b;
            ll g1 = gcdExtended(q, n, a, b);
            if (dx % g1 != 0) continue;
            ll n1 = n / g1;
            ll t1 = (dx / g1) * inv((q / g1) % n1, n1) % n1;

            ll g2 = gcdExtended(p, m, a, b);
            if (dy % g2 != 0) continue;
            ll m1 = m / g2;
            ll t2 = (dy / g2) * inv((p / g2) % m1, m1) % m1;

            ll consider = crt(t1, n1, t2, m1);
            if (consider == -1) continue;
            // starting asteroid is only hit after wrapping around once
            ll g3 = std::gcd(n1, m1);
            ll period = n1 / g3 * m1;
            if (consider == 0) consider = period;

            if (consider < minimum) {
                minimum = consider;
                ans = i;
            }
        }

        cout << ans << '\n';
    }
}