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

int n, m, k;
char g[1005][1005];
int bg[3005][3005], pref[3005][3005];
const int o = 1000;

void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= o * 3; i++) {
		for (int j = 1; j <= o * 3; j++) bg[i][j] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == '-') {
				int x = (i + j), y = (j - i);
				x += o; y += o;
				//cout << "ok " << x << ' ' << y << '\n';
				bg[x][y] = 1;
			}
		}
	}
	for (int i = 1; i <= o * 3; i++) {
		for (int j = 1; j <= o * 3; j++) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + bg[i][j];
		}
	}
	int lo = 0, hi = (n + m) * 4, ans = hi;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		bool f = 0;
		for (int i = 1; i <= o * 3; i++) {
			for (int j = 1; j <= o * 3; j++) {
				int x = min(i + mid, o * 3), y = min(j + mid, o * 3);
				if (pref[x][y] - pref[i - 1][y] - pref[x][j - 1] + pref[i - 1][j - 1] >= k) {
					//if (mid == 3) cout << mid << ' ' << i << ' ' << j << '\n';
					f = 1;
				}
			}
		}
		if (f) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	//cout << ans << '\n';
	bool found = 0;
	for (int i = 1; i <= o * 3; i++) {
		for (int j = 1; j <= o * 3; j++) {
			int x = min(i + ans, o * 3), y = min(j + ans, o * 3);
			if (pref[x][y] - pref[i - 1][y] - pref[x][j - 1] + pref[i - 1][j - 1] >= k) {
				vector <pi> s;
				for (int a = i; a <= x; a++) {
					for (int b = j; b <= y; b++) {
						if (bg[a][b]) {
							s.push_back({(a - b) / 2, (a + b) / 2 - o});
						}
					}
				}
				for (int a = 0; a < k; a++) cout << s[a].fi << ' ' << s[a].se << '\n';
				
				found = 1;
				break;
			}
		}
		if (found) break;
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
