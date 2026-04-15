#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i : a) cin >> i;
		vector<int> b = a;
		sort(b.begin(), b.end());
		int med = b[n / 2];
		for (int i = 0; i < n; i++) cout << med << " \n"[i == n - 1];
	}
}