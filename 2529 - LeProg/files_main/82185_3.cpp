#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		string a, b; cin >> a >> b;
		int idx = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (idx < b.size() && a[i] == b[idx]) {
				++idx;
			} else {
				a[i] = '#';
			}
		}
		cout << a << '\n';
	}
	return 0;
}

