#include <iostream>
using namespace std;

long long absll(long long x) { return (x < 0) ? -x : x; }
long long dist(long long x1, long long y1, long long x2, long long y2) {
    return absll(x1 - x2) + absll(y1 - y2);
}

long long solve(int XG, int YG, int XM, int YM) {
    long long minX = min(XG, XM) - 5000;
    long long maxX = max(XG, XM) + 5000;
    long long minY = min(YG, YM) - 5000;
    long long maxY = max(YG, YM) + 5000;
    long long count = 0;
    for (long long x = minX; x <= maxX; x++) {
        for (long long y = minY; y <= maxY; y++) {
            long long dG = dist(x, y, XG, YG);
            long long dM = dist(x, y, XM, YM);
            if (7 * dM <= 2 * dG) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int XG, YG, XM, YM;
        cin >> XG >> YG >> XM >> YM;
        cout << solve(XG, YG, XM, YM) << '\n';
    }
    return 0;
}