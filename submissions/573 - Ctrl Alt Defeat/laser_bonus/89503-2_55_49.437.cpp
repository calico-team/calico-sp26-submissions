#include <bits/stdc++.h>
using namespace std;

long long egcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);

    return g;
}

long long inv(long long r, long long m) {
    long long x, y;
    long long g = egcd(r, m, x, y);

    if (g != 1) return -1;
    return (x % m + m) % m;
}

long long crt(long long r1, long long m1, long long r2, long long m2) {
    r1 = (r1 % m1 + m1) % m1;
    r2 = (r2 % m2 + m2) % m2;

    long long g = std::gcd(m1, m2);
    if ((r2 - r1) % g != 0) return -1;

    long long m1p = m1 / g;
    long long m2p = m2 / g;

    long long x, y;
    egcd(m1p, m2p, x, y);

    long long t = (r2 - r1) / g;
    t %= m2p;
    if (t < 0) t += m2p;

    long long k = (__int128)t * ((x % m2p + m2p) % m2p) % m2p;

    long long lcm = (__int128)m1p * m2;
    long long res = (r1 + (__int128)m1 * k) % lcm;
    if (res < 0) res += lcm;

    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long T;
    cin >> T;
    while (T--) {
        long long K,N,M,P,Q;
        cin >> K >> N >> M >> P >> Q;
        
        if (P == M) {
            P = 0;
        }
        if (Q == N) {
            Q = 0;
        }
        
        long long g1 = gcd(Q, N);
        long long g2 = gcd(P, M);
        
        Q /= g1; N /= g1;
        P /= g2; M /= g2;
        
        long long P_inv = inv(P, M);
        long long Q_inv = inv(Q, N);
        long long M_inv = inv(M, N);
        long long N_inv = inv(N, M);
        
        //cout << P_inv << ' ' << Q_inv << ' ' << M_inv << ' ' << N_inv << ' ' << '\n';
        
        long long X0, Y0;
        cin >> X0 >> Y0;
        
        long long best_val = N * M;
        long long best_i = 0;
        
        for (long long i = 1; i < K; i++) {
            long long Xi, Yi;
            cin >> Xi >> Yi;
            
            long long Rxi = (Xi - X0) % (N*g1);
            long long Ryi = (Yi - Y0) % (M*g2);
            
            if (Rxi < 0) {
                Rxi = Rxi + N*g1;
            }
            if (Ryi < 0) {
                Ryi = Ryi + M*g2;
            }
            
            if (Rxi % g1 != 0 || Ryi % g2 != 0) {
                continue;
            }
            
            long long Ixi = (Rxi / g1 * Q_inv) % N;
            long long Iyi = (Ryi / g2 * P_inv) % M;
            
            long long cur_val = crt(Ixi, N, Iyi, M);
            if (cur_val <= 0) {
                continue;
            }
            if (cur_val < best_val) {
                best_val = cur_val;
                best_i = i;
            }
        }
        
        cout << best_i << '\n';
    }
    
    return 0;
}