#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int T;
	if(!(cin >> T)) return 0;

	while (T--){
		ll k, n, m, p, q;
		cin >> k >> n >> m >> p >> q;

		vector<pair<ll, ll>> aeste(k);
		for (int i = 0; i < k; i++){
			cin >> aeste[i].first >> aeste[i].second;
		}

		ll x0 = aeste[0].first;
		ll y0 = aeste[0].second;

		ll min_ = -1;
		int index_h = 0;

		for (int i = 0; i < k; i++){
			ll xi = aeste[i].first;
			ll yi = aeste[i].second;

			ll dx = (xi - x0 % n + n) % n;
			ll dy = (yi - y0 % m + m) % m;

			for (ll s = (i == 0 ? 1 : 0); s < 2000; s++){
				if ((x0 + s * q) % n == xi && (y0 + s * p) % m == yi){
					if (s > 0 || (i > 0 && s == 0)) {
						if (min_ == -1 || s < min_){
							min_ = s;
							index_h = i;
						}
						break;
					}
				}
			}
		}
		cout << index_h << "\n";
	}

	return 0;
}