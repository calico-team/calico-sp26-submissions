#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll xg, yg, xm, ym;
    if (!(cin >> xg >> yg >> xm >> ym)) return;
    ll d = abs(xg - xm) + abs(yg - ym);
    ll r = (2 * d - 1) / 9;
    ll ans = 2 * r * r + 2 * r + 1;
    cout << ans << endl;
}
int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
}
