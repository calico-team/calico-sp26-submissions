#include <bits/stdc++.h>

using namespace std;

long long mod(long long a, long long m) {
    long long r = a % m;
    return r < 0 ? r + m : r;
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    exgcd(a, m, x, y);
    return mod(x, m);
}

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int K;
        long long N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<pair<long long, long long>> asteroids(K);
        for (int i = 0; i < K; ++i) {
            cin >> asteroids[i].first >> asteroids[i].second;
        }

        long long x0 = asteroids[0].first;
        long long y0 = asteroids[0].second;

        long long min_t = -1;
        int ans = -1;
        long long g1 = gcd(Q, N);
        long long M1 = N / g1;
        long long inv_Q = modInverse(Q / g1, M1);
        long long g2 = gcd(P, M);
        long long M2 = M / g2;
        long long inv_P = modInverse(P / g2, M2);

        for (int i = 0; i < K; ++i) {
            long long dx = mod(asteroids[i].first - x0, N);
            long long dy = mod(asteroids[i].second - y0, M);

            if (dx % g1 != 0 || dy % g2 != 0) continue;

            long long t1 = mod((dx / g1) % M1 * inv_Q, M1);
            long long t2 = mod((dy / g2) % M2 * inv_P, M2);

            long long A = M1;
            long long B = M2;
            long long C = t2 - t1;

            long long x, y;
            long long g = exgcd(A, B, x, y);

            if (C % g != 0) continue;
            long long B_prime = B / g;
            
            long long C_prime = mod(C / g, B_prime);
            long long x_mod = mod(x, B_prime);

            long long k1 = (x_mod * C_prime) % B_prime;
            long long t = t1 + k1 * A;

            if (t == 0) {
                long long L = A * B_prime; 
                t = L;
            }

            if (min_t == -1 || t < min_t) {
                min_t = t;
                ans = i;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}