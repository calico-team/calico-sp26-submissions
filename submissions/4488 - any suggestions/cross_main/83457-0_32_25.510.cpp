#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pi pair<int, int>
#define pii pair<int, pi>
#define fi first
#define se second
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cout << (3 + i) % 5 << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= m; i++) {
		cout << (i) % 5 << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= m; i++) {
		cout << (2 + i) % 5 << ' ';
	}
	cout << '\n';
	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << ((i - 4) * 2 + j - 1) % 5 << ' ';
		}
		cout << '\n';
	}
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int tc1=1;tc1<=tc;tc1++){
		// cout << "Case #" << tc1 << ": ";
		solve();
	}
}
