#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		ll n, p, r, k; cin >> n >> p >> r >> k;
		vector<ll> e(n);
		for (ll& i : e) cin >> i;
		bool bad = false;
		for (int i = 0; i < n; ++i) {
			if (i % k == 0 && i != 0) p += r;
			p -= e[i];
			if (p < 0) bad = true;
		}
		cout << (bad ? "nah i'd lose\n" : "nah i'd win\n");
	}
	return 0;
}

