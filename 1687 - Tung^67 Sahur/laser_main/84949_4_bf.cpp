#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int k;
		ll n, m, p, q;
		cin >> k >> n >> m >> p >> q;

		vector<pll> arr(k);
		vector<vector<int>> asteroidIndex(n, vector<int>(m, -1));
		map<pll, vector<int>> asteroidLines;
		for (int i = 0; i < k; i++) {
			cin >> arr[i].first >> arr[i].second;
			asteroidIndex[arr[i].first][arr[i].second] = i;
		}
		
		pll pos = arr[0];
		auto& [x, y] = pos;
		vector<vector<bool>> seen(n, vector<bool>(m, false));
		while (!seen[x][y]) {
			seen[x][y] = true;
			x += q;
			y += p;
			if (x >= n)
				x -= n;
			if (y >= m)
				y -= m;
			if (asteroidIndex[x][y] >= 0) {
				cout << asteroidIndex[x][y] << '\n';
				break;
			}
		}
	}
}
