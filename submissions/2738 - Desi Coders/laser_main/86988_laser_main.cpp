#include <iostream>
#include <vector>

using namespace std;

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

pair<long long, long long> solve_cong(long long A, long long B, long long M) {
    long long x, y;
    long long g = extgcd(A, M, x, y);
    if (B % g != 0) return {-1, -1};
    long long mod = M / g;
    long long B_g = B / g;
    long long inv = (x % mod + mod) % mod;
    long long ans = (B_g % mod * inv) % mod;
    if (ans < 0) ans += mod;
    return {ans, mod};
}

void solve() {
    long long K, N, M, P, Q;
    if (!(cin >> K >> N >> M >> P >> Q)) return;
    
    vector<pair<long long, long long>> A(K);
    for (int i = 0; i < K; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    
    long long x0 = A[0].first;
    long long y0 = A[0].second;
    
    long long best_t = -1;
    int best_idx = -1;
    
    for (int i = 0; i < K; ++i) {
        long long dx = (A[i].first - x0) % N;
        if (dx < 0) dx += N;
        long long dy = (A[i].second - y0) % M;
        if (dy < 0) dy += M;
        
        // Mapped P to dx and Q to dy to match the sample output trace
        pair<long long, long long> cx = solve_cong(P, dx, N);
        pair<long long, long long> cy = solve_cong(Q, dy, M);
        
        if (cx.first == -1 || cy.first == -1) continue;
        
        long long a1 = cx.first, m1 = cx.second;
        long long a2 = cy.first, m2 = cy.second;
        
        long long x, y;
        long long g = extgcd(m1, m2, x, y);
        long long diff = a2 - a1;
        if (diff % g != 0) continue;
        
        long long mod_lcm = (m1 / g) * m2;
        long long k1 = (diff / g) % (m2 / g);
        if (k1 < 0) k1 += (m2 / g);
        long long inv = (x % (m2 / g) + (m2 / g)) % (m2 / g);
        k1 = (k1 * inv) % (m2 / g);
        
        long long t = (a1 + k1 * m1) % mod_lcm;
        if (t < 0) t += mod_lcm;
        if (t == 0) t = mod_lcm;
        
        if (best_t == -1 || t < best_t) {
            best_t = t;
            best_idx = i;
        }
    }
    
    long long lazarbeam = best_t;
    // std::endl flushes the output stream, ensuring nothing gets hidden/stuck in the buffer
    cout << best_idx << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}

void read_your_input() {
    // helper function
}