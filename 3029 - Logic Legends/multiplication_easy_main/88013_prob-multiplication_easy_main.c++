#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, D;
    cin >> N >> M >> D;
    
    vector<int> R(M), C(M), W(M);
    vector<long long> V(M);
    
    for(int i = 0; i < M; i++){
        cin >> R[i] >> C[i] >> V[i] >> W[i];
        R[i]--; C[i]--;
    }
    
    // Work in log space: b[i] = log(a[i])
    // For each constraint: b[R] + b[C] ~ log(V)
    // Weighted least squares: minimize sum W_i*(b[R[i]]+b[C[i]] - log(V[i]))^2
    // Normal equations: for each node u,
    //   sum_{i: R[i]==u or C[i]==u} W[i] * (b[u] + b[other] - log(V[i])) = 0
    // => b[u] * sum_W_u + sum_{neighbors} W[i]*b[other] = sum W[i]*log(V[i])
    // Solve with Gauss-Seidel iteration
    
    vector<double> b(N, 0.0);
    // For each node, accumulate weighted degree and weighted sum of (logV - b[other])
    // Gauss-Seidel:
    
    // Precompute logV
    vector<double> logV(M);
    for(int i = 0; i < M; i++) logV[i] = log((double)V[i]);
    
    // For each node, sum of weights of incident constraints
    vector<double> sumW(N, 0.0);
    for(int i = 0; i < M; i++){
        sumW[R[i]] += W[i];
        sumW[C[i]] += W[i];
    }
    // Avoid nodes with no constraints
    for(int u = 0; u < N; u++) if(sumW[u] == 0) sumW[u] = 1.0;
    
    // Gauss-Seidel iterations
    for(int iter = 0; iter < 200; iter++){
        vector<double> num(N, 0.0);
        for(int i = 0; i < M; i++){
            int u = R[i], v = C[i];
            double w = W[i];
            num[u] += w * (logV[i] - b[v]);
            num[v] += w * (logV[i] - b[u]);
        }
        double maxDiff = 0;
        for(int u = 0; u < N; u++){
            double newb = num[u] / sumW[u];
            maxDiff = max(maxDiff, abs(newb - b[u]));
            b[u] = newb;
        }
        if(maxDiff < 1e-9) break;
    }
    
    // Convert to integers
    vector<long long> a(N);
    for(int u = 0; u < N; u++){
        long long val = (long long)round(exp(b[u]));
        val = max(1LL, min((long long)1e9, val));
        a[u] = val;
    }
    
    // Compute penalty for each constraint, discard top D
    vector<pair<double,int>> penalties(M);
    for(int i = 0; i < M; i++){
        double prod = (double)a[R[i]] * (double)a[C[i]];
        double pen = W[i] * abs(prod - V[i]) / V[i];
        penalties[i] = {pen, i+1};
    }
    sort(penalties.begin(), penalties.end(), greater<>());
    
    // Output
    for(int u = 0; u < N; u++){
        cout << a[u];
        if(u < N-1) cout << ' ';
    }
    cout << '\n';
    
    int d = min(D, M);
    cout << d;
    for(int i = 0; i < d; i++) cout << ' ' << penalties[i].second;
    cout << '\n';
    
    return 0;
}

void read_your_input(){
    // reads from stdin: N M D, then M lines of R C V W
}