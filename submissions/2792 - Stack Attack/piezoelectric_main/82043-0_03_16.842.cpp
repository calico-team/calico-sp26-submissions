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

void solve() {
	ll l, w;
	cin >> l >> w;
	ll p = l * 2 + w * 2;
	ll e, r;
	cin >> e >> r;
	ll num = p * r;
	cout << e / num << endl;
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