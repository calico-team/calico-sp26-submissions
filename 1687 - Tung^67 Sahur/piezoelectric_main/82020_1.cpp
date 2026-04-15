#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int l, w, e, r;
		cin >> l >> w >> e >> r;
		int perim = 2 * (l + w);
		cout << (e + (perim * r - 1)) / (perim * r) << '\n';
	}
}
