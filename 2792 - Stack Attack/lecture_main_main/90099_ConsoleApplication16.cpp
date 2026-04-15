#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<string>
#include<math.h>
#include<iomanip>
#include<deque>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll >;
using vvpll = vector<vpll>;

vpll points;
ll n, m, k, p;

void calc(ll d, vll& c) {
	ll sz = 2 * (n + m);
	vector<vector<pair<pll, ll>>> op(sz);
	for (ll i = 0; i < p; i++) {
		pll x = { max(points[i].first - d, ll(0)), min(points[i].first + d, ll(sz - 1)) };
		pll y = { max(points[i].second - d, ll(0)), min(points[i].second + d, sz - 1) };
		op[x.first].push_back({y, 1});
		op[x.second].push_back({ y, -1 });
	}
	vll add(sz), rem(sz);
	ll ind = 0;
	for (ll i = 0; i < sz; i++) {
		if (ind == p) { break; }
		for (auto j : op[i]) {
			if (j.second == 1) {
				add[j.first.first]++;
				rem[j.first.second]--;
			}
		}
		ll s = 0;
		for (ll j = 0; j < sz; j++) {
			if (ind == p || points[ind].first != i) { break; }
			s += add[j];
			if (ind < p && points[ind].second == j) {
				c[ind] = s;
				ind++;
			}
			s += rem[j];
		}

		for (auto j : op[i]) {
			if (j.second == -1) {
				add[j.first.first]--;
				rem[j.first.second]++;
			}
		}
	}
}

void trans(ll ind) {
	ll x = points[ind].first, y = points[ind].second;
	ll x1 = (x + y - m) / 2;
	ll y1 = (x - y + m) / 2;
	cout << x1 << " " << y1 << '\n';
}


void solve() {
	cin >> n >> m >> k;
	points.clear();
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (ll j = 0; j < m; j++) {
			if (s[j] == '-') {
				points.push_back({ i + j, i - j + m });
			}
		}
	}
	p = points.size();
	
	sort(points.begin(), points.end());
	ll start = 0, end = n + m;
	ll dis = n + m;
	while (start <= end) {
		ll mi = (start + end) / 2;
		ll mid = mi / 2;
		vll c(p);
		calc(mid, c);
		if (mi % 2 == 1) {
			vll tmp(p);
			calc(mid + 1, tmp);
			for (ll i = 0; i < p; i++) {
				if (tmp[i] > c[i]) {
					c[i]++;
				}
			}
		}
		ll max_val = *max_element(c.begin(), c.end());
		if (max_val >= k) {
			end = mi - 1;
			dis = mi;
		}
		else {
			start = mi + 1;
		}
	}
	vll sol(p);
	calc(dis /2 , sol);
	if (dis % 2 == 1) {
		vll tmp1(p);
		calc(dis/2 + 1, tmp1);
		for (ll i = 0; i < p; i++) {
			if (tmp1[i] > sol[i]) {
				sol[i]++;
			}
		}
	}

	ll max_ind = -1;
	for (ll i = 0; i < p; i++) {
		if (sol[i] >= k) {
			max_ind = i;
		}
	}
	ll have = (dis % 2);
	ll take = 0;
	for (ll i = 0; i < p; i++) {
		if (take == k) { break; }
		ll distance = max(abs(points[i].first - points[max_ind].first), abs(points[i].second - points[max_ind].second));
		if (distance <= dis / 2) {
			take++;
			trans(i);
		}
		else if (distance <= (dis / 2) + have) {
			have = 0;
			take++;
			trans(i);
		}
	}
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

/*1
5 5 3
--###
####-
###-#
##-##
##-##*/