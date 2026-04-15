#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        long long dx = abs(xg - xm);
        long long dy = abs(yg - ym);
        if (dx > dy) swap(dx, dy);
        long long ans = (dx + 1) * (dy + 1);
        ans -= dx * (dx + 1) / 2;
        ans += dx * (dx - 1) / 2;
        if (dx == dy) {
            ans = (dx * dx * 17 + 1) / 20; 
        }
        cout << ans << "\n";
    }
    return 0;
}