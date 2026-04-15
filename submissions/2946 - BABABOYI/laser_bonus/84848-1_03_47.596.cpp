#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a, long long b, long long &x, long long &y){
    if (b == 0) { 
        x = 1; y = 0; 
        return a; 
}
    long long x1, y1;
    long long g = exgcd(b, a % b, x1, y1);
    x = y1; 
    y = x1-(a / b)*y1;
    return g;
}

pair<long long, long long> solve_mod(long long A, long long B, long long M){
    long long x, y;
    long long g = exgcd(A, M, x, y);
    if (B % g != 0) return {-1, -1};
    
    long long m_prime = M / g;
    long long res = ((__int128)x* (B / g) % m_prime+ m_prime) % m_prime;
    return {res, m_prime};
}


void solve() {
    long long K, N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;
    
    vector<pair<long long, long long>> A(K);
    for(int i = 0; i < K; i++) {
        cin >> A[i].first >> A[i].second;
    }
    
    
    long long min_S = -1;
    int best_idx = -1;
    long long X0 =A[0].first;
    long long Y0 =A[0].second;
    
    
    for (int i=0; i < K; i++){
        long long dX = (A[i].first - X0 % N + N) % N;
        long long dY = (A[i].second - Y0 % M + M) % M;
 
 
        auto [Sx, Nx] = solve_mod(Q, dX, N);
        if (Sx == -1) continue;
        
        auto [Sy, My] = solve_mod(P, dY, M);
        if (Sy == -1) continue;
    
    
        long long dS = (Sy - Sx % My + My) % My;
        auto [k, K_mod] = solve_mod(Nx, dS, My);
        if (k == -1) continue; 
  
        long long S = Sx + k * Nx;
        long long LCM = Nx * K_mod;
        if (S == 0) {
            S += LCM;
        }
        if (min_S == -1 || S<min_S) {
            min_S = S;
            best_idx = i;
        }
    }
    
    cout << best_idx << "\n";
}

int main() {
    int T; 
    if (cin >> T) {
        while(T--){
        solve();
      }
    }
    return 0;
}