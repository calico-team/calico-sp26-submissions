#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
int p2[3005][3005], l[1005][1005], r[1005][1005];
ll p[3005][3005];

void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n * 2 + m; i++) {
		for (int j = 1; j <= n * 2 + m; j++) bg[i][j] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == '-') {
				int x = (i + j), y = (j - i);
				x += n; y += n;
				//cout << "ok " << x << ' ' << y << '\n';
				bg[x][y] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		l[i][0] = 0;
		for (int j = 1; j < m; j++) l[i][j] = l[i][j - 1] + (g[i][j - 1] == '#');
		r[i][m - 1] = 0;
		for (int j = m - 2; j >= 0; j--) r[i][j] = r[i][j + 1] + (g[i][j + 1] == '#');
		for (int j = 0; j < m; j++) l[i][j] = min(l[i][j], r[i][j]);
	}
	for (int i = 1; i <= n * 2 + m; i++) {
		for (int j = 1; j <= n * 2 + m; j++) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + bg[i][j];
		}
	}
	int lo = 0, hi = (n + m), ans = hi;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		bool f = 0;
		for (int i = 1; i <= n * 2 + m; i++) {
			for (int j = 1; j <= n * 2 + m; j++) {
				int x = min(i + mid, n * 2 + m), y = min(j + mid, n * 2 + m);
				if (pref[x][y] - pref[i - 1][y] - pref[x][j - 1] + pref[i - 1][j - 1] >= k) {
					//if (mid == 3) cout << mid << ' ' << i << ' ' << j << '\n';
					f = 1;
				}
			}
		}
		if (f) ans = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	
	
	lo = 0, hi = m;
	int grr = hi + 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		//only if its <= mid then consider it
		for (int i = 1; i <= n * 2 + m; i++) {
			for (int j = 1; j <= n * 2 + m; j++) bg[i][j] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == '-') {
					int x = (i + j), y = (j - i);
					x += n; y += n;
					//cout << "ok " << x << ' ' << y << '\n';
					if (l[i][j] <= mid) bg[x][y] = 1;
				}
			}
		}
		for (int i = 1; i <= n * 2 + m; i++) {
			for (int j = 1; j <= n * 2 + m; j++) {
				pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + bg[i][j];
			}
		}
		bool f = 0;
		for (int i = 1; i <= n * 2 + m; i++) {
			for (int j = 1; j <= n * 2 + m; j++) {
				int x = min(i + ans, n * 2 + m), y = min(j + ans, n * 2 + m);
				if (pref[x][y] - pref[i - 1][y] - pref[x][j - 1] + pref[i - 1][j - 1] >= k) {
					//if (mid == 3) cout << mid << ' ' << i << ' ' << j << '\n';
					f = 1;
				}
			}
		}
		if (f) grr = mid, hi = mid - 1;
		else lo = mid + 1;
	}
	
	pi mn = {2e9, grr};
	for (;grr <= m / 2; grr++) {
		for (int i = 0; i <= n * 2 + m; i++) {
			for (int j = 0; j <= n * 2 + m; j++) bg[i][j] = p2[i][j] = p[i][j] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == '-') {
					int x = (i + j), y = (j - i);
					x += n; y += n;
					//cout << "ok " << x << ' ' << y << '\n';
					if (l[i][j] < grr) {
						p2[x][y] = 1;
						p[x][y] = l[i][j];
					}
					if (l[i][j] <= grr) bg[x][y] = 1;
				}
			}
		}
		for (int i = 1; i <= n * 2 + m; i++) {
			for (int j = 1; j <= n * 2 + m; j++) {
				p2[i][j] += p2[i - 1][j] + p2[i][j - 1] - p2[i - 1][j - 1];
				p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
				pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + bg[i][j];
			}
		}
	
		for (int i = 1; i <= n * 2 + m; i++) {
			for (int j = 1; j <= n * 2 + m; j++) {
				int x = min(i + ans, n * 2 + m), y = min(j + ans, n * 2 + m);
				if (pref[x][y] - pref[i - 1][y] - pref[x][j - 1] + pref[i - 1][j - 1] >= k) {
					ll cnt = p2[x][y] - p2[i - 1][y] - p2[x][j - 1] + p2[i - 1][j - 1];
					ll sm = p[x][y] - p[i - 1][y] - p[x][j - 1] + p[i - 1][j - 1];
					mn = min(mn, {sm + 1ll * max(0ll, k - cnt) * grr, grr});
				}
			}
		}
	}
	//now consider grr - 1, build stuff
	
	grr = mn.se;
	assert(mn.fi != 2e18);
	for (int i = 0; i <= n * 2 + m; i++) {
		for (int j = 0; j <= n * 2 + m; j++) bg[i][j] = p2[i][j] = p[i][j] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '-') {
				int x = (i + j), y = (j - i);
				x += n; y += n;
					//cout << "ok " << x << ' ' << y << '\n';
				if (l[i][j] < grr) {
					p2[x][y] = 1;
					p[x][y] = l[i][j];
				}
				if (l[i][j] <= grr) bg[x][y] = 1;
			}
		}
	}
	for (int i = 1; i <= n * 2 + m; i++) {
		for (int j = 1; j <= n * 2 + m; j++) {
			p2[i][j] += p2[i - 1][j] + p2[i][j - 1] - p2[i - 1][j - 1];
			p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + bg[i][j];
		}
	}
	bool found = 0;
	for (int i = 1; i <= n * 2 + m; i++) {
		for (int j = 1; j <= n * 2 + m; j++) {
			int x = min(i + ans, n * 2 + m), y = min(j + ans, n * 2 + m);
			if (pref[x][y] - pref[i - 1][y] - pref[x][j - 1] + pref[i - 1][j - 1] >= k) {
				ll cnt = p2[x][y] - p2[i - 1][y] - p2[x][j - 1] + p2[i - 1][j - 1];
				ll sm = p[x][y] - p[i - 1][y] - p[x][j - 1] + p[i - 1][j - 1];
				if (mn.fi == sm + 1ll * max(0ll, k - cnt) * grr) {
					vector <pii> s;
					for (int a = i; a <= x; a++) {
						for (int b = j; b <= y; b++) {
							if (bg[a][b]) {
								int p = (a - b) / 2, q = (a + b) / 2 - n;
								s.push_back({l[p][q], {p, q}});
							}
						}
					}
					sort(s.begin(), s.end());
					for (int a = 0; a < k; a++) cout << s[a].se.fi << ' ' << s[a].se.se << '\n';
					found = 1;
					break;
				}
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
