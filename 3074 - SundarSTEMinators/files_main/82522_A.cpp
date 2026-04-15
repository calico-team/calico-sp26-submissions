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
	string s, t; cin >> s >> t;
	int n = s.size();
	for (int l = 0, r = 0; l < n; l++){
		if (s[l] == t[r]){
			r++;
		}
		else {
			s[l] = '#';
		}
	}
	cout << s << endl;
}

signed main() {
	fast_io();
	srand(chrono::steady_clock::now().time_since_epoch().count());
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
	return 0;
}
