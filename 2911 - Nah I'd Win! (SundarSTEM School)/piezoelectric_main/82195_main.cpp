#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define ll long long



void solve() {
    ll l, w, e, r; cin >> l >> w >> e >> r;
    cout << e / (2 * (l + w) * r) << endl; 
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) solve();
    return 0;
}
