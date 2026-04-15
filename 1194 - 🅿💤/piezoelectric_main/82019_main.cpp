#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int l, w, e, r;
		cin >> l >> w >> e >> r;
		int steps = e / r + (e % r != 0);
		int perim = 2 * (l + w);
		int ans = steps / perim + (steps % perim != 0);
		cout << ans << '\n';
	}
}