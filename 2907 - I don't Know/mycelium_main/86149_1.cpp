#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll x1, y1, d = extgcd(b, a % b, x1, y1);
    x = y1; y = x1 - y1 * (a / b);
    return d;
}

ll inv(ll a, ll m) {
    ll x, y; extgcd(a, m, x, y);
    return (x % m + m) % m;
}

void solve() {
    ll K, N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;
    
    vector<pair<ll, ll>> a(K);
    for (auto &[x, y] : a) cin >> x >> y;

    ll x0 = a[0].first, y0 = a[0].second;
    
    ll gx = std::gcd(Q, N), Np = N / gx, iQ = inv(Q / gx, Np);
    ll gy = std::gcd(P, M), Mp = M / gy, iP = inv(P / gy, Mp);
    ll g = std::gcd(Np, Mp), M2 = Mp / g, iN2 = inv(Np / g, M2);

    ll min_t = -1, ans = -1;

    for (int i = 0; i < K; ++i) {
        ll dx = (a[i].first - x0 + N) % N;
        ll dy = (a[i].second - y0 + M) % M;

        if (dx % gx || dy % gy) continue;

        ll tx = (dx / gx) * iQ % Np;
        ll ty = (dy / gy) * iP % Mp;
        ll diff = (ty - tx % Mp + Mp) % Mp;

        if (diff % g) continue;

        ll t = tx + (diff / g) * iN2 % M2 * Np;
        
        if (t == 0) t = Np * M2; 

        if (min_t == -1 || t < min_t) {
            min_t = t;
            ans = i;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; if (cin >> T) while (T--) solve();
}