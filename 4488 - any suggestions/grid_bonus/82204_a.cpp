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

int n, a[200005], b[200005];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
	int s = 0, s2 = 0;
	for (int i = 1; i < n; i++) s += abs(a[i] - a[i + 1]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s2 += abs(a[(n + 1) / 2] - a[i]);
	if (s < s2) {
		for (int i = 1; i <= n; i++) cout << b[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) cout << a[(n + 1) / 2] << ' ';
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
