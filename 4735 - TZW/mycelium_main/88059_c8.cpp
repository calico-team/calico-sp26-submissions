#include <bits/stdc++.h>
using namespace std;

int solve_test_case(int xg, int yg, int xm, int ym) {
    int radius = 0;
    while (true) {
        bool found = false;
        for (int dx = -radius; dx <= radius; dx++) {
            int dy = radius - abs(dx);
            if (dy < 0) continue;
            int x = xm + dx, y = ym + dy;
            int dm = radius;
            int dg = abs(x - xg) + abs(y - yg);
            if (7 * dm < 2 * dg) {
                found = true;
                break;
            }
            if (dy != 0) {
                x = xm + dx; y = ym - dy;
                if (7 * radius < 2 * (abs(x - xg) + abs(y - yg))) {
                    found = true;
                    break;
                }
            }
        }
        if (!found && radius > 0) break;
        radius++;
        if (radius > 10000) break;
    }
    
    int ans = 0;
    for (int dx = -radius; dx <= radius; dx++) {
        for (int dy = -radius; dy <= radius; dy++) {
            int x = xm + dx, y = ym + dy;
            int dm = abs(dx) + abs(dy);
            int dg = abs(x - xg) + abs(y - yg);
            if (7 * dm < 2 * dg) {
                ans++;
            }
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        cout << solve_test_case(xg, yg, xm, ym) << "\n";
    }
    
    return 0;
}