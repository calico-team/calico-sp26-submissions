#include <bits/stdc++.h>
#define int long long
#define vvi vector<vector<int>>
using namespace std;

void solve() {
    int l, w, e, r;
    cin >> l >> w >> e >> r;
    int p = 2*(l+w);
    cout << e/(p*r) << endl;
}

int32_t main() {
	int t;
    cin >> t;
    while (t--) solve();
}
