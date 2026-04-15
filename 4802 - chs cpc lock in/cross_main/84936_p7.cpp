#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using ll = long long;
using str = string;
using pi = pair<int,int>;
using vb = vector<bool>;

#define sz(x) int(size(x))
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
const int MOD = 1000000000;
const int INF = 1e18;


void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> grd(n, vector<int> (m));

    int st = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grd[i][j] = (st + j) % 5;
        }
        st -= 2;
        if (st < 0) st = 5 + st;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grd[i][j] << " ";
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

