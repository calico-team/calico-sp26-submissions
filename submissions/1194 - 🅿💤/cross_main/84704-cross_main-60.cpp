#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int offset[] = {0, 2, 4, 1, 3};
		for (int i = 0; i < n; i++) {
			int cur = offset[i % 5];
			for (int j = 0; j < m; j++) {
				cout << cur << " \n"[j == m-1];
				cur = (cur + 1) % 5;
			}
		}
	}
}