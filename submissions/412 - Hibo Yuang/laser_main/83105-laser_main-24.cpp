#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 1e18;
const ll MOD = 1e9 + 7;
bool testcases = true;

void solve() {
    ll k, n, m, p, q;
    cin >> k >> n >> m >> q >> p;
    vector<int> assx(k), assy(k);
    for (int i = 0; i < k; i++) cin >> assx[i] >> assy[i];
    ll curx = assx[0], cury = assy[0];
    while (true) {
        curx += p, cury += q;
        curx %= n; cury %= m;
        for (int i = 0; i < k; i++) {
            if (assx[i] == curx && assy[i] == cury) {
                cout << i << endl;
                return;
            }
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve();
    return 0;
}