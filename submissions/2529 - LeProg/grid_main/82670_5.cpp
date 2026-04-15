#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& i : a) cin >> i;
		if (n == 1) {
			cout << a[0] << '\n';
		} else if (n == 2) {
			cout << a[0] << ' ' << a[0] << '\n';
		} else {
			cout << a[1] << ' ' << a[1] << ' ' << a[1] << '\n';
		}
	}
	return 0;
}

