#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b)
{
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll modInverse(ll n, ll m)
{
    // Check if inverse exists
    if (gcd(n, m) != 1)
        return -1;
        
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
        return 0;

    while (n > 1) {
        
        // q is quotient
        ll q = n / m;
        ll t = m;

        // m is remainder now, process same as Euclid's algo
        m = n % m;
        n = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
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
	// YOUR CODE HERE
	ll x0 = X[0];
	ll y0 = Y[0];

	ll x_gcd = gcd(Q, N);
	ll m1 = N/x_gcd;
	ll q_inv = modInverse(Q/x_gcd, m1);
	ll y_gcd = gcd(P, M);
	ll m2 = M/y_gcd;
	ll p_inv = modInverse(P/y_gcd, m2);
	
	ll smallestInd = -1;
	ll smallestVal = -1;
	for (int i = 0; i < X.size(); i++) {
		ll xi = X[i];
		ll yi = Y[i];
		ll dx = xi-x0;
		ll dy = yi-y0;
		if (dx < 0) dx += N;
		if (dy < 0) dy += M;

		// solve t*Q = (Xi - X0) mod N
		if (dx % x_gcd != 0) continue;
		ll r1 = (dx / x_gcd * q_inv) % m1;

		// solve t*P = (Yi-Y0) mod M
		if (dy % y_gcd != 0) continue;
		ll r2 = (dy / y_gcd * p_inv) % m2;

		// solve r1+k*m1 = r2 (mod m2) where m1=N/x_gcd and m2=M/y_gcd
		ll dxy = r2 - r1;
		while (dxy < 0) dxy += m2;
		ll mods_gcd = gcd(m1, m2);
		if (dxy % mods_gcd != 0) continue;
		ll k = (modInverse(m1/mods_gcd, m2/mods_gcd) * dxy/mods_gcd) % (m2/mods_gcd);
		ll t = r1 + k * m1;
		if (t == 0) {
			t = m1*m2 / mods_gcd; // the full cycle repeats every lcm(m1, m2)
		}
		if (smallestVal == -1) {
			smallestVal = t;
			smallestInd = i;
		} else if (smallestVal > t) {
			smallestVal = t;
			smallestInd = i;
		}
	}
	return smallestInd;
}


int main() {
	ll T; cin >> T;
	while (T--) {
		ll K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		vector<ll> X(K), Y(K);
		for (ll i = 0; i < K; i++) {
			ll a, b; cin >> a >> b;
			X[i] = a;
			Y[i] = b;
		}
		cout << solve(K, N, M, P, Q, X, Y) << endl;
	}
	return 0;
}