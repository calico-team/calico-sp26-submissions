#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, vector<int>& A) {
    vector<int> cands = A;
    sort(cands.begin(), cands.end());
    cands.erase(unique(cands.begin(), cands.end()), cands.end());
    int M = cands.size();

    const long long INF = 2e18;
    vector<long long> dp(M), ndp(M);
    vector<vector<int>> choice(N, vector<int>(M, 0));

    for (int j = 0; j < M; j++)
        dp[j] = abs(A[0] - cands[j]);

    for (int i = 1; i < N; i++) {
        // left pass: min over j<=k of dp[j] - cands[j], then add cands[k]
        vector<long long> leftVal(M, INF);
        vector<int> leftIdx(M, 0);
        {
            long long best = INF; int bestJ = 0;
            for (int j = 0; j < M; j++) {
                long long v = dp[j] - cands[j];
                if (v < best) { best = v; bestJ = j; }
                leftVal[j] = best; leftIdx[j] = bestJ;
            }
        }
     vector<long long> rightVal(M, INF);
        vector<int> rightIdx(M, 0);
        {
            long long best = INF; int bestJ = M-1;
            for (int j = M-1; j >= 0; j--) {
                long long v = dp[j] + cands[j];
                if (v < best) { best = v; bestJ = j; }
                rightVal[j] = best; rightIdx[j] = bestJ;
            }
        }

        for (int k = 0; k < M; k++) {
            long long costL = leftVal[k] + cands[k];
            long long costR = rightVal[k] - cands[k];
            if (costL <= costR) { ndp[k] = costL; choice[i][k] = leftIdx[k]; }
            else                { ndp[k] = costR; choice[i][k] = rightIdx[k]; }
            ndp[k] += abs(A[i] - cands[k]);
        }
        dp = ndp;
    }

    int cur = min_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> B(N);
    B[N-1] = cands[cur];
    for (int i = N-1; i >= 1; i--) {
        cur = choice[i][cur];
        B[i-1] = cands[cur];
    }
    return B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
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