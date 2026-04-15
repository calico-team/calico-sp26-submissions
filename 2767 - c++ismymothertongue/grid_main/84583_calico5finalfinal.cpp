#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> S;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        S.push_back(A[i]);
    }

    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    int M = S.size();

    vector<vector<pair<ll, int>>> dp(N, vector<pair<ll, int>>(M, {1e18, -1}));

    for (int j = 0; j < M; ++j) {
        dp[0][j] = {abs(A[0] - S[j]), -1};
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < M; ++k) {
                ll cost = dp[i-1][k].first + abs(S[j] - S[k]) + abs(A[i] - S[j]);
                if (cost < dp[i][j].first) {
                    dp[i][j] = {cost, k};
                }
            }
        }
    }

    ll min_total = 1e18;
    int last_idx = -1;
    for (int j = 0; j < M; ++j) {
        if (dp[N-1][j].first < min_total) {
            min_total = dp[N-1][j].first;
            last_idx = j;
        }
    }

    vector<ll> b(N);
    for (int i = N - 1; i >= 0; --i) {
        b[i] = S[last_idx];
        last_idx = dp[i][last_idx].second;
    }

    for (int i = 0; i < N; ++i) {
        cout << b[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}