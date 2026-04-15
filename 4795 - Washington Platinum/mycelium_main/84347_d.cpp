#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

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

int solve() {
	pii g, m;
	cin >> g.first >> g.second >> m.first >> m.second;
	deque<pii> gnext{g}, mnext{m};
	auto mandist = [&](pii a, pii b) {
		return abs(a.first - b.first) + abs(a.second - b.second);
	};
	set<pii> mvals{m}, gvals{g};

	pii delta[4] = {{-1, 0},
	                {1,  0},
	                {0,  -1},
	                {0,  1}};
	for (int t = 1; !mnext.empty(); ++t) {
		if (t % 2 == 0) {
			int gsz = gnext.size();
			for (int i = 0; i < gsz; ++i) {
				auto [x, y] = gnext.front();
				gnext.pop_front();
				for (auto &[dx, dy]: delta) {
					int nx = x + dx, ny = y + dy;
					if (mvals.count({nx, ny}) || gvals.count({nx, ny})) continue;
					gvals.insert({nx, ny});
					gnext.push_back({nx, ny});
				}
			}
		}
		if (t % 7 == 0) {
			int msz = mnext.size();
			for (int i = 0; i < msz; ++i) {
				auto [x, y] = mnext.front();
				mnext.pop_front();
				for (auto &[dx, dy]: delta) {
					int nx = x + dx, ny = y + dy;
					if (mvals.count({nx, ny}) || gvals.count({nx, ny})) continue;
					mvals.insert({nx, ny});
					mnext.push_back({nx, ny});
				}
			}
		}
	}
	cout << mvals.size() << '\n';
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}