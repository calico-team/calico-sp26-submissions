#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;
typedef long long ll;

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
    int sx = X[0];
    int sy = Y[0];
    
    unordered_map<ll, int> pos_map;
    
    for (int i = 1; i < K; i++) {
        int dx = (X[i] - sx + N) % N;
        int dy = (Y[i] - sy + M) % M;
        
        int gx = gcd(Q, N);
        int gy = gcd(P, M);
        
        if (dx % gx != 0 || dy % gy != 0) {
            continue;
        }
        
        int n1 = N / gx;
        int q1 = Q / gx;
        int dx1 = dx / gx;
        
        int m1 = M / gy;
        int p1 = P / gy;
        int dy1 = dy / gy;
        
        ll inv_q = 0, inv_p = 0;
        for (int t = 0; t < n1; t++) {
            if ((q1 * 1LL * t) % n1 == dx1) {
                inv_q = t;
                break;
            }
        }
        
        for (int t = 0; t < m1; t++) {
            if ((p1 * 1LL * t) % m1 == dy1) {
                inv_p = t;
                break;
            }
        }
        
        ll g = gcd(n1, m1);
        if ((inv_q - inv_p) % g != 0) {
            continue;
        }
        
        ll n1g = n1 / g;
        ll m1g = m1 / g;
        ll diff = (inv_p - inv_q) / g;
        diff = (diff % m1g + m1g) % m1g;
        
        ll inv_n1 = 0;
        for (int t = 0; t < m1g; t++) {
            if ((t * n1g) % m1g == diff) {
                inv_n1 = t;
                break;
            }
        }
        
        ll t = inv_q + inv_n1 * n1;
        ll period = n1 * 1LL * m1g;
        t = ((t % period) + period) % period;
        
        if (t == 0) {
            t = period;
        }
        
        ll key = t;
        if (pos_map.find(key) == pos_map.end() || pos_map[key] > i) {
            pos_map[key] = i;
        }
    }
    
    if (pos_map.empty()) {
        return 0;
    }
    
    ll min_step = 1e18;
    int ans = 0;
    for (auto& p : pos_map) {
        if (p.first < min_step) {
            min_step = p.first;
            ans = p.second;
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) {
        int K, N, M, P, Q; 
        cin >> K >> N >> M >> P >> Q;
        vector<int> X(K), Y(K);
        for (int i = 0; i < K; i++) {
            cin >> X[i] >> Y[i];
        }
        cout << solve(K, N, M, P, Q, X, Y) << '\n';
    }
    return 0;
}