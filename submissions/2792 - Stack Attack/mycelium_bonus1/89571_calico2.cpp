#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define rep(i, s, e) for (ll i = s; i < e; i++)
#define upmax(a, b) a = max(a, b)
#define upmin(a, b) a = min(a, b)

using namespace std;
using ll = int;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;

vll dx = { 1, -1, 0, 0 };
vll dy = { 0, 0, 1, -1 };

vll ans = { 1, 2, 2, 5, 8, 9, 16, 19, 28, 32, 38, 49, 55, 70, 76, 84, 101, 110, 129, 140, 149, 172, 184, 209, 221, 233, 263, 275, 307, 322, 336, 371, 387, 424, 440, 459, 498, 517, 560, 579, 599, 645, 666, 713, 737, 758, 810, 834, 888, 912, 937, 995, 1019, 1080, 1107, 1134, 1197, 1226, 1291, 1320, 1351, 1418, 1450, 1521, 1553, 1585, 1660, 1693, 1769, 1805, 1838, 1919, 1955, 2038, 2074, 2112, 2198, 2235, 2324, 2363, 2403, 2494, 2536, 2629, 2671, 2714, 2810, 2854, 2953, 2998, 3042, 3146, 3191, 3296, 3344, 3390, 3499, 3547, 3659, 3707, 3758, 3872, 3922, 4039, 4091, 4143, 4262, 4317, 4438, 4493, 4548, 4673, 4729, 4857, 4914, 4970, 5103, 5160, 5294, 5354, 5413, 5550, 5611, 5751, 5811, 5875, 6017, 6080, 6225, 6290, 6354, 6502, 6569, 6718, 6786, 6853, 7007, 7075, 7232 };

void solve3() {
	ll xg, yg;
	cin >> xg >> yg;
	ll xm, ym;
	cin >> xm >> ym;
	xm -= xg;
	ym -= yg;
	xm = abs(xm);
	ym = abs(ym);
	cout << ans[xm * 201 + ym] << '\n';
}

void solve() {
	ll xg, yg;
	cin >> xg >> yg;
	ll xm, ym;
	cin >> xm >> ym;
	set<pll> g, m;
	set<pll> ans_m;
	set<pll> ans_g;
	g.insert({ xg, yg });
	ans_g.insert({ xg, yg });
	m.insert({ xm, ym });
	ans_m.insert({ xm, ym });
	rep(t, 1, 20000) {
		if (m.size() == 0) break;
		if (t % 2 == 0) {
			set<pll> to_erase_g;
			set<pll> to_add_g;
			for (auto& it : g) {
				ll x = it.first, y = it.second;
				bool check = false;
				rep(i, 0, 4) {
					ll nei_x = x + dx[i];
					ll nei_y = y + dy[i];
					if (ans_g.find({ nei_x, nei_y }) != ans_g.end()) continue;
					if (ans_m.find({ nei_x, nei_y }) != ans_m.end()) continue;
					check = true;
					to_add_g.insert({ nei_x, nei_y });
				}
				if (!check) {
					to_erase_g.insert({ x, y });
				}
			}
			for (auto& it : to_erase_g) {
				g.erase(it);
			}
			for (auto& it : to_add_g) {
				g.insert(it);
				ans_g.insert(it);
			}
		}
		if (t % 7 == 0) {
			set<pll> to_erase_m;
			set<pll> to_add_m;
			for (auto& it : m) {
				ll x = it.first, y = it.second;
				bool check = false;
				rep(i, 0, 4) {
					ll nei_x = x + dx[i];
					ll nei_y = y + dy[i];
					if (ans_g.find({ nei_x, nei_y }) != ans_g.end()) continue;
					if (ans_m.find({ nei_x, nei_y }) != ans_m.end()) continue;
					check = true;
					to_add_m.insert({ nei_x, nei_y });
				}
				if (!check) {
					to_erase_m.insert({ x, y });
				}
			}
			for (auto& it : to_erase_m) {
				m.erase(it);
			}
			for (auto& it : to_add_m) {
				m.insert(it);
				ans_m.insert(it);
			}
		}
	}
	cout << ans_m.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}