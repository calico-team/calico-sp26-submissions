	// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>
#include <set>
#include <deque>
#include <numeric>
#include <stack>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

void fast_io() {
	// freopen("", "r", stdin);
	// freopen("", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cout << setprecision(9);
}

#define int long long
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fi first
#define se second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const int N = 1e3 + 5;

int loc[N][N];

void solve() {
	int k, n, m, p, q; cin >> k >> n >> m >> p >> q;
	int X, Y;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++) loc[i][j] = -1;
	}
	for (int i = 1; i <= k; i++){
		int x, y; cin >> x >> y;
		if (i == 1){
			X = x, Y = y;
		}
		loc[x][y] = i - 1;
	}
	
	
	
	while (1){
		X += q;
		Y += p;
		X %= n;
		Y %= m;
		if (loc[X][Y] != -1){
			cout << loc[X][Y] << endl;;
			return;
		}
	}
	
	
}

signed main() {
	fast_io();
	srand(chrono::steady_clock::now().time_since_epoch().count());
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
