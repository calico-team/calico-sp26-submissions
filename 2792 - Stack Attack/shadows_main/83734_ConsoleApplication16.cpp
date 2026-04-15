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
	ll n;
	cin >> n;
	vvll s1(n, vll(n)), s2(n, vll(n));
	vvll got(n), got1(n);
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (ll j = 0; j < n; j++) {
			if (s[j] == '#') {
				s1[i][j] = 1;
				got[i].push_back(j);
				got1[i].push_back(j);
			}
			else {
				s1[i][j] = 0;
			}
		}
	}
	ll min_val = 0, max_val = 0;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (ll j = 0; j < n; j++) {
			if (s[j] == '#') {
				s2[i][j] = 1;
			}
			else {
				s2[i][j] = 0;
			}
		}
	}
	for (ll j = 0; j < n; j++) {
		for (ll i = 0; i < n; i++) {
			if (s2[i][j]) {
				if (got[i].empty()) { min_val++; continue; }
				got[i].pop_back();
				min_val++;
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		min_val += got[i].size();
	}
	vll vis(n);
	for (ll j = 0; j < n; j++) {
		for (ll i = 0; i < n; i++) {
			if (s2[i][j]) {
				vis[i] = true;
				max_val += got1[i].size();
			}
		}
	}
	cout << max_val << " " << min_val << '\n';

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