// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	cout << c / ((a + b) * 2 * d) << "\n";
}

int main() {
	int T; cin >> T;
	while (T--) solve();
}
