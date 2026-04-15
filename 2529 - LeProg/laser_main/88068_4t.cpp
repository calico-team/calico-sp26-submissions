#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		ll k, n, m, p, q; cin >> k >> n >> m >> p >> q;
		vector<pair<ll, ll>> vp(k);
		for (pair<ll, ll>& i : vp) cin >> i.first >> i.second;
		int a = vp[0].first, b = vp[0].second;
		vector<vector<int>> time(n, vector<int>(m, -1));
		int ct = 0;
		while (true) {
			a = (a + q) % n; b = (b + p) % m;
			if (time[a][b] != -1) break;
			++ct;
			time[a][b] = ct;
		}
		int mn = INT32_MAX;
		int best = -1;
		for (int i = 0; i < k; ++i) {
			if (time[vp[i].first][vp[i].second] != -1 && time[vp[i].first][vp[i].second] < mn) {
				mn = time[vp[i].first][vp[i].second];
				best = i;
			}
		}
		cout << best << '\n';
	}
	return 0;
}

