#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, vector<int>& A) {
    vector<int> modA(A);
    sort(modA.begin(), modA.end());
    modA.erase(unique(modA.begin(), modA.end()), modA.end());
    int M = modA.size();

    vector<vector<long long>> dpHistory(N, vector<long long>(M));

    for (int j = 0; j < M; j++) dpHistory[0][j] = abs((long long)A[0] - modA[j]);

    for (int i = 1; i < N; i++) {
        vector<long long> pre(M);
        vector<int> pre_i(M);
        pre[0] = dpHistory[i-1][0] - modA[0]; pre_i[0] = 0;
        for (int k = 1; k < M; k++) {
            long long v = dpHistory[i-1][k] - modA[k];
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
        suf[M-1] = dpHistory[i-1][M-1] + modA[M-1]; suf_i[M-1] = M-1;
        for (int k = M-2; k >= 0; k--) {
            long long v = dpHistory[i-1][k] + modA[k];
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

            long long best = min(opt_left, opt_right);
            dpHistory[i][j] = best + abs((long long)A[i] - modA[j]);
        }
    }

    int best_j = (int)(min_element(dpHistory[N-1].begin(), dpHistory[N-1].end()) - dpHistory[N-1].begin());

    // Reconstruct path backwards
    vector<int> B(N);
    B[N-1] = modA[best_j];
    for (int i = N-1; i > 0; i--) {
        int preBest = -1;
        long long bbest = LLONG_MAX;
        for (int k = 0; k < M; k++) {
            long long cost = dpHistory[i-1][k] + abs((long long)modA[best_j] - modA[k]);
            if (cost < bbest) { 
                bbest = cost; 
                preBest = k; 
            }
        }
        best_j = preBest;
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