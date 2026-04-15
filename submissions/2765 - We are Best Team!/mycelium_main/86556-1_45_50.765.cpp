#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;

        long long d = abs(xg - xm) + abs(yg - ym);
        long long ans = (d - 1) * (d - 1) / 2;

        cout << ans << '\n';
    }

    return 0;
}