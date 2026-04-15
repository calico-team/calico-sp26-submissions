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


void solve() {
	ll n, m;
	cin >> n >> m;
	vll v = { 3 ,1, 2, 4, 0 };
	ll p = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cout << v[(p + j) % 5] << " ";
		}cout << '\n';
		p += 3;
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