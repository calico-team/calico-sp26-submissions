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

ll gcd(ll a, ll b) {
	if (a > b) { swap(a, b); }
	if (a == 0) { return b; }
	if (a == 1) { return 1; }
	return gcd(b % a, a);
}

void solve() {
	ll k, n, m, p, q;
	cin >> k >> n >> m >> p >> q;
	vpll points(k);
	for (ll i = 0; i < k; i++) {
		cin >> points[i].first >> points[i].second;
	}
	for (ll i = k - 1; i >= 0; i--) {
		points[i].first -= points[0].first - n;
		points[i].second -= points[0].second - m;
		points[i].first %= n;
		points[i].second %= m;
	}
	vpll x, y;
	vll vis(n);
	ll now = 0;
	while (!vis[now]) {
		x.push_back({ now, x.size() });
		vis[now] = true;
		now += q;
		now %= n;
	}

	now = 0;
	vis.clear();
	vis.resize(m);
	while (!vis[now]) {
		y.push_back({ now, y.size() });
		vis[now] = true;
		now += p;
		now %= m;
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	ll g = gcd((ll)x.size(), (ll)y.size());
	ll k1 = (ll)x.size() / g;
	ll k2 = (ll)y.size() / g;
	vll s(k2);
	now = 0;
	ll ind = 0;
	vis.clear();
	vis.resize(k2);
	while (!vis[now]) {
		vis[now] = true;
		if (now < k1) {
			s[now] = ind;
		}
		ind++;
		now += k1;
		now %= k2;
	}

	ll min_t = k1*k2*g, min_ind = 0;
	for (ll i = 1; i < k; i++) {
		pll tmp = { points[i].first, -1 };
		auto it = lower_bound(x.begin(), x.end(), tmp);
		tmp = { points[i].second, -1 };
		auto it1 = lower_bound(y.begin(), y.end(), tmp);
		if (it == x.end() || (*it).first != points[i].first) {
			continue;
		}
		if (it1 == y.end() || (*it1).first != points[i].second) {
			continue;
		}
		if ((*it1).second % g != (*it).second % g) { continue; }
		ll y1 = (*it).second / g;
		ll y2 = (*it1).second / g;
		ll sh = (y2 - y1);
		sh %= k2;
		sh += k2;
		sh %= k2;
		ll t_now = s[sh] * k1 * g;
		t_now += y2  * g;
		t_now += (*it1).second % g;
		if (t_now < min_t) {
			min_ind = i;
			min_t = t_now;
		}

	}
	cout << min_ind << '\n';


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