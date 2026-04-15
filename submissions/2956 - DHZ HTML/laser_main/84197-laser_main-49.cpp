#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
        int K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;
        vector<pair<int,int>> a(K);
        for (int i = 0; i < K; i++) cin >> a[i].first >> a[i].second;
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < K; i++) {
                mp[i] = {a[i].first, a[i].second};
        }
        int x = a[0].first, y = a[0].second;
        int mx = 1000000;
	int ans = 0;
	bool ok = true;
        while (mx--) {
                x = (x + Q) % N;
                y = (y + P) % M;
		for(int i = 0; i < K; i++) {
			if (x == a[i].first && y == a[i].second) {
				ans = i;
				ok = false;
				break;
			}
		}
		if (!ok) break;
        }
	cout << ans << "\n";
}

int32_t main() {
        int T; cin >> T;
        while (T--) solve();
}
