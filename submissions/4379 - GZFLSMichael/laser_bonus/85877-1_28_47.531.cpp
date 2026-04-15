#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;
        int x[100005] = {0}, y[100005] = {0};
        for (int i = 0; i < K; i++) cin >> x[i] >> y[i];
        int x0 = x[0], y0 = y[0];
        long long min_steps = 9e18;
        int ans_idx = -1;

        int a = Q, b = N;
        while (b){
             int t = a % b;
             a = b;
             b = t;
        }
        int g1 = a;
        a = P, b = M;
        while (b){
            int t = a % b;
            a = b;
            b = t;
        }
        int g2 = a;
        long long n1 = N / g1;
        long long m2 = M / g2;

        long long p = n1, qq = m2;
        while (qq){
            long long t = p % qq;
            p = qq;
            qq = t;
        }
        long long period = n1 / p * m2;

        for (int idx = 0; idx < K; idx++) {
            long long dx = (x[idx] - x0 + N) % N;
            long long dy = (y[idx] - y0 + M) % M;

            if (dx % g1 != 0) continue;
            long long q1 = Q / g1;
            long long dx1 = dx / g1;
            long long inv1;
            long long a1 = q1 % n1, m1 = n1;
            long long m0 = m1, y0_inv = 0, x0_inv = 1;
            if (m1 == 1) inv1 = 0;
            else {
                while (a1 > 1) {
                    long long q = a1 / m1;
                    long long t = m1;
                    m1 = a1 % m1;
                    a1 = t;
                    t = y0_inv;
                    y0_inv = x0_inv - q * y0_inv;
                    x0_inv = t;
                }
                if (x0_inv < 0) x0_inv += m0;
                inv1 = x0_inv;
            }
            long long t1 = (dx1 % n1) * inv1 % n1;

            if (dy % g2 != 0) continue;
            long long p2 = P / g2;
            long long dy1 = dy / g2;
            long long inv2;
            long long a2 = p2 % m2, m2_ = m2;
            m0 = m2_, y0_inv = 0, x0_inv = 1;
            if (m2_ == 1) inv2 = 0;
            else {
                while (a2 > 1) {
                    long long q = a2 / m2_;
                    long long t = m2_;
                    m2_ = a2 % m2_;
                    a2 = t;
                    t = y0_inv;
                    y0_inv = x0_inv - q * y0_inv;
                    x0_inv = t;
                }
                if (x0_inv < 0) x0_inv += m0;
                inv2 = x0_inv;
            }
            long long t2 = (dy1 % m2) * inv2 % m2;

            long long m1c = n1, m2c = m2, r1 = t1, r2 = t2;
            long long ga = m1c, gb = m2c;
            while (gb) { long long t = ga % gb; ga = gb; gb = t; }
            long long g = ga;
            if ((r2 - r1) % g != 0) continue;
            long long p_ = m1c / g, q_ = m2c / g;
            long long invp;
            long long ap = p_ % q_, mq = q_;
            m0 = mq, y0_inv = 0, x0_inv = 1;
            if (mq == 1) invp = 0;
            else {
                while (ap > 1) {
                    long long qq = ap / mq;
                    long long t = mq;
                    mq = ap % mq;
                    ap = t;
                    t = y0_inv;
                    y0_inv = x0_inv - qq * y0_inv;
                    x0_inv = t;
                }
                if (x0_inv < 0) x0_inv += m0;
                invp = x0_inv;
            }
            long long k = ((r2 - r1) / g % q_ + q_) % q_ * invp % q_;
            long long lcm = p_ * m2c;
            long long t = (r1 + m1c * k) % lcm;
            if (t == 0) t = lcm;
            if (idx == 0) t = period;

            if (t < min_steps || (t == min_steps && idx < ans_idx)) {
                min_steps = t;
                ans_idx = idx;
            }
        }
        cout << ans_idx << '\n';
    }
    return 0;
}