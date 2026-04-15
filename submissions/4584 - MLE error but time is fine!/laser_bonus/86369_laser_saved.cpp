#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll modinv(ll a, ll mod) {
    ll x, y;
    extgcd(a, mod, x, y);
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

ll norm(ll a, ll mod) {
    a %= mod;
    if (a < 0) a += mod;
    return a;
}

void solve() {
    int K;
    ll N, M, P, Q; 
    cin >> K >> N >> M >> P >> Q; 
    vector<ll> X(K), Y(K);

    for (int i = 0; i < K; i++) {
        cin >> X[i] >> Y[i];
    }

    int ans = -1;
    ll time = (1LL << 62);

    ll x0 = X[0], y0 = Y[0];

    ll gx = gcd(N, Q);
    ll gy = gcd(M, P);

    ll modx = N / gx;
    ll mody = M / gy;

    ll invQ = (modx == 1 ? 0 : modinv(Q / gx, modx));
    ll invP = (mody == 1 ? 0 : modinv(P / gy, mody));

    ll g = gcd(modx, mody);
    ll cycle = (modx / g) * mody;

    for (int i = 0; i < K; i++) {
        ll dx = norm(X[i] - x0, N);
        ll dy = norm(Y[i] - y0, M);

        if (dx % gx != 0 || dy % gy != 0) continue;

        ll ax = (modx == 1 ? 0 : (__int128)(dx / gx) * invQ % modx);
        ll ay = (mody == 1 ? 0 : (__int128)(dy / gy) * invP % mody);

        if ((ay - ax) % g != 0) continue;

        ll k = 0;
        ll t = 0;

        if (mody / g == 1) {
            t = ax;
        } else {
            ll mod2 = mody / g;
            ll inv = modinv(modx / g, mod2);
            ll rhs = norm((ay - ax) / g, mod2);
            k = (__int128)rhs * inv % mod2;
            t = (ax + (__int128)modx * k) % cycle;
        }

        if (t == 0) t = cycle;

        if (t < time) {
            ans = i;
            time = t; 
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t; 
    while(t--)
        solve();
}
