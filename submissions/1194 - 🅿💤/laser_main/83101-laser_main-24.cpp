#include <bits/stdc++.h>
using namespace std;

int t;
int k, n, m, p, q;
vector<pair<int, int>> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;

	while (t--) {
		cin >> k >> n >> m >> p >> q;
		v.clear();
		v.reserve(k);
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			v.emplace_back(x, y);
		}

		auto [cx, cy] = v.front();
		for (int i = 0; i <= n * m; i++) {
			cx = (cx + q) % n;
			cy = (cy + p) % m;

			bool found = false;
			for (auto it = v.begin(); it < v.end(); ++it) {
				if (it->first == cx && it->second == cy) {
					cout << (it - v.begin()) << '\n';
					found = true;
					break;
				}
			}
			if (found)
				break;
		}
	}

	return 0;
}
