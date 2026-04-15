#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        int total = 0;
        for (int x = -200; x <= 200; ++x) {
            for (int y = -200; y <= 200; ++y) {
                int dg = abs(x - xg) + abs(y - yg);
                int dm = abs(x - xm) + abs(y - ym);
                if (dm * 7 < dg * 2) {
                    ++total;
                }
            }
        }
        cout << total << '\n';
    }
    return 0;
}