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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << (2 * i + j) % 5 << " ";
		}
		cout << '\n';
	}
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