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
	ll n;
	cin >> n;
	vll arr(n);
	rep(i, 0, n) cin >> arr[i];
	vll ans(n + 2);
	ans[0] = -1;
	ans[n + 1] = -1;
	rep(i, 1, n + 1) {
		ans[i] = arr[i - 1];
	}
	rep(i, 1, n + 1) {
		if (ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) {
			ans[i] = max(ans[i - 1], ans[i + 1]);
		}
	}
	rep(i, 1, n + 1) {
		cout << ans[i] << ' ';
	}
	cout << endl;
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