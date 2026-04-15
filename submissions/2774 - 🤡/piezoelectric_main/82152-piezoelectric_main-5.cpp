#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll l, w, e, r; cin >> l >> w >> e >> r;
    ll p = 2 * (l + w);
    cout << ceil((long double) e / p / r) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}

