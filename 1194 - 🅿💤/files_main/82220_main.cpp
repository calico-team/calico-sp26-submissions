#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		string s, t;
		cin >> s >> t;
		string ans = "";
		int i = 0;
		for (char c : t) {
			while (s[i] != c) {
				i++;
				ans += '#';
			}
			ans += c;
			i++;
		}
		while (i < s.size()) {
			ans += '#';
			i++;
		}
		cout << ans << '\n';
	}
}