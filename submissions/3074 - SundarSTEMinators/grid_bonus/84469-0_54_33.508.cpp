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
	int n; cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << a[1] << ' ';
	int lst = a[1];
	for (int i = 2; i < n; i++){
	int A = lst;
	int b = a[i];
	int c = a[i + 1];
	vector<int> x = {A, b, c};
	sort(all(x));
	cout << x[1] << ' ';
	lst = x[1];
	}
	cout << a[n] << endl;
}

signed main() {
	fast_io();
	srand(chrono::steady_clock::now().time_since_epoch().count());
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
