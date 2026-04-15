#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;

        // shift so mycelium is at (0,0)
        int a = xg - xm;
        int b = yg - ym;

        int D = abs(a) + abs(b);

        if (D == 0) {
            cout << 0 << '\n';
            continue;
        }

        int R = (2 * D - 1) / 5;

        int ans = 0;

        for (int x = -R; x <= R; x++) {
            for (int y = -R; y <= R; y++) {
                int dm = abs(x) + abs(y);
                if (dm > R) continue;

                int dg = abs(x - a) + abs(y - b);

                if (7 * dm < 2 * dg) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}