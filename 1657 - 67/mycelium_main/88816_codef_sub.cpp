#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
void solve() {
    ll xg, yg, xm, ym;
    if (!(cin >> xg >> yg >> xm >> ym)) return;
    ll dy = abs(yg - ym);
    ll dx = abs(xg - xm);
    ll d = dx + dy;
    ll r = (2 * (dx+dy) - 1) / 5;
    ll ans = (r + 1) * (r + 1) + r * r;
    cout << ans << endl;
}
int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
}