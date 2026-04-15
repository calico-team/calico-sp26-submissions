#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;

// Extended GCD: returns gcd, sets x,y such that a*x + b*y = gcd
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Solve: t ≡ r (mod m), returns {r, m} or {-1,-1} if no solution
// Combined with existing t ≡ cr (mod cm)
pair<ll,ll> combine(ll r1, ll m1, ll r2, ll m2) {
    // t = r1 + m1*k, need r1 + m1*k ≡ r2 (mod m2)
    // m1*k ≡ r2-r1 (mod m2)
    ll diff = ((r2 - r1) % m2 + m2) % m2;
    ll x, y;
    ll g = extgcd(m1 % m2, m2, x, y);
    if (diff % g != 0) return {-1, -1};
    ll m2g = m2 / g;
    // k = x * (diff/g) mod (m2/g)
    ll k = (lll)x % m2g * ((diff / g) % m2g) % m2g;
    k = (k % m2g + m2g) % m2g;
    ll lcm = m1 / g * m2;
    ll r = r1 + m1 * k;
    r = ((r % lcm) + lcm) % lcm;
    return {r, lcm};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        ll K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;
        
        vector<ll> X(K), Y(K);
        for (int i = 0; i < K; i++) cin >> X[i] >> Y[i];
        
        ll lazarbeam = -1;
        ll x0 = X[0], y0 = Y[0];
        ll best_t = -1;
        int best_idx = -1;

        for (int i = 0; i < K; i++) {
            // Need t > 0:
            // t*Q ≡ (X[i]-x0) mod N
            // t*P ≡ (Y[i]-y0) mod M
            ll dx = ((X[i] - x0) % N + N) % N;
            ll dy = ((Y[i] - y0) % M + M) % M;

            // Solve t*Q ≡ dx (mod N)
            ll g1, inv1, dummy;
            g1 = extgcd(Q, N, inv1, dummy);
            ll t1, m1;
            if (dx % g1 != 0) { /* no solution on x */ goto no_sol; }
            {
                ll N1 = N / g1;
                t1 = (lll)(inv1 % N1 + N1) % N1 * ((dx / g1) % N1) % N1;
                m1 = N1 * g1; // = N
                // wait, period is N/g1
                m1 = N / g1;
                t1 = ((lll)(inv1 % m1 + m1) % m1 * ((dx/g1) % m1)) % m1;
            }

            // Solve t*P ≡ dy (mod M)
            {
                ll g2, inv2, dummy2;
                g2 = extgcd(P, M, inv2, dummy2);
                if (dy % g2 != 0) goto no_sol;
                ll m2 = M / g2;
                ll t2 = ((lll)(inv2 % m2 + m2) % m2 * ((dy/g2) % m2)) % m2;

                // CRT combine t ≡ t1 (mod m1) and t ≡ t2 (mod m2)
                auto [r, mod] = combine(t1, m1, t2, m2);
                if (r == -1) goto no_sol;

                // t must be > 0
                ll t = r;
                if (t == 0) t += mod;
                if (mod == 0) goto no_sol;

                if (best_t == -1 || t < best_t) {
                    best_t = t;
                    best_idx = i;
                }
            }
            continue;
            no_sol:;
        }

        lazarbeam = best_idx;
        cout << lazarbeam << '\n';
    }
    return 0;
}

void read_your_input() {
    // T test cases, each: K N M P Q, then K lines of Xi Yi
}