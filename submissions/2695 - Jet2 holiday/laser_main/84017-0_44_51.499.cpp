#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod(ll a, ll m) { 
    return (a % m + m) % m; 
    
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1; y = 0; return a; }
    ll d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}




pair<ll, ll> solve_linear(ll a, ll b, ll m) {
    a = mod(a, m); b = mod(b, m);
    ll g = gcd(a, m);
    if (b % g) return {-1, -1};
    a /= g; 
    b /= g; 
    m /= g;
    ll x, y;
    extgcd(a, m, x, y);
    ll x0 = mod(b * x, m);
    return {x0, m};
}




pair<ll, ll> crt(ll a1, ll m1, ll a2, ll m2) {
    ll g = gcd(m1, m2);
    if ((a2 - a1) % g) return {-1, -1};
    ll l = m1 / g * m2;
    ll m1_g = m1 / g, m2_g = m2 / g;
    ll diff = (a2 - a1) / g;
    diff = mod(diff, m2_g);
    ll x, y;
    extgcd(m1_g, m2_g, x, y);
    ll k = mod(diff * x, m2_g);
    ll a = (a1 + k * m1) % l;
    return {a, l};
}





int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
    ll x0 = X[0], y0 = Y[0];
    ll best_t = LLONG_MAX;
    int best_idx = -1;

    for (int i = 0; i < K; ++i) {
        ll dx = mod(X[i] - x0, N);
        ll dy = mod(Y[i] - y0, M);

        auto sol1 = solve_linear(Q, dx, N);
        auto sol2 = solve_linear(P, dy, M);
        if (sol1.first == -1 || sol2.first == -1) continue;

        auto merged = crt(sol1.first, sol1.second, sol2.first, sol2.second);
        if (merged.first == -1) continue;

        ll t = merged.first;
        ll L = merged.second;

        if (t == 0 && L > 0) t = L;
        if (t <= 0) continue;

        if (t < best_t) {
            best_t = t;
            best_idx = i;
        }
    }
    return best_idx;
}



int main() {
	int T; cin >> T;
	while (T--) {
		int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		vector<int> X(K), Y(K);
		for (int i = 0; i < K; i++) {
			int a, b; cin >> a >> b;
			X[i] = a;
			Y[i] = b;
		}
		cout << solve(K, N, M, P, Q, X, Y) << endl;
	}
	return 0;
}