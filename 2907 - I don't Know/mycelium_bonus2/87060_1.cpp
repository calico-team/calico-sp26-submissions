#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        
        long long dx = xg - xm;
        if (dx < 0) dx = -dx;
        
        long long dy = yg - ym;
        if (dy < 0) dy = -dy;
        
        long long dist = dx + dy;
        long long k = (dist + 1) / 2;
        
        long long result = k * (k + 1);
        cout << result << endl;
    }
    return 0;
}