#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
	ll xg, yg, xm, ym;
	cin >> xg >> yg >> xm >> ym;

	ll dx = xg - xm;
	ll dy = yg - ym;

	ll ug = dx + dy;
	ll vg = dx - dy;

	ll mycel_ = 0;

	ll D = max(abs(ug), abs(vg));
	ll max_r = (2 * D)/5 + 1;

	for (ll u = -max_r; u <= max_r; u++){
		for (ll v = -max_r; v <= max_r; v++){
			if ((u % 2 != 0 && v% 2 == 0) || (u % 2 == 0 && v % 2 != 0)){
				continue;
			}

			ll dist_M = max(abs(u), abs(v));
			ll dist_G = max(abs(u-ug), abs(v-vg));

			ll time_M = 7 * dist_M;
			ll time_G = 2 * dist_G;

			if (time_M < time_G){
				mycel_++;
			}
		}
	}

	cout << mycel_ << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	if (cin>> T){
		while (T--){
			solve();
		}
	}
	return 0;
}