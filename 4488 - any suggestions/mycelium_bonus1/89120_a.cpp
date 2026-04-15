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

int a, b, c, d;
const int o = 400;
int vis[2005][2005];
using t4 = tuple <int, int, int, int>;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void solve(){
	cin >> a >> b >> c >> d;
	a += o; b += o; c += o; d += o;
	priority_queue <t4, vector <t4>, greater <t4> > pq;
	for (int i = 1; i <= 2 * o; i++) for (int j = 1; j <= 2 * o; j++) vis[i][j] = 0;
	pq.push({0, 1, a, b});
	pq.push({0, 2, c, d});
	int cnt = 1;
	while (cnt && !pq.empty()) {
		int w, x, y, z;
		tie (w, x, y, z) = pq.top();
		pq.pop();
		cnt -= (x == 2);
		if (vis[y][z]) continue;
		vis[y][z] = x;
		for (int i = 0; i < 4; i++) {
			int x1 = y + dx[i], y1 = z + dy[i];
			if (x1 < 1 || x1 > 2 * o || y1 < 1 || y1 > 2 * o) continue;
			pq.push({w + (x == 1 ? 2 : 7), x, x1, y1});
			cnt += (x == 2);
		}
	}
	int ans = 0;
	for (int i = 1; i <= 2 * o; i++) {
		for (int j = 1; j <= 2 * o; j++) ans += (vis[i][j] == 2);
	}
	cout << ans << '\n';
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
