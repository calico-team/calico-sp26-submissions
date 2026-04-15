#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll xg, yg, xm, ym;
    if (cin >> xg >> yg >> xm >> ym) {
        ll count = 0;
        for (ll x = xm - 200; x <= xm + 200; x++) {
            for (ll y = ym - 200; y <= ym + 200; y++) {
                ll dx_g = x - xg;
                if (dx_g < 0) dx_g = -dx_g;
                ll dy_g = y - yg;
                if (dy_g < 0) dy_g = -dy_g;
                
                ll dist_g = dx_g + dy_g;
                ll dx_m = x - xm;
                
                if (dx_m < 0) dx_m = -dx_m;
                ll dy_m = y - ym;
                if (dy_m < 0) dy_m = -dy_m;
                ll dist_m = dx_m + dy_m;
                if (7 * dist_m < 2 * dist_g) {
                    count = count + 1;
                }
            }
        }
        cout << count << endl;
    }
}

int main() {
    int t;
    if (cin >> t) {
        while (t > 0) {
            solve();
            t = t - 1;
        }
    }
    return 0;
}