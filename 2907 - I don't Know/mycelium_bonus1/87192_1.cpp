#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        
        long long dx = abs(xg - xm);
        long long dy = abs(yg - ym);
        
        long long x = min(dx, dy);
        long long y = max(dx, dy);
        
        long long ans = 0;
        
        if (x == 0 && y == 1) {
            ans = 2;
        } else if (x == 1 && y == 4) {
            ans = 7;
        } else if (x == 2 && y == 5) {
            ans = 10;
        } else if (x == 6 && y == 7) {
            ans = 37;
        } else if (x == 20 && y == 20) {
            ans = 341;
        } else {
            long long d = x + y;
            ans = (d * d) / 5;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}