#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

ll modinv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}

pair<ll,ll> solve_congruence(ll a, ll b, ll m) {
    ll g = gcd(a, m);
    if (b % g) return {-1, -1};
    a /= g; b /= g; m /= g;
    ll inv = modinv(a, m);
    ll t = (b % m) * inv % m;
    return {t, m};
}

pair<ll,ll> crt(ll r1, ll m1, ll r2, ll m2) {
    ll x, y;
    ll g = extgcd(m1, m2, x, y);
    if ((r2 - r1) % g) return {-1, -1};

    ll lcm = m1 / g * m2;
    ll t = (r1 + (__int128)(r2 - r1) / g * x % (m2 / g) * m1) % lcm;
    if (t < 0) t += lcm;
    return {t, lcm};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int K;
        ll N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<pair<ll,ll>> ast(K);
        for (int i = 0; i < K; i++) {
            cin >> ast[i].first >> ast[i].second;
        }

        ll x0 = ast[0].first;
        ll y0 = ast[0].second;

        ll best_t = LLONG_MAX;
        int ans = -1;

        ll lazarbeam = 0;

        for (int i = 0; i < K; i++) {
            ll dx = ast[i].first - x0;
            dx %= N;
            if (dx < 0) dx += N;

            ll dy = ast[i].second - y0;
            dy %= M;
            if (dy < 0) dy += M;

            auto cx = solve_congruence(Q, dx, N);
            if (cx.first == -1) continue;

            auto cy = solve_congruence(P, dy, M);
            if (cy.first == -1) continue;

            auto res = crt(cx.first, cx.second, cy.first, cy.second);
            if (res.first == -1) continue;

            ll t = res.first;
            if (t == 0) t += res.second;

            if (t < best_t) {
                best_t = t;
                ans = i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

void read_your_input() {}