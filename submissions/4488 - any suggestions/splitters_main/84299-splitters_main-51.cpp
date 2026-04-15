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

inline pi add_f (pi a, pi b) {
	int dn = a.se * b.se / __gcd(a.se, b.se);
	int t = a.fi * dn / a.se + b.fi * dn / b.se;
	int r = __gcd(t, dn);
	t /= r; dn /= r;
	return {t, dn};
}

int n, m;
pair <int, int> dp[20][20];
char g[20][20];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char cc[] = {'v', '<', '^', '>'};

pi f(int x, int y) {
	//cerr << x << ' ' << y << '\n';
	if (x < 1 || x > n || y < 1 || y > m) return {1, 1};
	if (dp[x][y].fi != -1) return dp[x][y];
	if (g[x][y] == 'X') return {0, 1};
	if (g[x][y] == 'S') {
		dp[x][y] = {0, 1};
		int c = 0;
		for (int i = 0; i < 4; i++) {
			int x1 = x + dx[i], y1 = y + dy[i];
			if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && (g[x1][y1] == cc[i] || g[x1][y1] == '.')) continue;
			c++;
		}
		//cerr << x << ' ' << y << ' ' << c << '\n';
		for (int i = 0; i < 4; i++) {
			int x1 = x + dx[i], y1 = y + dy[i];
			if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && (g[x1][y1] == cc[i] || g[x1][y1] == '.')) continue;
			dp[x][y] = add_f(dp[x][y], f(x1, y1));
		}
		dp[x][y].se *= c;
		int r = __gcd(dp[x][y].fi, dp[x][y].se);
		dp[x][y].fi /= r;
		dp[x][y].se /= r;
		return dp[x][y];
	}
	if (g[x][y] == '^') return dp[x][y] = f(x - 1, y);
	if (g[x][y] == '<') return dp[x][y] = f(x, y - 1);
	if (g[x][y] == '>') return dp[x][y] = f(x, y + 1);
	if (g[x][y] == 'v') return dp[x][y] = f(x + 1, y);
	assert(0);
	return {0, 1};
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = {-1, -1};
			cin >> g[i][j];
		}
	}
	pi res = f(1, 1);
	cout << res.fi << ' ' << res.se << '\n';
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
