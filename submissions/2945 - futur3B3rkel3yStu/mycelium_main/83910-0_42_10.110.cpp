#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(int x, int y, int x1, int y1) {
    ll a = x - x1;
    ll b = y - y1;

    ll D = abs(a) + abs(b);
    ll R = (2 * D - 1) / 5;

    ll ans = 0;

    for (ll i = -R; i <= R; i++) {
        for (ll j = -R; j <= R; j++) {
            ll dM = abs(i) + abs(j);
            ll dG = abs(i - a) + abs(j - b);
            if (7 * dM < 2 * dG) ans++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x, y, x1, y1;
        cin >> x >> y >> x1 >> y1;
        cout << f(x, y, x1, y1) << '\n';
    }
}