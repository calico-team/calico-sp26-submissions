#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

pair<ll, ll> crt_general(ll a1, ll m1, ll a2, ll m2) {
    ll g = ::gcd(m1, m2);
    if ((a2 - a1) % g != 0) return { -1, -1 };

    ll lcm = m1 / g * m2;
    ll a = m1 / g;
    ll b = m2 / g;
    ll c = (a2 - a1) / g;

    ll inv_a = mod_inverse(a, b);
    if (inv_a == -1) return { -1, -1 };

    ll k0 = (c % b) * inv_a % b;
    if (k0 < 0) k0 += b;

    ll x0 = (a1 + k0 * m1) % lcm;
    return { x0, lcm };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        ll K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<pair<ll, ll>> ast(K);
        for (int i = 0; i < K; ++i) {
            cin >> ast[i].first >> ast[i].second;
        }

        ll x0 = ast[0].first;
        ll y0 = ast[0].second;
        ll min_step = LLONG_MAX;
        int ans = 0;

        for (int idx = 0; idx < K; ++idx) {
            ll a = ast[idx].first;
            ll b = ast[idx].second;

            ll dx = (a - x0) % N;
            if (dx < 0) dx += N;
            ll g1 = ::gcd(Q, N);
            if (dx % g1 != 0) continue;

            ll Q1 = Q / g1;
            ll N1 = N / g1;
            ll dx1 = dx / g1;
            ll inv_Q1 = mod_inverse(Q1, N1);
            if (inv_Q1 == -1) continue;
            ll t1 = dx1 * inv_Q1 % N1;
            ll m1 = N1;

            ll dy = (b - y0) % M;
            if (dy < 0) dy += M;
            ll g2 = ::gcd(P, M);
            if (dy % g2 != 0) continue;

            ll P2 = P / g2;
            ll M2 = M / g2;
            ll dy2 = dy / g2;
            ll inv_P2 = mod_inverse(P2, M2);
            if (inv_P2 == -1) continue;
            ll t2 = dy2 * inv_P2 % M2;
            ll m2 = M2;

            auto res = crt_general(t1, m1, t2, m2);
            ll t = res.first;
            if (t == -1) continue;
            if (t == 0) continue;

            if (t < min_step) {
                min_step = t;
                ans = idx;
            }
        }
        cout << ans << endl;
    }
    return 0;
}