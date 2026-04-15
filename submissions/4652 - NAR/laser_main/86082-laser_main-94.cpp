#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;

ll exp(ll x, ll n, ll m) {
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}
ll G(ll u, ll v, ll &x, ll &y) {
    if (u == 0) {x=0;y=1;return v;}
    ll x1, y1;
    ll gd = G(v%u,u,x1,y1);
    x = y1-(v/u)*x1; y = x1;
    return gd;
}
ll inv(ll a, ll m) {
    ll x, y; x = y = 0;
    ll g = G(a,m,x,y);
    return (x+m)%m;
}

ll CRT(vector<ll> &a, vector<ll> &b) {
    ll M = 1; ll res = 0;
    for (ll t: b) M = M*t;
    for (int i = 0; i < a.size(); i++) {
        ll tmp = M/b[i];
        res = (res + (tmp*a[i]*inv(tmp, b[i])))%M;
    }
    return res;
}

/** 
 * Find the index of the first asteroid hit by the laser.
 * 		
 * K: Number of asteroids
 * N, M: Bounds for x- and y-coordinates
 * P, Q: Laser movement (P along y-axis, Q along x-axis)
 * X: List of x-coordinates of asteroids
 * Y: List of y-coordinates of asteroids
 */

ll solve(ll K, ll N, ll M, ll P, ll Q, vector<ll> X, vector<ll> Y) {
	ll x = X[0]; ll y = Y[0];
	for (ll i = 0; i < K; i++) {
		X[i] = ((X[i] - x) + N)%N;
		Y[i] = (Y[i] - y + M)%M; 
	}
	ll g1 = gcd(N, Q);
	ll g2 = gcd(M, P);
	ll n2 = N/g1; ll m2 = M/g2; ll q2 = Q/g1; ll p2 = P/g2;
	ll R = 1e18; ll m = -1;
	for (int i = 0; i < K; i++) {
		ll x1 = X[i]; ll y1 = Y[i];
		if ((x1%g1 != 0) || (y1%g2 != 0)) {
			continue;
		} else {
			ll x2 = x1/g1;
			ll y2 = y1/g2;
			ll x3 = (x2 * exp(q2, n2-2, n2))%n2;
			ll y3 = (y2 * exp(p2, m2-2, m2))%m2;
			ll g3 = gcd(n2, m2);
			if ((x3-y3)%g3 != 0) {continue;}
            vector<ll> a; 
            a.push_back(x3);
            a.push_back(y3);
            vector<ll> b;
            b.push_back(n2);
            b.push_back(m2);
            ll r = CRT(a, b);
			// ll d = (x3-y3)/g3;
			// ll n3 = n2/g3; ll m3 = m2/g3;
			// ll u1 = ((-d)*exp(n3, m3-2, m3))%m3;
			// ll u2 = ((d)*exp(m3, n3-2, n3))%n3;
			// if (u1 == 0 && x3 == 0) u1 = m3;
			// ll r = (ll)n2*(ll)u1 + (ll)x3;
			// cout << "i, r: " << i << ", " << r << "\n";
			if (r < R && r != 0) {
				R = r;
				m = i;
			}
		}	
	}
    if (m2*n2 < R) {
        m = 0;
    }
	return m;
}


int main() {
	ll T; cin >> T;
	while (T--) {
		ll K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		vector<ll> X(K), Y(K);
		for (int i = 0; i < K; i++) {
			ll a, b; cin >> a >> b;
			X[i] = a;
			Y[i] = b;
		}
		cout << solve(K, N, M, P, Q, X, Y) << endl;
	}
	return 0;
}