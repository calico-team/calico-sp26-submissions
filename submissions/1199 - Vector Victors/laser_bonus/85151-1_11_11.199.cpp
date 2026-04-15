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
	ll a = X[0];
	ll b = Y[0];
	ll factX = gcd(Q, N);
	ll mInvX = modInverse(Q/factX, N/factX);
	ll factY = gcd(P, M);
	ll mInvY = modInverse(P/factY, M/factY);
	ll smallestInd = -1;
	ll smallestVal = -1;
	for (int i = 0; i < X.size(); i++) {
		ll x = X[i];
		ll shift = x-a;
		if (shift < 0) shift += N;
		if (shift == 0) shift = N;
		if (shift % factX != 0) {
			continue; // asteroid unreachable
		}
		shift /= factX;

		ll tX = shift * mInvX;

		ll y = Y[i];
		shift = y-b;
		if (shift < 0) shift += M;
		if (shift == 0) shift = M;
		if (shift % factY != 0) {
			continue; // asteroid unreachable
		}
		shift /= factY;

		ll tY = shift * mInvY;

		ll lcm = tX * tY / gcd(tX, tY);
		//cout << i << " " << tX << " " << tY << " " << lcm << "\n";

		if (smallestVal == -1) {
			smallestInd = i;
			smallestVal = lcm;
		} else if (lcm < smallestVal) {
			smallestInd = i;
			smallestVal = lcm;
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