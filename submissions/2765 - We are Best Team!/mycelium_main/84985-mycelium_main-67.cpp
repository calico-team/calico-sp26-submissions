#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll xg, yg, xm, ym;
    if (cin >> xg >> yg >> xm >> ym) {
        ll count = 0;
        for (ll x = xm - 200; x <= xm + 200; x++) {
            for (ll y = ym - 200; y <= ym + 200; y++) {
                ll dg = abs(x - xg) + abs(y - yg);
                ll dm = abs(x - xm) + abs(y - ym);
                if (7 * dm < 2 * dg) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}