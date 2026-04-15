#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int testCases;
ll gx, gy, mx, my;

ll calculateMycelium(ll gx, ll gy, ll mx, ll my) {
    ll dx = abs(gx - mx);
    ll dy = abs(gy - my);
    ll tx = mx - dx / 7 * 2 - 10;
    ll ty = my - dy / 7 * 2 - 10;
    ll startX = min(gx, mx) - 1000;
    ll endX = max(gx, mx) + 1000;
    ll startY = min(gy, my) - 1000;
    ll endY = max(gy, my) + 1000;
    ll count = 0;
    for (ll x = startX; x <= endX; ++x) {
        for (ll y = startY; y <= endY; ++y) {
            ll distG = abs(x - gx) + abs(y - gy);
            ll distM = abs(x - mx) + abs(y - my);
            if (7 * distM < 2 * distG) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> testCases;
    while (testCases--) {
        cin >> gx >> gy >> mx >> my;
        cout << calculateMycelium(gx, gy, mx, my) << '\n';
    }

    return 0;
}
