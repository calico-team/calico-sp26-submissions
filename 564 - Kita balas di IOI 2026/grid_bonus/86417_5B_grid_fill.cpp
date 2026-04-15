#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		
		cout << v[n / 2] << " ";
	}
}

