#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <map>
typedef long long ll;
using namespace std;

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
    int xs = X[0];
    int ys = Y[0];
    
    map<ll, int> mp;
    
    for (int i = 1; i < K; i++) {
        int dx = (X[i] - xs + N) % N;
        int dy = (Y[i] - ys + M) % M;
        
        int g1 = gcd(Q, N);
        int g2 = gcd(P, M);
        
        if (dx % g1 != 0 || dy % g2 != 0) {
            continue;
        }
        
        int n1 = N / g1;
        int q1 = Q / g1;
        int dx1 = dx / g1;
        
        ll tx = 0;
        for (ll t = 0; t < n1; t++) {
            if ((q1 * t) % n1 == dx1) {
                tx = t;
                break;
            }
        }
        
        int m1 = M / g2;
        int p1 = P / g2;
        int dy1 = dy / g2;
        
        ll ty = 0;
        for (ll t = 0; t < m1; t++) {
            if ((p1 * t) % m1 == dy1) {
                ty = t;
                break;
            }
        }
        
        ll g = gcd(n1, m1);
        if ((tx - ty) % g != 0) {
            continue;
        }
        
        ll n1g = n1 / g;
        ll m1g = m1 / g;
        ll diff = (ty - tx) / g;
        
        ll inv = 0;
        for (ll k = 0; k < m1g; k++) {
            if ((k * n1g) % m1g == (diff % m1g + m1g) % m1g) {
                inv = k;
                break;
            }
        }
        
        ll kk = inv;
        ll tt = tx + kk * n1;
        
        ll lcm = n1 * m1 / g;
        tt = ((tt % lcm) + lcm) % lcm;
        
        if (tt == 0) {
            tt = lcm;
        }
        
        mp[tt] = i;
    }
    
    if (mp.empty()) {
        return 0;
    }
    
    return mp.begin()->second;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
        vector<int> X(K), Y(K);
        for (int i = 0; i < K; i++) {
            int a, b; cin >> a >> b;
            X[i] = a;
            Y[i] = b;
        }
        cout << solve(K, N, M, P, Q, X, Y) << endl;
    }
    return 0;
}
