#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll inv(ll v, ll m) {
	ll x, y;
	ll g = gcd(v, m, x, y);
	return (x % m + m) % m;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		ll k, n, m, p, q; cin >> k >> n >> m >> p >> q;
		q %= n; p %= m;
		vector<pair<ll, ll>> vp(k);
		for (pair<ll, ll>& i : vp) cin >> i.first >> i.second;
		ll a = vp[0].first, b = vp[0].second;
		a = (a + q) % n; b = (b + p) % m;
		int best = -1;
		ll besttime = 1e18;
		for (int i = 0; i < k; ++i) {
			ll v1 = ((vp[i].first - a) % n + n) % n;
			ll g1 = gcd(n, q);
			if (v1 % g1 != 0) continue;
			bool ok1 = false;
			if (q == 0 && v1 != 0) continue;
			if (q == 0) ok1 = true;
			else v1 = (v1 / g1) * inv(q / g1, n / g1) % (n / g1);

			ll v2 = ((vp[i].second - b) % m + m) % m;
			ll g2 = gcd(m, p);
			if (v2 % g2 != 0) continue;
			bool ok2 = false;
			if (p == 0 && v2 != 0) continue;
			if (p == 0) ok2 = true;
			else v2 = (v2 / g2) * inv(p / g2, m / g2) % (m / g2);

			ll m1 = n / g1, m2 = m / g2;
			ll time = -1;
			if (ok1 && ok2) {
				time = 0;
			} else if (ok1) {
				time = v2;
			} else if (ok2) {
				time = v1;
			} else {
				ll v = ((v2 - v1) % m2 + m2) % m2;
				m1 %= m2;
				ll g3 = gcd(m1, m2);
				if (m1 == 0 && v != 0) continue;
				ll k;
				if (m1 == 0) k = 0;
				else k = (v / g3) * inv(m1 / g3, m2 / g3) % (m / g3);
				ll m3 = m / g3;
				time = m1 * k + v1;
			}
			if (time < besttime) {
				besttime = time;
				best = i;
			}
		}
		cout << best << '\n';
	}
	return 0;
}

