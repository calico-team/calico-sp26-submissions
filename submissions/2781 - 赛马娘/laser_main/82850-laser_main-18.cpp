#include <bits/stdc++.h>
using namespace std;

int solve(int k, int n, int m, int p, int q) {
    vector<pair<int,int>> a (k);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    int x = a[0].first;
    int y = a[0].second;

    while (true) {
        // cout << x << " " << y << "\n";
        x = (x + q) % n;
        y = (y + p) % m;
        for (int j = 0; j < k; j++) {
            if (x == a[j].first && y == a[j].second) {
                return j;
            }
        }
    }
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
	    cout << solve(k, n, m, p, q) << "\n";
	}
}
