#include <bits/stdc++.h>
using namespace std;

int n, p, r, k;
vector<int> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> p >> r >> k;
		v.clear();
		v.reserve(n);

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		int j = 0;
		bool valid = true;
		for (auto x : v) {
			p -= x;

			if (p < 0) {
				cout << "nah i'd lose" << endl;
				valid = false;
				break;
			}

			if (++j == k) {
				p += r;
				j = 0;
			}
		}
		if (valid)
			cout << "nah i'd win" << endl;
	}

	return 0;
}
