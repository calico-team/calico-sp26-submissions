#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll extGCD(ll a, ll b, ll & x, ll & y){
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d= extGCD(b, a % b, x1, y1);
	x =y1;
	y =x1 - y1 * (a / b);
	return d;
}

pair<ll, ll> sol_congrue(ll a, ll b, ll m){
	a = (a % m + m) % m;
	b = (b % m + m) % m;
	ll x, y;
	ll g = extGCD(a, m, x, y);

	if (b % g != 0) return {-1, -1};
	ll m0 = m / g;

	x = (x % m0 + m0) % m0;

	ll ans = ((b / g) % m0 * x) % m0;
	return {ans, m0};
}

pair<ll, ll> merge_cong(ll a1, ll m1, ll a2, ll m2){
	pair<ll, ll> res = sol_congrue(m1, a2 - a1, m2);
	if (res.first == -1) return {-1, -1};

	ll k = res.first;
	ll g = std::gcd(m1, m2);
	ll m0 = (m1 / g) * m2;

	ll x0 = (a1 + k * m1) % m0;
	return {x0, m0};
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int T;
	if(!(cin >> T)) return 0;

	while (T--){
		ll k, n, m, p, q;
		cin >> k >> n >> m >> p >> q;

		vector<pair<ll, ll>> aeste(k);
		for (int i = 0; i < k; i++){
			cin >> aeste[i].first >> aeste[i].second;
		}

		ll x0 = aeste[0].first;
		ll y0 = aeste[0].second;

		ll min_s = -1;
		int index_h = 0;

		for (int i = 0; i < k; i++){
			ll xi = aeste[i].first;
			ll yi = aeste[i].second;

			ll dx = ((xi - x0) % n + n) % n;
			ll dy = ((yi - y0) % m + m) % m;

			pair<ll, ll> res_x = sol_congrue(q, dx, n);
			pair<ll, ll> res_y = sol_congrue(p, dy, m);

			if (res_x.first == -1 || res_y.first == -1) continue;

			pair<ll, ll> res = merge_cong(res_x.first, res_x.second, res_y.first, res_y.second);

			if (res.first != -1){
			ll s = res.first;
				if ( s == 0){
					s = res.second;
				}
				
				if (min_s == -1 || s < min_s){
					min_s = s;
					index_h = i;
				}
			}
		}
		cout << index_h << "\n";
	}

	return 0;
}