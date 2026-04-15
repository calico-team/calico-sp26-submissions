#include <bits/stdc++.h>]

using namespace std;

typedef long long ll;

const ll INF = 2e18;

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    extGCD(a, m, x, y);
    return (x % m + m) % m;
}

void solve() {
    int K;
    ll N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;

    vector<pair<ll, ll>> ast(K);
    for (int i = 0; i < K; ++i) {
        cin >> ast[i].first >> ast[i].second;
    }

    ll X0 = ast[0].first;
    ll Y0 = ast[0].second;

    ll min_t = INF;
    int best_idx = -1;

    for (int i = 0; i < K; ++i) {
        ll A = (ast[i].first - X0) % N;
        if (A < 0) A += N;
        ll B = (ast[i].second - Y0) % M;
        if (B < 0) B += M;

        ll g1, x1, y1;
        g1 = extGCD(Q, N, x1, y1);
        if (A % g1 != 0) continue;
        
        ll N_prime = N / g1;
        ll tx = (A / g1) % N_prime;
        tx = (tx * modInverse(Q / g1, N_prime)) % N_prime;

        ll g2, x2, y2;
        g2 = extGCD(P, M, x2, y2);
        if (B % g2 != 0) continue;
        
        ll M_prime = M / g2;
        ll ty = (B / g2) % M_prime;
        ty = (ty * modInverse(P / g2, M_prime)) % M_prime;

        ll diff = (ty - tx) % M_prime;
        if (diff < 0) diff += M_prime;

        ll g3, x3, y3;
        g3 = extGCD(N_prime, M_prime, x3, y3);
        if (diff % g3 != 0) continue;

        ll m_prime_g3 = M_prime / g3;
        ll k1 = (diff / g3) % m_prime_g3;
        k1 = (k1 * modInverse(N_prime / g3, m_prime_g3)) % m_prime_g3;

        ll t = tx + k1 * N_prime;
        ll L = N_prime / g3 * M_prime;
        
        t %= L;
        if (t <= 0) t += L;

        if (t < min_t) {
            min_t = t;
            best_idx = i;
        }
    }

    cout << best_idx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}