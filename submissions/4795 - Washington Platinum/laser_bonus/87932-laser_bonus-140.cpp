#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#define YESNO(condition) cout << ((condition) ? "YES" : "NO")
#define sfunc(a, b, c) ((a) = c((a), (b)))
#define smin(a, b) sfunc((a), (b), min)
#define smax(a, b) sfunc((a), (b), max)
#define SZ(a) (int)(a).size()
#define readall(arr, n) for (int i = 0; i < n; i++) cin >> (arr)[i]
#define printall(arr, n) for (int i = 0; i < n; i++) cout << (arr)[i] <<

const int inf = 2e9;
const ll infl = 4e18;
const ll MOD = 998244353;
const ll MAXN = 2e5 + 5;
int gcd(int a, int b, int &x, int &y) {
	x = 1, y = 0;
	int x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, y - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}
ll inv(ll a, ll m) {
	int x, y;
	int g = gcd(a, m, x, y);
	if (g != 1) {
		throw;
	} else {
		x = (x % m + m) % m;
		return x;
	}
}

void solve() {
	ll k, m, n, p, q;
	cin >> k >> n >> m >> p >> q;
	vector<pll> coords(n);
	vector<int> turns(n);
	auto solve = [](ll a, ll b, ll m) -> pll {
		// solve ax = b mod m
		ll g = __gcd(a, m);
		if (b % g != 0) {
			return {-1, -1};
		}
		m /= g, a /= g, b /= g;
		if (m == 1) {
			return {0, m};
		}
		ll ainv = inv(a, m);
		return {(1ll * b * ainv) % m, m};
	};
	pll minv{1e18, 1e18};
	pll start{-1, -1};
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		if (i == 0) {
			start = {x, y};
		}
		auto [r1, np] = solve(q % n, (x - start.first + n) % n, n);
		if (r1 == -1)continue;
		auto [r2, mp] = solve((1ll * np * p) % m, ((y - start.second - 1ll * r1 * p) % m + m) % m, m);
		if (r2 == -1) continue;
		ll val = (r1 + r2 * np) % (np * mp);
		if (val == 0) {
			val += np * mp;
		}
		smin(minv, (pll{val, i}));

	}
	cout << minv.second << '\n';
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}