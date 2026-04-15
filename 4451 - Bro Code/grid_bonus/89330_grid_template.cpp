#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, vector<int>& A) {
    vector<int> cands = A;
    sort(cands.begin(), cands.end());
    cands.erase(unique(cands.begin(), cands.end()), cands.end());
    int M = cands.size();

    const long long INF = 2e18;
    vector<long long> dp(M), ndp(M);

    for (int j = 0; j < M; j++)
        dp[j] = abs(A[0] - cands[j]);

    vector<vector<long long> > all_dp(N, vector<long long>(M));
    all_dp[0] = dp;

    for (int i = 1; i < N; i++) {
        vector<long long> leftVal(M, INF);
        vector<int> leftIdx(M, 0);
        {
            long long best = INF; int bestJ = 0;
            for (int j = 0; j < M; j++) {
                long long v = dp[j] - (long long)cands[j];
                if (v < best) { best = v; bestJ = j; }
                leftVal[j] = best; leftIdx[j] = bestJ;
            }
        }
        vector<long long> rightVal(M, INF);
        vector<int> rightIdx(M, 0);
        {
            long long best = INF; int bestJ = M-1;
            for (int j = M-1; j >= 0; j--) {
                long long v = dp[j] + (long long)cands[j];
                if (v < best) { best = v; bestJ = j; }
                rightVal[j] = best; rightIdx[j] = bestJ;
            }
        }

        for (int k = 0; k < M; k++) {
            long long costL = leftVal[k] + cands[k];
            long long costR = rightVal[k] - cands[k];
            ndp[k] = min(costL, costR) + abs(A[i] - cands[k]);
        }
        dp = ndp;
        all_dp[i] = dp;
    }

    // reconstruct
    vector<int> B(N);
    int cur = min_element(dp.begin(), dp.end()) - dp.begin();
    B[N-1] = cands[cur];

    for (int i = N-1; i >= 1; i--) {
        long long best = INF; int bestJ = 0;
        for (int j = 0; j < M; j++) {
            long long cost = all_dp[i-1][j] + abs((long long)cands[j] - cands[cur]);
            if (cost < best) { best = cost; bestJ = j; }
        }
        cur = bestJ;
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
