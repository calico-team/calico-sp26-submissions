#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	auto from = [&](vector<int>& a, vector<int>& b) -> int {
		return abs(b[1] - b[0]) + abs(b[2] - b[1]) + abs(a[1] - a[0]) + abs(a[2] - a[1]) + abs(b[0] - a[0]) + abs(b[1] - a[1]) + abs(b[2] - a[2]);
	};
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& i : a) cin >> i;
		vector<int> d = a;
		sort(d.begin(), d.end());
		d.erase(unique(d.begin(), d.end()), d.end());
		int mn = INT32_MAX;
		vector<int> h;
		vector<int> b;
		auto at = [&](auto&& self) -> void {
			if (h.size() == n) {
				if (from(a, h) < mn) {
					mn = from(a, h);
					b = h;
				}
				return;
			}
			for (int i : d) {
				h.push_back(i);
				self(self);
				h.pop_back();
			}
		};
		at(at);
		for (int i : b) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}

