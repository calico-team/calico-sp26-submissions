#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // quick and dirty solution for the multiplication table thing
    // i just threw together some log stuff and iterative averaging
    // should beat the AI baselines, hopefully
    
    int N;
    ll M, D;
    cin >> N >> M >> D;
    
    vector<int> R(M), C(M);
    vector<ll> V(M), W(M);
    for (int i = 0; i < M; i++) {
        cin >> R[i] >> C[i] >> V[i] >> W[i];
    }
    
    vector<vector<pair<int, ll>>> adj(N + 1);
    vector<double> totalW(N + 1, 0.0);
    vector<double> rhs(N + 1, 0.0);
    
    for (int i = 0; i < M; i++) {
        int r = R[i], c = C[i];
        ll w = W[i];
        double b = log((double)V[i]);
        adj[r].emplace_back(c, w);
        adj[c].emplace_back(r, w);
        totalW[r] += (double)w;
        totalW[c] += (double)w;
        rhs[r] += (double)w * b;
        rhs[c] += (double)w * b;
    }
    
    vector<double> x(N + 1, 0.0);
    
    // do a few iterations of relaxation
    for (int it = 0; it < 200; it++) {
        for (int i = 1; i <= N; i++) {
            if (totalW[i] < 1e-9) continue;
            double sum_off = 0.0;
            for (auto& p : adj[i]) {
                sum_off += (double)p.second * x[p.first];
            }
            double new_val = (rhs[i] - sum_off) / totalW[i];
            x[i] = new_val;
        }
    }
    
    vector<ll> a(N + 1, 1LL);
    for (int i = 1; i <= N; i++) {
        if (totalW[i] < 1e-9) {
            a[i] = 1;
            continue;
        }
        double expo = exp(x[i]);
        if (expo > 1e9) expo = 1e9;
        if (expo < 1.0) expo = 1.0;
        a[i] = (ll)round(expo);
        if (a[i] < 1) a[i] = 1;
        if (a[i] > 1000000000LL) a[i] = 1000000000LL;
    }
    
    // now figure out which constraints to discard
    vector<pair<double, int>> err_list(M);
    for (int i = 0; i < M; i++) {
        int r = R[i], c = C[i];
        long double prod = (long double)a[r] * (long double)a[c];
        long double vv = (long double)V[i];
        long double absdiff = fabsl(prod - vv);
        long double rel = (vv > 0 ? absdiff / vv : 0.0L);
        long double contrib = rel * (long double)W[i];
        err_list[i] = {(double)contrib, i + 1};
    }
    
    sort(err_list.rbegin(), err_list.rend());
    
    ll dd = min(D, M);
    vector<int> discarded;
    for (ll j = 0; j < dd; j++) {
        discarded.push_back(err_list[j].second);
    }
    
    // output the a array
    for (int i = 1; i <= N; i++) {
        if (i > 1) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    
    // output discarded stuff
    cout << discarded.size();
    for (int idx : discarded) {
        cout << " " << idx;
    }
    cout << "\n";
    
    return 0;
}