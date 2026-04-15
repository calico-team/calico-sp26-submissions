#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, vector<int>& A) {
    vector<int> modA(A);
    sort(modA.begin(), modA.end());
    modA.erase(unique(modA.begin(), modA.end()), modA.end());
    int M = modA.size();

    vector<long long> dp(M), ndp(M);
    vector<vector<int>> path(N, vector<int>(M, 0));

    for (int j = 0; j < M; j++) dp[j] = abs(A[0] - modA[j]);

    for (int i = 1; i < N; i++) {
        vector<long long> pre(M);
        vector<int> pre_i(M);
        pre[0] = dp[0] - modA[0]; pre_i[0] = 0;
        for (int k = 1; k < M; k++) {
            long long v = dp[k] - modA[k];
            if (v < pre[k-1]) { 
                pre[k] = v;
                pre_i[k] = k;
            }
            else { 
                pre[k] = pre[k-1]; pre_i[k] = pre_i[k-1]; 
            }
        }

        vector<long long> suf(M);
        vector<int> suf_i(M);
        suf[M-1] = dp[M-1] + modA[M-1]; suf_i[M-1] = M-1;
        for (int k = M-2; k >= 0; k--) {
            long long v = dp[k] + modA[k];
            if (v < suf[k+1]) { 
                suf[k] = v;
                suf_i[k] = k;
            }
            else { 
                suf[k] = suf[k+1]; 
                suf_i[k] = suf_i[k+1]; 
            }
        }

        for (int j = 0; j < M; j++) {
            long long opt_left  = pre[j] + (long long)modA[j]; // best k <= j
            long long opt_right = suf[j] - (long long)modA[j]; // best k >= j

            long long best;
            int best_k;
            if (opt_left <= opt_right) { 
                best = opt_left;
                best_k = pre_i[j]; 
            }
            else {
                best = opt_right; 
                best_k = suf_i[j]; 
            }
            ndp[j] = best + abs(A[i] - modA[j]);
            path[i][j] = best_k;
        }
        dp = ndp;
    }

    int best_j = (int)(min_element(dp.begin(), dp.end()) - dp.begin());

    // Reconstruct path backwards
    vector<int> B(N);
    B[N-1] = modA[best_j];
    for (int i = N-1; i > 0; i--) {
        best_j = path[i][best_j];
        B[i-1] = modA[best_j];
    }
    return B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        vector<int> result = solve(N, A);
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}