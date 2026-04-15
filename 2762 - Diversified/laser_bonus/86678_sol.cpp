#include <bits/stdc++.h>
using namespace std;

long long gcdll(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int solve(int K, long long N, long long M, long long P, long long Q,
          vector<long long>& X, vector<long long>& Y) {

    long long best_t = LLONG_MAX;
    int best_idx = -1;

    for (int i = 0; i < K; i++) {

        long long dx = (X[i] - X[0]) % N;
        if (dx < 0) dx += N;

        long long dy = (Y[i] - Y[0]) % M;
        if (dy < 0) dy += M;

        long long g1 = gcdll(Q, N);
        long long g2 = gcdll(P, M);

        if (dx % g1 != 0 || dy % g2 != 0) continue;

        long long n1 = N / g1;
        long long m1 = M / g2;

        long long stepX = Q / g1;
        long long stepY = P / g2;

        long long targetX = dx / g1;
        long long targetY = dy / g2;

        long long tX = -1, tY = -1;

        // brute small cycle only (safe bounds)
        for (long long t = 0; t < n1; t++) {
            if ((t * stepX) % n1 == targetX) {
                tX = t;
                break;
            }
        }

        for (long long t = 0; t < m1; t++) {
            if ((t * stepY) % m1 == targetY) {
                tY = t;
                break;
            }
        }

        if (tX == -1 || tY == -1 || tX != tY) continue;

        if (tX == 0) continue; // must wrap once

        if (tX < best_t) {
            best_t = tX;
            best_idx = i;
        }
    }

    return best_idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int K;
        long long N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<long long> X(K), Y(K);
        for (int i = 0; i < K; i++) {
            cin >> X[i] >> Y[i];
        }

        cout << solve(K, N, M, P, Q, X, Y) << "\n";
    }
}