#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct frac {
	ll num, den;
	frac() : num(0), den(1) {}
	frac(ll num, ll den) {
		if (num == 0 && den == 0) {
			this->num = 0;
			this->den = 0;
			return;
		}
		ll g = gcd(num, den);
		this->num = num / g;
		this->den = den / g;
	}
	frac operator+(const frac &other) const {
		return frac(num * other.den + other.num * den, den * other.den);
	}
	bool operator<(const frac &other) const {
		return num * other.den < other.num * den;
	}
	bool valid() const {
		return den != 0;
	}
};

frac dp[20][20];
vector<string> grid;

char get(int x, int y) {
	if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return '.';
	return grid[x][y];
}

frac dfs(int x, int y) {
	if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return frac(1, 1);
	if (dp[x][y].valid()) return dp[x][y];
	if (grid[x][y] == 'v') return dp[x][y] = dfs(x+1, y);
	if (grid[x][y] == '>') return dp[x][y] = dfs(x, y+1);
	if (grid[x][y] == '^') return dp[x][y] = dfs(x-1, y);
	if (grid[x][y] == '<') return dp[x][y] = dfs(x, y-1);
	if (grid[x][y] == 'X') return dp[x][y] = frac(0, 1);
	// must be S = split
	int valid[4] = {};
	valid[0] = get(x+1, y) != '.' && get(x+1, y) != '^';
	valid[1] = get(x, y+1) != '.' && get(x, y+1) != '<';
	valid[2] = get(x-1, y) != '.' && get(x-1, y) != 'v';
	valid[3] = get(x, y-1) != '.' && get(x, y-1) != '>';
	int tot = valid[0] + valid[1] + valid[2] + valid[3]; // num split
	if (tot == 0) return dp[x][y] = frac(0, 1);
	frac ans = frac(0, 1);
	if (valid[0]) ans = ans + dfs(x+1, y);
	if (valid[1]) ans = ans + dfs(x, y+1);
	if (valid[2]) ans = ans + dfs(x-1, y);
	if (valid[3]) ans = ans + dfs(x, y-1);
	return dp[x][y] = frac(ans.num, ans.den * tot);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		grid.resize(n);
		for (auto &i : grid) cin >> i;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dp[i][j] = frac(0, 0);
		frac ans = dfs(0, 0);
		cout << ans.num << ' ' << ans.den << '\n';
	}
}