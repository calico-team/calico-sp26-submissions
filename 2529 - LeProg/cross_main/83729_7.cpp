#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> order = {0, 2, 4, 1, 3};
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << (order[i % 5] + j) % 5 << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}

