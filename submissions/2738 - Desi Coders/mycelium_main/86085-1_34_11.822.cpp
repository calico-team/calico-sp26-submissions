#include <bits/stdc++.h>
using namespace std;

long long solve_one(long long xg, long long yg, long long xm, long long ym) {
    long long dx = xg - xm;
    long long dy = yg - ym;

    long long D = llabs(dx) + llabs(dy);
    long long R = (2 * D) / 5;

    long long count = 0;

    for (long long x = -R; x <= R; x++) {
        long long rem = R - llabs(x);
        for (long long y = -rem; y <= rem; y++) {
            long long lhs = 7 * (llabs(x) + llabs(y));
            long long rhs = 2 * (llabs(x - dx) + llabs(y - dy));
            if (lhs < rhs) count++;
        }
    }

    return count;
}

void read_your_input() {
    int t;
    cin >> t;
    while (t--) {
        long long xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        cout << solve_one(xg, yg, xm, ym) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_your_input();
    return 0;
}