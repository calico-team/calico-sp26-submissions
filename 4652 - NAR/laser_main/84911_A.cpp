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

/** 
 * Find the index of the first asteroid hit by the laser.
 * 		
 * K: Number of asteroids
 * N, M: Bounds for x- and y-coordinates
 * P, Q: Laser movement (P along y-axis, Q along x-axis)
 * X: List of x-coordinates of asteroids
 * Y: List of y-coordinates of asteroids
 */

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
	int x = X[0]; int y = Y[0];
	for (int i = 0; i < K; i++) {
		X[i] = ((X[i] - x) + N)%N;
		Y[i] = (Y[i] - y + M)%M; 
	}
	int g1 = gcd(N, Q);
	int g2 = gcd(M, P);
	int n2 = N/g1; int m2 = M/g2; int q2 = Q/g1; int p2 = P/g2;
	int R = 1e9; int m = -1;
	for (int i = 0; i < K; i++) {
		int x1 = X[i]; int y1 = Y[i];
		if ((x1%g1 != 0) || (y1%g2 != 0)) {
			continue;
		} else {
			int x2 = x1/g1;
			int y2 = y1/g2;
			// cout << "i, x2, y2: " << i << ", " << x2 << ", " << y2 << "\n"; 
			int x3 = (x2 * exp(q2, n2-2, n2))%n2;
			int y3 = (y2 * exp(p2, m2-2, m2))%m2;
			int g3 = gcd(n2, m2);
			// cout << x3 << ", " << y3 << "\n";
			// cout << "g3: " << g3 << "\n";
			// cout << (x3-y3) << "\n";
			if ((x3-y3)%g3 != 0) {continue;}
			// cout << "i: " << i << "\n";

			int d = (x3-y3)/g3;
			int n3 = n2/g3; int m3 = m2/g3;
			int u1 = ((-d)*exp(n3, m3-2, m3))%m3;
			int u2 = ((d)*exp(m3, n3-2, n3))%n3;
			if (u1 == 0 && x3 == 0) u1 = m3;
			ll r = (ll)n2*(ll)u1 + (ll)x3;
			// cout << "i, r: " << i << ", " << r << "\n";
			if (r < R && r != 0) {
				R = r;
				m = i;
			}
		}	
	}
	return m;
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