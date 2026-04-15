#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

vector<ll> solve_bonus(const vector<ll>& A) {
    int N = A.size();
    
    if (N == 1) {
        return {A[0]};
    }

    
    vector<ll> b = A; // start with A
    
    // Iterative relaxation (like median smoothing)
    for (int iter = 0; iter < 20; iter++) {
        vector<ll> new_b = b;
        for (int i = 0; i < N; i++) {
            vector<ll> candidates;
            candidates.push_back(A[i]);
            if (i > 0) candidates.push_back(b[i-1]);
            if (i < N-1) candidates.push_back(b[i+1]);
            
            // Find best value for b[i]
            ll best_val = b[i];
            ll best_cost = INF;
            
            for (ll cand : candidates) {
                cand = max(1LL, min(cand, 2000000000LL));
                ll cost = abs(A[i] - cand);
                if (i > 0) cost += abs(cand - b[i-1]);
                if (i < N-1) cost += abs(cand - b[i+1]);
                
                if (cost < best_cost) {
                    best_cost = cost;
                    best_val = cand;
                }
            }
            new_b[i] = best_val;
        }
        
        if (new_b == b) break;
        b = new_b;
    }
    
    return b;
}

vector<ll> solve_main(const vector<ll>& A) {
    int N = A.size();
    
    if (N == 1) {
        return {A[0]};
    }
    
    if (N == 2) {
        // Minimize |A1-b1| + |A2-b2| + |b1-b2|
        // Try values around A1 and A2
        vector<ll> candidates = {A[0], A[1]};
        
        ll best_cost = INF;
        vector<ll> best_b = {A[0], A[1]};
        
        for (ll b1 : candidates) {
            for (ll b2 : candidates) {
                ll cost = abs(A[0] - b1) + abs(A[1] - b2) + abs(b1 - b2);
                if (cost < best_cost) {
                    best_cost = cost;
                    best_b = {b1, b2};
                }
            }
        }
        return best_b;
    }
    
    if (N == 3) {
        // Try all combinations from A values
        vector<ll> candidates = {A[0], A[1], A[2]};
        
        ll best_cost = INF;
        vector<ll> best_b = {A[0], A[1], A[2]};
        
        for (ll b1 : candidates) {
            for (ll b2 : candidates) {
                for (ll b3 : candidates) {
                    ll cost = abs(A[0] - b1) + abs(A[1] - b2) + abs(A[2] - b3) +
                             abs(b1 - b2) + abs(b2 - b3);
                    if (cost < best_cost) {
                        best_cost = cost;
                        best_b = {b1, b2, b3};
                    }
                }
            }
        }
        return best_b;
    }
    
    return solve_bonus(A);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        vector<ll> result = solve_main(A);
        
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }
    
    return 0;
}