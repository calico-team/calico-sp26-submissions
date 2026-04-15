
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;


void solve() {
    int l, w, e, r; cin >> l >> w >> e >> r;

    int each = 2 * (l + w) * r;
    cout << e / each << "\n";
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();


    return 0;

}