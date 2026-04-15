#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define rep(i, s, e) for (ll i = s; i < e; i++)
#define upmax(a, b) a = max(a, b)
#define upmin(a, b) a = min(a, b)

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;

vll dx = { 1, -1, 0, 0 };
vll dy = { 0, 0, 1, -1 };

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
		set<pll> to_erase_g;
		set<pll> to_add_g;
		set<pll> to_erase_m;
		set<pll> to_add_m;
		if (m.size() == 0) break;
		if (t % 2 == 0) {
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