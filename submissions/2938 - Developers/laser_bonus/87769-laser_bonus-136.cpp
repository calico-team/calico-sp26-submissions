#include <iostream>
#include <vector>

using namespace std;

// Extended GCD
long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0; return a;
    }
    long long x1, y1;
    long long g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Modular Inverse
long long modInverse(long long a, long long m) {
    long long x, y;
    extgcd(a, m, x, y);
    return (x % m + m) % m;
}

// Ensure maximum compiler compatibility without relying strictly on #include <numeric>
long long get_gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int t;
    if (!(cin >> t)) return;
    
    while (t--) {
        long long K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;
        
        vector<pair<long long, long long>> asteroids(K);
        for (int i = 0; i < K; i++) {
            cin >> asteroids[i].first >> asteroids[i].second;
        }
        
        long long X0 = asteroids[0].first;
        long long Y0 = asteroids[0].second;
        
        long long min_S = -1;  // Represents infinity since limits can slightly exceed INT blocks
        int best_idx = 0;
        
        // Find general cycle period
        long long g1_p = get_gcd(Q, N);
        long long N_prime_p = N / g1_p;
        long long A_p = (N_prime_p * P) % M;
        long long g2_p = get_gcd(A_p, M);
        long long M_prime_p = M / g2_p;
        long long period = N_prime_p * M_prime_p;
        
        for (int i = 0; i < K; i++) {
            long long Xi = asteroids[i].first;
            long long Yi = asteroids[i].second;
            
            long long dX = (Xi - X0) % N;
            if (dX < 0) dX += N; // Wrap negative modulos 
            
            long long dY = (Yi - Y0) % M;
            if (dY < 0) dY += M;
            
            long long g1 = get_gcd(Q, N);
            if (dX % g1 != 0) continue;
            
            long long Q_prime = Q / g1;
            long long N_prime = N / g1;
            long long dX_prime = dX / g1;
            
            long long invQ = modInverse(Q_prime, N_prime);
            long long S0 = (dX_prime * invQ) % N_prime;
            
            long long A = (N_prime * P) % M;
            long long B = (dY - (S0 * P) % M) % M;
            if (B < 0) B += M; // Force non-negative representation
            
            long long g2 = get_gcd(A, M);
            if (B % g2 != 0) continue;
            
            long long A_prime = A / g2;
            long long M_prime = M / g2;
            long long B_prime = B / g2;
            
            long long invA = modInverse(A_prime, M_prime);
            long long k0 = (B_prime * invA) % M_prime;
            
            long long S = S0 + k0 * N_prime;
            
            if (S == 0) {
                S = period; // Account for the initial asteroid loop
            }
            
            if (min_S == -1 || S < min_S) {
                min_S = S;
                best_idx = i;
            }
        }
        
        cout << best_idx << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
