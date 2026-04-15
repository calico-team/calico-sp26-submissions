#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int solve() {
	ll L, W, E, R;
	cin >> L >> W >> E >> R;
	ll P = (L + W) * 2;
	ll ASDF = P * R;
	cout << ((E + ASDF - 1 )) / ASDF << '\n';
	return 0;
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	ll Q;
	cin >> Q;
	while (Q--) {
		solve();
	}
	
	return 0;
}