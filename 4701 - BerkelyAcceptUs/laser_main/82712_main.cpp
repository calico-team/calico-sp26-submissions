
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;


void solve() {
    int k, n, m, p, q; cin >> k >> n >> m >> p >> q;
    // vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> indices(n, vector<int>(m, -1));

    vector<vector<int>> arr;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
        indices[a][b] = i;
    }

    int x = arr[0][0];
    int y = arr[0][1];

    while (true) {
        x = (x + q) % n;
        y = (y + p) % m;

        if (indices[x][y] != -1) {
            cout << indices[x][y] << "\n";
            return;
        }
    }


}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();


    return 0;

}