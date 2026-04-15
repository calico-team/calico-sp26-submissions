#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	auto from = [&](vector<ll>& a, vector<ll>& b) -> ll {
		ll res = 0;
		for (int i = 0; i + 1 < a.size(); ++i) {
			res += abs(a[i + 1] - a[i]);
			res += abs(b[i + 1] - b[i]);
		}
		for (int i = 0; i < a.size(); ++i) {
			res += abs(a[i] - b[i]);
		}
		return res;
	};
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n);
		for (ll& i : a) cin >> i;
		vector<ll> d = a;
		sort(d.begin(), d.end());
		d.erase(unique(d.begin(), d.end()), d.end());
		ll mn = INT32_MAX;
		vector<ll> h;
		vector<ll> b;
		auto at = [&](auto&& self) -> void {
			if (h.size() == n) {
				if (from(a, h) < mn) {
					mn = from(a, h);
					b = h;
				}
				return;
			}
			for (ll i : d) {
				h.push_back(i);
				self(self);
				h.pop_back();
			}
		};
		at(at);
		for (ll i : b) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}

