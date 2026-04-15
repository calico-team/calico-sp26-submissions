#include <bits/stdc++.h>
using namespace std;

#define pr pair<int, int>

void solve()
{
	int k, m, n, p, q;
	cin >> k >> n >> m >> p >> q;
	set<pr> coords;
	vector<pr> vals;
	for (int i = 0; i < k; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		coords.insert({c1, c2});
		vals.push_back({c1, c2});
	}
	int st1 = vals[0].first;
	int st2 = vals[0].second;
	int counter = 0;
	while (true) {
		pr curr = {st1, st2};
		if (coords.find(curr) != coords.end() && counter != 0) {
			break;
		}
		else {
			st1 += q;
			st1 = st1 % n;
			st2 += p;
			st2 = st2 % m;
			counter++;
		}
	}
	for (int i = 0; i < k; i++) {
		if (vals[i].first == st1 && vals[i].second == st2) {
			cout << i << '\n';
			return;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}