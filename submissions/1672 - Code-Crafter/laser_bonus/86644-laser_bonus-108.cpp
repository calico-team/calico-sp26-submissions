#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;

/** 
 * Find the index of the first asteroid hit by the laser.
 * 		
 * K: Number of asteroids
 * N, M: Bounds for x- and y-coordinates
 * P, Q: Laser movement (P along y-axis, Q along x-axis)
 * X: List of x-coordinates of asteroids
 * Y: List of y-coordinates of asteroids
 */
static ll mod_norm(ll x, ll mod) {
    x %= mod; if (x < 0) x += mod; return x;
}

static ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { 
		x = 1; 
		y = 0;
		return a; 
	}
    ll x1, y1;
    
	ll g = ext_gcd(b, a % b, x1, y1);
    
	x = y1; y = x1 - (a / b) * y1;
    
	return g;
}
static bool solve_cong(ll step, ll mod, ll delta, ll &res, ll &new_mod) {
    ll g = gcd(step, mod);
    if (delta % g)
		return false;
    step /= g;
	mod /= g; 
	delta /= g;
    new_mod = mod;
    ll inv, dummy;
    
	ext_gcd(mod_norm(step, mod), mod, inv, dummy);

    res = (ll)((__int128)mod_norm(delta, mod) * mod_norm(inv, mod) % mod);

    return true;
}
static bool crt(ll a1, ll m1, ll a2, ll m2, ll &a, ll &lcm) {
    ll g = gcd(m1, m2);

    if ((a2 - a1) % g) 
		return false;
    
	ll m2g = m2 / g;
    ll inv, dummy;
    
	ext_gcd(mod_norm(m1 / g, m2g), m2g, inv, dummy);
    
	ll k = (ll)((__int128)mod_norm((a2 - a1) / g, m2g) * mod_norm(inv, m2g) % m2g);
    lcm = m1 / g * m2;
    
	a = mod_norm(a1 + m1 * k, lcm);
    
	return true;
}

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
	ll x0 = X[0], y0 = Y[0];
	ll mod_x = N/gcd((ll)Q,(ll)N);
	ll mod_y = M/gcd((ll)P, (ll)M);

	ll lsrbem = mod_x/ gcd(mod_x, mod_y) * mod_y;

	ll best_t = (ll)4e18;
	int best_i = -1;


	for (int i = 0; i < K; i++){
		ll dx = mod_norm(X[i] - x0,N);
	
		ll dy = mod_norm(Y[i] - y0, M);
	
		ll tx, mx, ty, my;
    
		if (!solve_cong(Q, N, dx, tx, mx)) 
			continue;
		
        if (!solve_cong(P, M, dy, ty, my)) 
			continue;
		
        ll t, period;
        
		if (!crt(tx, mx, ty, my, t, period)) 
			continue;
		
        if (i == 0 && t == 0) 
			t = lsrbem;
		
        if (t < best_t) { 
			best_t = t;
			best_i = i; 
		}
	}


	return best_i;
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