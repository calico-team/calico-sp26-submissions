#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
const int mod = 1e9 + 7;
const long long INF = (long long)4e18;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
		int n;
		cin >> n;
		vector <int> v (n);
		vector <int> v2;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			v2.pb(v[i]);
		}
		sort(v2.begin(), v2.end());
		v2.erase(unique(v2.begin(), v2.end()), v2.end());
		vector <vector <pair <int, int>>> dp (n, vector <pair <int, int>> (v2.size(), {INF, -1}));
		for (int j = 0; j < v2.size(); j++) {
			dp[0][j] = {abs(v[0] - v2[j]), -1};
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < v2.size(); j++) {
				for (int k = 0; k < v2.size(); k++) {
					int cost = dp[i - 1][k].fi + abs(v2[j] - v2[k]) + abs(v[i] - v2[j]);
					if (cost < dp[i][j].fi) {
						dp[i][j] = {cost, k};
					}
				}
			}
		}
		int total = 1e18;
		int idx = -1;
		for (int j = 0; j < v2.size(); j++) {
			if (dp[n - 1][j].fi < total) {
				total = dp[n - 1][j].fi;
				idx = j;
			}
		}
		vector <int> v3 (n);
		for (int i = n - 1; i >= 0; i--) {
			v3[i] = v2[idx];
			idx = dp[i][idx].se;
		}
		for (int i = 0; i < n; i++) {
			cout << v3[i] << " ";
		}
		cout << endl;
	}
}
