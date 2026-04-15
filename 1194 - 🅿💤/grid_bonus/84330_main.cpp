#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (auto &i : a) cin >> i;
		vector<ll> b = a;
		sort(b.begin(), b.end());
		ll med = b[n / 2];
		ll med2 = med;
		if (n % 2 == 0) med2 = (b[n/2-1] + b[n/2]) / 2;
		ll ans1 = 0, ans2 = 0, ans3 = 0;
		for (int i = 1; i < n; i++) {
			ans2 += abs(a[i] - a[i-1]);
		}
		for (int i = 0; i < n; i++) {
			ans1 += abs(a[i] - med);
			ans3 += abs(a[i] - med2);
		}
		ans1 += ans2;
		ans3 += ans2;
		ans2 *= 2;
		ll minimum = min({ans1, ans2, ans3});
		if (minimum == ans1) {
			for (int i = 0; i < n; i++) {
				cout << med << " \n"[i == n-1];
			}
		} else if (minimum == ans2) {
			for (int i = 0; i < n; i++) {
				cout << a[i] << " \n"[i == n-1];
			}
		} else {
			for (int i = 0; i < n; i++) {
				cout << med2 << " \n"[i == n-1];
			}
		}
	}
}