#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

array<ll, 3> gcd(ll X, ll Y, ll ax, ll bx, ll ay, ll by) {
    if (X > Y) {swap(X, Y); swap(ax, ay); swap(bx, by);} // wlog x < y

    if (Y % X == 0) return {X, ax, bx};

    ll divid = Y / X;
    Y -= divid * X;
    ay -= divid * ax;
    by -= divid * bx;

    return gcd(X, Y, ax, bx, ay, by);

}

ll inv(ll X, ll M) {
	auto result = gcd(X, M, 1, 0, 0, 1);
	return ((result[1] % M) + M) % M;
}

ll crt(ll a, ll m1, ll b, ll m2) {
	auto result = gcd(m1, m2, 1, 0, 0, 1);
	// cout << "result = " << result[1] << '\n';
	
	// cout << b - a << " " << __gcd(m1, m2) << '\n';
	if (((b - a) % (__gcd(m1, m2))) != 0) return -1;
	
	ll lcm = a / __gcd(m1, m2) * b;
	
	return ((a + (result[1]) * ((b - a) / __gcd(m1, m2)) * m1) % lcm + lcm) % lcm;
}

int solve() {
	ll K, N, M, P, Q;
	cin >> K >> N >> M >> P >> Q;
	
	vector<ll> Ax(K), Ay(K);
	for (int i=0; i<K; i++) cin >> Ax[i] >> Ay[i];
	
	ll X = Ax[0], Y = Ay[0];
	
	ll X_multiple = __gcd(Q, N);
	ll X_inverse = inv(Q, N);
	ll real_X = N/X_multiple;
	
	ll Y_multiple = __gcd(P, M);
	ll Y_inverse = inv(P, M);
	ll real_Y = M/Y_multiple;
	
	ll Res_a = LLONG_MAX, Res_b = -1; 
	for (int i=0; i<K; i++) {
		// cout << Ax[i] << ' ' << Ay[i] << '\n';
		// cout << X << " + " << P << "x = " << Ax[i] << '\n';
		if ((Ax[i] - X) % X_multiple) continue;
		if ((Ay[i] - Y) % Y_multiple) continue;
		// cout << "x = " << ((Ax[i] - X) / X_multiple) * X_inverse << " mod " << real_X << '\n';
		ll x_mod = ((Ax[i] - X) / X_multiple) * X_inverse;
		ll y_mod = ((Ay[i] - Y) / Y_multiple) * Y_inverse;
		
		
		// cout << Y << " + " << Q << "y = " << Ay[i] << '\n';
		// cout << "y = " << ((Ay[i] - Y) / Y_multiple) * Y_inverse << " mod " << real_Y << '\n';
		
		ll result = crt(x_mod, real_X, y_mod, real_Y);
		// cout << "SOL: " << result << '\n';
		if (result == -1) continue;
		ll lcm = real_X / gcd(real_X, real_Y) * real_Y;
		if (result == 0) result = lcm;
		if (result < Res_a) {
			Res_a = result;
			Res_b = i;
		}
	}
	cout << Res_b << '\n';
	// 
	// 16 mod 21
	// 5 mod 17
	// 4 * 17 + 7 * 21
	
	
	
	
	
	
	return 0;
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	ll Q;
	cin >> Q;
	while (Q--) {
		solve();
	}
	
	return 0;
}