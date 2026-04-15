#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<long long, long long> sum (pair<long long, long long> a, pair<long long, long long> b) {
	return make_pair(a.first * b.second + b.first * a.second, a.second * b.second);
}

pair<long long, long long> dfs(int x, int y) {
	// cout << x << ' ' << y << endl;
	if (x < 0 || x >= n || y < 0 || y >= m) return make_pair(1LL, 1LL);

	if (grid[x][y] == 'X') return make_pair(0LL, 1LL);
	if (grid[x][y] == '^') return dfs(x - 1, y);
	if (grid[x][y] == 'v') return dfs(x + 1, y);
	if (grid[x][y] == '<') return dfs(x, y - 1);
	if (grid[x][y] == '>') return dfs(x, y + 1);

	int ways = 0;
	pair<long long, long long> total = make_pair(0LL, 1LL);
	for (int d = 0; d < 4; d++) {
		if (d == 0 && grid[x + 1][y] == '^') continue;
		if (d == 1 && grid[x - 1][y] == 'v') continue;
		if (d == 2 && grid[x][y + 1] == '<') continue;
		if (d == 3 && grid[x][y - 1] == '>') continue;
		if (grid[x + dx[d]][y + dy[d]] == '.') continue;

		total = sum(total, dfs(x + dx[d], y + dy[d]));
		ways++;
	}

	total.second *= ways;
	long long fac = gcd(total.first, total.second);
	return make_pair(total.first / fac, total.second / fac);
}

int main() {
	// ifstream cin("input");

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		grid.clear();
		grid.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> grid[i];
		}

		pair<long long, long long> ans = dfs(0, 0);
		long long fac = gcd(ans.first, ans.second);
		cout << ans.first / fac << ' ' << ans.second / fac << '\n';
	}
}