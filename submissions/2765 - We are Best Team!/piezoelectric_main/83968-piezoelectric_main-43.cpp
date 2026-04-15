#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    ll l, w, e, r;
    if (cin >> l >> w >> e >> r) {
        ll p = 2 * (l + w);
        ll energy_per_lap = p * r;
        ll lap = e / energy_per_lap;
        cout << lap << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}