// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve() {
	string a, b; cin >> a >> b;
	int p1 = 0;
	string c = "";
	for(int i = 0; i < b.size(); i++) {
		while (a[p1] != b[i]) {
			c += '#';
			p1++;
		}
		c += b[i];
		p1++;
	}
	cout << c << "\n";
}

int main() {
	int T; cin >> T;
	while (T--) solve();
}
