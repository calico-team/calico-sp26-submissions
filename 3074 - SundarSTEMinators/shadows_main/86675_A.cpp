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


void solve() {
	int n; cin >> n;
	int a[n + 1] = {};
	int v1 = 0, v2 = 0;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		for (auto j : s) a[i] += (j == '#');
	}
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		int b = 0;
		for (auto j : s) b += (j == '#');
		v1 += max(a[i], b);
		v2 += a[i] * b;
	}
	cout << v2 << ' ' << v1 << endl;
}

signed main() {
	fast_io();
	srand(chrono::steady_clock::now().time_since_epoch().count());
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
	return 0;
}

