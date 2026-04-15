#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, vector<int>& A) {

    const long long INF = 1e18;

    vector<vector<long long>> dp(N, vector<long long>(N, INF));
    vector<vector<int>> parent(N, vector<int>(N, -1));

    for (int j = 0; j < N; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i < N; i++) {
        for (int cur = 0; cur < N; cur++) {

            for (int prev = 0; prev < N; prev++) {

                long long cost = dp[i - 1][prev]
                               + abs(A[i] - A[cur])
                               + abs(A[cur] - A[prev]);

                if (cost < dp[i][cur]) {
                    dp[i][cur] = cost;
                    parent[i][cur] = prev;
                }
            }
        }
    }

    long long best = INF;
    int last = 0;

    for (int j = 0; j < N; j++) {
        if (dp[N - 1][j] < best) {
            best = dp[N - 1][j];
            last = j;
        }
    }

    vector<int> path(N);
    path[N - 1] = last;

    for (int i = N - 1; i > 0; i--) {
        path[i - 1] = parent[i][path[i]];
    }

    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = A[path[i]];
    }

    return B;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        vector<int> B = solve(N, A);

        for (int i = 0; i < N; i++) {
            cout << B[i] << " ";
        }
        cout << "\n";
    }
}