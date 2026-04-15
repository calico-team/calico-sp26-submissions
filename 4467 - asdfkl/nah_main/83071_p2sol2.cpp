#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

void solve() {
    int n, p, r, k;
    cin >> n >> p >> r >> k;
    vi v(n);
    for (auto&i:v) cin >> i;

    bool fail = false;
    for (int i=0; i<n; i++) {
        p -= v[i];
        if (p < 0) {
            fail = true;
            break;
        }
        if ((i+1) % k == 0) {
            p += r;
        }
    }
    if (fail) cout << "nah i'd lose" << endl;
    else cout << "nah i'd win" << endl;
}

int32_t main() {
	int t;
    cin >> t;
    while (t--) solve();
}
