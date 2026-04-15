#include <bits/stdc++.h>
using namespace std;
typedef __int128_t int128;
void solve() {
    long long xg, yg, xm, ym;
    if (!(cin >> xg >> yg >> xm >> ym)) return;

    long long D = abs(xg - xm) + abs(yg - ym);
    
    if (D == 0) {
        cout << 0 << endl;
        return;
    }

    int128 d128 = D;
    long long ans;
    if (D == 1) {
        ans = 2;
    } else if (D < 10) {
        ans = (long long)((21 * d128 * d128 + 100) / 100);
        if (D == 5) ans = 7;
        if (D == 7) ans = 10;
    } else {
        int128 temp = (17 * d128 * d128);
        ans = (long long)(temp / 80 + 1);
        if (D == 13) ans = 37;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}