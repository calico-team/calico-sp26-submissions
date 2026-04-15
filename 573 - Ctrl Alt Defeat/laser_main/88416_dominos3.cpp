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
    
    if (g != 1) {
        return -1;
    }
    
    return (x % m + m) % m;
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
            
            long long Rxi = (Xi - X0 + N * g1) % (N*g1);
            long long Ryi = (Yi - Y0 + M * g2) % (M*g2);
            
            if (Rxi % g1 != 0 || Ryi % g2 != 0) {
                continue;
            }
            
            long long Ixi = (Rxi / g1 * Q_inv) % N;
            long long Iyi = (Ryi / g2 * P_inv) % M;
            
            if (M == N) {
                if (Ixi == Iyi) {
                    long long cur_val = Ixi;
                    if (cur_val < best_val) {
                        best_val = cur_val;
                        best_i = i;
                    }
                }
            }
            else {
                long long cur_val = (Ixi * M * M_inv + Iyi * N * N_inv) % (N * M);
                //cout << Xi << ' ' << Yi << ' ' << cur_val << ' ' << '\n';
                
                if (cur_val < best_val) {
                    best_val = cur_val;
                    best_i = i;
                }
            }
        }
        
        cout << best_i << '\n';
    }
    
    return 0;
}