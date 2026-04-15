#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#ifdef LOCAL
#define err cerr
#else
#define err if (0) cerr
#endif

void solve() {
	pair<int, int> g, m;
	cin >> g.f >> g.s >> m.f >> m.s;
#define pii pair<pair<int, bool>, pair<int, int>>
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({{0, 0}, g});
	pq.push({{0, 1}, m});
	int num = 1, ans = 0;
	set<pair<int, int>> been;
	while (num) {
		auto tp = pq.top();
		pq.pop();
		num -= tp.f.s;
		if (!been.count(tp.s)) {
			been.insert(tp.s);
			ans += tp.f.s;
			if (tp.f.s) {
				pq.push({{tp.f.f+7, 1}, {tp.s.f+1, tp.s.s}});
				pq.push({{tp.f.f+7, 1}, {tp.s.f, tp.s.s-1}});
				pq.push({{tp.f.f+7, 1}, {tp.s.f-1, tp.s.s}});
				pq.push({{tp.f.f+7, 1}, {tp.s.f, tp.s.s+1}});
				num += 4;
			} else {
				pq.push({{tp.f.f+2, 0}, {tp.s.f+1, tp.s.s}});
				pq.push({{tp.f.f+2, 0}, {tp.s.f, tp.s.s-1}});
				pq.push({{tp.f.f+2, 0}, {tp.s.f-1, tp.s.s}});
				pq.push({{tp.f.f+2, 0}, {tp.s.f, tp.s.s+1}});
			}
		}
	}
	cout << ans << "\n";
}

	signed main (signed argc, char **argv) {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		int t;
		cin >> t;
		while (t--) solve();
	}

	/*
	 *
	 *  ┏┓   ┏┓+ +
	 * ┏┛┻━━━┛┻┓ + +
	 * ┃   ━   ┃ ++ + + +
	 * ████━████+
	 * ◥██◤ ◥██◤ +
	 * ┃   ┻   ┃ 
	 * ┗━┓   ┏━┛  + + 
	 *   ┃   ┃ + + + +Code is far away from  
	 *   ┃   ┃ + bug with the llama protecting
	 *   ┃    ┗━━━┓ 神兽保佑,代码无bug 
	 *   ┃        ┣┓
	 *   ┃        ┏┛
	 *   ┗┓┓┏━┳┓┏┛ + + + +
	 *    ┃┫┫ ┃┫┫
	 *    ┗┻┛ ┗┻┛+ + + +
	 */

	//thanks cindy

