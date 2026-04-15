#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

void solve() {
    ll xg, yg, xm, ym;
    if (!(cin >> xg >> yg >> xm >> ym)) return;

    ll dx = abs(xg - xm);
    ll dy = abs(yg - ym);
    ll dist_starts = dx + dy;

    ll count = 0;
    ll max_reach = (2 * dist_starts) / 5 + 20; 

    for (ll i = -max_reach; i <= max_reach; ++i) {
        for (ll j = -max_reach; j <= max_reach; ++j) {
            ll dm = abs(i) + abs(j);
            ll dg = abs(xm + i - xg) + abs(ym + j - yg);
            
            if (7 * dm < 2 * dg) {
                count++;
            }
        }
    }
    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}