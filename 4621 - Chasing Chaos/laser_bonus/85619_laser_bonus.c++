#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll mod_inv(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

ll crt(ll r1, ll m1, ll r2, ll m2) {
    ll g = gcd(m1, m2);
    if ((r1 - r2) % g != 0) return -1;
    ll p = m1 / g;
    ll q = m2 / g;
    ll inv = mod_inv(p, q);
    ll lcm = p * q * g;
    ll x = r1 + m1 * ((inv * ((r2 - r1) / g % q + q)) % q);
    return x % lcm;
}

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
    int sx = X[0];
    int sy = Y[0];
    
    unordered_map<ll, int> best;
    
    for (int i = 1; i < K; i++) {
        int dx = (X[i] - sx + N) % N;
        int dy = (Y[i] - sy + M) % M;
        
        int gx = gcd(Q, N);
        int gy = gcd(P, M);
        
        if (dx % gx != 0 || dy % gy != 0) {
            continue;
        }
        
        int n1 = N / gx;
        int q1 = Q / gx;
        int dx1 = dx / gx;
        
        int m1 = M / gy;
        int p1 = P / gy;
        int dy1 = dy / gy;
        
        ll t1 = (dx1 * 1LL * mod_inv(q1 % n1, n1)) % n1;
        ll t2 = (dy1 * 1LL * mod_inv(p1 % m1, m1)) % m1;
        
        ll t = crt(t1, n1, t2, m1);
        
        if (t == -1) {
            continue;
        }
        
        ll period = (ll)n1 * m1 / gcd(n1, m1);
        if (t == 0) {
            t = period;
        }
        
        if (best.find(t) == best.end() || best[t] > i) {
            best[t] = i;
        }
    }
    
    if (best.empty()) {
        return 0;
    }
    
    ll mn = 1e18;
    int ans = 0;
    for (auto& p : best) {
        if (p.first < mn) {
            mn = p.first;
            ans = p.second;
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
        int K, N, M, P, Q; 
        cin >> K >> N >> M >> P >> Q;
        vector<int> X(K), Y(K);
        for (int i = 0; i < K; i++) {
            cin >> X[i] >> Y[i];
        }
        cout << solve(K, N, M, P, Q, X, Y) << '\n';
    }
    return 0;
}