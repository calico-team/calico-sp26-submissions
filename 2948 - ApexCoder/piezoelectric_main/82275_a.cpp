#include <bits/stdc++.h>


void solve() {
	int l,w,e,r;
	std::cin >> l >> w >> e >> r;
	std::cout << e/((2* l + 2 * w)*r) << std::endl;
}

int main() {
	int t;std::cin >> t;
	while(t--) {
		solve();
	}
}