#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, p, r, k; cin >> n >> p >> r >> k;
	vector<int> E(n);
	
	for (auto &x : E) cin >> x;
	
	int cooldown = 0;
	for (int i = 0; i < n; ++i) {
		if (cooldown == k){
			p+=r;
			cooldown = 0;
		}
		p -= E[i];
		cooldown++;
		if (p < 0) break;
		//cout << p << "\n";
	}
	
	if (p >= 0) {
		cout << "nah i'd win\n";
	} else {
		cout << "nah i'd lose\n";
	}
	
}
int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}

