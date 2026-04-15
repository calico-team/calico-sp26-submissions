#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll mod_inv(ll a, ll mod) {
    ll x, y;
    exgcd(a, mod, x, y);
    x %= mod;
    if (x < 0) x += mod;
    return x;
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

        vector<pair<ll,ll>> a(K);
        for (int i = 0; i < K; i++) cin >> a[i].first >> a[i].second;

        ll x0 = a[0].first, y0 = a[0].second;

        ll g1 = gcd(Q, N);
        ll g2 = gcd(P, M);

        ll n1 = N / g1;
        ll n2 = M / g2;

        ll invQ = mod_inv(Q / g1, n1);
        ll invP = mod_inv(P / g2, n2);

        ll best = -1;
        int ans = 0;

        for (int i = 0; i < K; i++) {
            ll dx = (a[i].first - x0) % N;
            if (dx < 0) dx += N;
            if (dx % g1) continue;

            ll dy = (a[i].second - y0) % M;
            if (dy < 0) dy += M;
            if (dy % g2) continue;

            ll t1 = (dx / g1) % n1;
            t1 = (t1 * invQ) % n1;

            ll t2 = (dy / g2) % n2;
            t2 = (t2 * invP) % n2;

            ll g = gcd(n1, n2);
            if ((t2 - t1) % g) continue;

            ll lcm = n1 / g * n2;

            ll p, q;
            exgcd(n1/g, n2/g, p, q);

            ll k = ((t2 - t1) / g) % (n2/g);
            if (k < 0) k += (n2/g);

            ll mult = (p % (n2/g) + (n2/g)) % (n2/g);
            k = (k * mult) % (n2/g);

            ll t = (t1 + n1 * k) % lcm;

            if (t == 0) continue;

            if (best == -1 || t < best) {
                best = t;
                ans = i;
            }
        }

        if (best == -1) ans = 0;

        ll lazarbeam = ans;
        cout << lazarbeam << '\n';
    }
}

void read_your_input() {
    main();
}
