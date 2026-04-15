#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll g = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

ll solve_linear_congruence(ll a, ll b, ll m, ll &mod) {
    if (m == 0) return -1;
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    if (m == 1) {
        mod = 1;
        return 0;
    }
    ll x, y;
    ll g = extgcd(a, m, x, y);
    if (b % g != 0) return -1;
    ll m1 = m / g;
    ll a1 = a / g;
    ll b1 = b / g;
    extgcd(a1, m1, x, y);
    x = (x % m1 + m1) % m1;
    ll t = (x * b1) % m1;
    mod = m1;
    return t;
}

pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2) {
    if (m1 == 0 || m2 == 0) return make_pair(0LL, 0LL);
    ll diff = ((r2 - r1) % m2 + m2) % m2;
    ll x, y;
    ll g = extgcd(m1, m2, x, y);
    if (diff % g != 0) return make_pair(0LL, 0LL);
    ll m1g = m1 / g;
    ll m2g = m2 / g;
    ll lcm = m1g * m2;
    extgcd(m1g, m2g, x, y);
    x = (x % m2g + m2g) % m2g;
    ll k = (x * (diff / g)) % m2g;
    ll r = r1 + k * m1;
    r = (r % lcm + lcm) % lcm;
    return make_pair(r, lcm);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int K;
        ll N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;
        vector<pair<ll, ll> > asteroids(K);
        for (int i = 0; i < K; ++i) {
            cin >> asteroids[i].first >> asteroids[i].second;
        }
        ll x0 = asteroids[0].first, y0 = asteroids[0].second;
        ll best_t = LLONG_MAX;
        int best_idx = -1;
        for (int i = 0; i < K; ++i) {
            ll dx = (asteroids[i].first - x0) % N;
            if (dx < 0) dx += N;
            ll dy = (asteroids[i].second - y0) % M;
            if (dy < 0) dy += M;
            ll mod1, mod2;
            ll t1 = solve_linear_congruence(Q, dx, N, mod1);
            if (t1 == -1) continue;
            ll t2 = solve_linear_congruence(P, dy, M, mod2);
            if (t2 == -1) continue;
            pair<ll, ll> res = crt(t1, mod1, t2, mod2);
            ll t0 = res.first;
            ll L = res.second;
            if (L == 0) continue;
            if (t0 == 0) t0 = L;
            if (t0 < best_t) {
                best_t = t0;
                best_idx = i;
            }
        }
        cout << best_idx << "\n";
    }
    return 0;
}
