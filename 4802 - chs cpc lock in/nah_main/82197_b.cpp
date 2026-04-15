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
    int n, p, r, k; cin >> n >> p >> r >> k;
    vi e(n);
    for (auto& x : e) cin >> x; 

    for (int i = 0; i < n; i++) {
        if (i != 0 and i % k == 0) p += r;

        p -= e[i];
        if (p < 0) {
            cout << "nah i'd lose" << '\n';
            return;
        }
    }

    cout << "nah i'd win" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

