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
	int a[n + 1];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int L[n + 1], R[n + 1];
	L[1] = R[1] = a[1];
	for (int i = 2; i <= n; i++){
		L[i] = L[i - 1];
		R[i] = R[i - 1];
		if (a[i] < L[i - 1]){
			L[i] = a[i];
		}
		else if (a[i] > R[i - 1]){
			R[i] = a[i];
		}
	}
	
	for (int i = n - 1; i >= 1; i--){
		if (a[i + 1] < L[i]) a[i] = L[i];
		else if (a[i + 1] > R[i]) a[i] = R[i];
		else a[i] = a[i + 1];
	}
	
	
	for (int i = 1; i <= n; i++){
		cout << a[i] << ' ';
	}
		cout << endl;
}

signed main() {
	fast_io();
	srand(chrono::steady_clock::now().time_since_epoch().count());
	int tc = 1;
	cin >> tc;
	while (tc--) solve();
	return 0;
}

