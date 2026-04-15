#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;

ll egcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll g = egcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

ll inv(ll a, ll mod) {
	ll x, y;
	egcd(a, mod, x, y);
	x %= mod;
	if (x < 0) x += mod;
	return x;
}

bool crt(ll a1, ll m1, ll a2, ll m2, ll &v, ll &mod) {
	ll x, y;
	ll g = egcd(m1, m2, x, y);
	ll d = a2 - a1;
	if (d % g != 0) return false;
	mod = m1 / g * m2;
	ll sm = m2 / g;
	ll t = ((d / g) % sm + sm) % sm;
	t = (t * (x % sm + sm)) % sm;
	v = (a1 + m1 * t) % mod;
	if (v < 0) v += mod;
	return true;
}

bool hit(ll dx, ll dy, ll n, ll m, ll sx, ll sy, ll tx, ll ty, ll &v, ll &mod) {
	ll ax = (tx - sx) % n;
	if (ax < 0) ax += n;
	ll ay = (ty - sy) % m;
	if (ay < 0) ay += m;

	ll gx = gcd(dx, n);
	if (ax % gx != 0) return false;
	ll mx = n / gx;
	ll rx = (ax / gx) % mx;
	rx = (rx * inv(dx / gx, mx)) % mx;

	ll gy = gcd(dy, m);
	if (ay % gy != 0) return false;
	ll my = m / gy;
	ll ry = (ay / gy) % my;
	ry = (ry * inv(dy / gy, my)) % my;

	return crt(rx, mx, ry, my, v, mod);
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
	ll lazarbeam = gcd((ll) P, (ll) Q);
	ll dx = Q / lazarbeam;
	ll dy = P / lazarbeam;

	ll cv, cl;
	hit(dx, dy, N, M, X[0], Y[0], X[0], Y[0], cv, cl);

	ll bt = cl;
	int bi = 0;

	for (int i = 1; i < K; i++) {
		ll t, mod;
		if (!hit(dx, dy, N, M, X[0], Y[0], X[i], Y[i], t, mod)) {
			continue;
		}
		if (t == 0) t = mod;
		if (t < bt || (t == bt && i < bi)) {
			bt = t;
			bi = i;
		}
	}

	return bi;
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