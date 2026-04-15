#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll simplify(pll frac) {
	ll g = gcd(frac.first, frac.second);
	if (g != 1)
		return make_pair(frac.first / g, frac.second / g);
	return frac;
}
pll operator+(pll a, pll b) {
	ll denom = lcm(a.second, b.second);
	return simplify(make_pair(a.first * b.second + b.first * a.second, denom));
}
pll operator-(pll a) {
	return make_pair(-a.first, a.second);
}
pll operator-(pll a, pll b) {
	return a + (-b);
}
pll operator*(pll a, ll x) {
	return simplify(make_pair(a.first * x, a.second));
}
pll operator*(pll a, pll b) {
	return simplify(make_pair(a.first * b.first, a.second * b.second));
}
ostream& operator<<(ostream& out, const pll& x) {
	return out << x.first << ',' << x.second;
}
bool operator<(pll a, pll b) {
	return a.first * b.second < a.second * b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int k;
		ll n, m, p, q;
		cin >> k >> n >> m >> p >> q;
		pll slope = make_pair(p, q);
		pll recip = make_pair(q, p);

		function<pll(pll)> getYInt = [&](pll pos) {
			return slope * (-pos.first) + make_pair(pos.second, 1);
		};

		vector<pll> arr(k);
		map<pll, vector<int>> asteroidLines;
		for (int i = 0; i < k; i++) {
			cin >> arr[i].first >> arr[i].second;
			pll yInt = getYInt(arr[i]);
			asteroidLines[yInt].push_back(i);
		}
		for (auto& [k, v] : asteroidLines) {
			sort(v.begin(), v.end(), [&](int a, int b) {
				return arr[a] < arr[b];
			});
		}
		vector<int> belowFirst;
		auto& firstVec = asteroidLines[getYInt(arr[0])];
		size_t index = 0;
		while (index < firstVec.size() && arr[firstVec[index]].first <= arr[0].first) {
			belowFirst.push_back(firstVec[index++]);
		}
		firstVec.erase(firstVec.begin(), firstVec.begin() + index);

		set<pll> seen;
		pll yInt = getYInt(arr[0]);
		bool found = false;
		while (!seen.count(yInt)) {
			seen.insert(yInt);
			auto it = asteroidLines.find(yInt);
			if (it != asteroidLines.end() && it->second.size()) {
				found = true;
				cout << it->second.front() << '\n';
				break;
			}

			pll xVal {n, 1};
			pll xYLimit = (make_pair(m, 1LL) - yInt) * recip;
			if (xYLimit < xVal) {
				// bounded by Y
				yInt = -slope * xYLimit;
			}
			else {
				// bounded by X
				yInt = slope * n + yInt;
				if (yInt == pll{m, 1})
					yInt = pll{0, 1};
			}
		}

		if (!found) {
			cout << firstVec[0] << '\n';
		}
	}
}
