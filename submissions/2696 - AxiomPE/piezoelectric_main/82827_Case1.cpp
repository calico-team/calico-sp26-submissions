#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	if (!(cin >> T)) return 0;

	while (T--){
		long long l, w, e, r;
		cin >> l >> w >> e >> r;

		long long peri = 2 * (l + w);
		long long elec_ = peri * r;
		long long vuel = e / elec_;

		cout << vuel << "\n";
	}

	return 0;
}