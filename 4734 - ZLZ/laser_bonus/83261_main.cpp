#include <iostream>
#include <algorithm>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) { x = 1; y = 0; return a; }
    int x1, y1;
    int g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

bool solve(int a, int b, int mod, int &x) {
    int y;
    int g = exgcd(a, mod, x, y);
    if (b % g) return false;
    x = (int)((1LL * x * (b / g)) % mod);
    if (x < 0) x += mod;
    return true;
}

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        int X[100005], Y[100005];
        for (int i = 0; i < K; i++) cin >> X[i] >> Y[i];

        int x0 = X[0], y0 = Y[0];

        int best_t = -1;
        int best_idx = -1;

        int L = lcm(N, M);

        int lazarbeam = 0;

        for (int i = 1; i < K; i++) {
            int dx = (X[i] - x0) % N;
            if (dx < 0) dx += N;

            int dy = (Y[i] - y0) % M;
            if (dy < 0) dy += M;

            int t1, t2;

            if (!solve(Q, dx, N, t1)) continue;
            if (!solve(P, dy, M, t2)) continue;

            int diff = (t2 - t1) % M;
            if (diff < 0) diff += M;

            int k;
            if (!solve(N, diff, M, k)) continue;

            int t = (t1 + (int)((1LL * k * N) % L)) % L;

            if (t == 0) t = L;

            if (best_t == -1 || t < best_t) {
                best_t = t;
                best_idx = i;
            }
        }

        if (best_idx == -1) best_idx = 0;
        cout << best_idx << '\n';
    }

    return 0;
}
