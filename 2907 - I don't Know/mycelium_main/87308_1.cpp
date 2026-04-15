#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;


ll dist(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
    ll xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;

    ll count = 0;
    
    
    ll range = dist(xg, yg, xm, ym) * 2; 
    
    for (ll x = xm - range; x <= xm + range; ++x) {
        for (ll y = ym - range; y <= ym + range; ++y) {
            ll tm = 7 * dist(x, y, xm, ym);
            ll tg = 2 * dist(x, y, xg, yg);
            
            
            if (x == xm && y == ym) {
                count++;
            } 
           
            else if (tm < tg) {
                count++;
            }
        }
    }
    cout << count << endl;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}