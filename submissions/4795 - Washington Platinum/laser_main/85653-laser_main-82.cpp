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

ll exp(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

void solve() {
	ll k, m, n, p, q;
	cin >> k >> m >> n >> p >> q;
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
		ll ainv = exp(a, m - 2, m);
		return {(1ll * b * ainv) % m, m};
	};
	pll minv{2e9, 2e9};
	pll start{-1, -1};
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> y >> x;
		if (i == 0) {
			start = {x, y};
		}
		auto [r1, np] = solve(p % n, (x - start.first + n) % n, n);
		if (r1 == -1)continue;
		auto [r2, mp] = solve((1ll * np * q) % m, ((y - start.first - 1ll * r1 * q) % m + m) % m, m);
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