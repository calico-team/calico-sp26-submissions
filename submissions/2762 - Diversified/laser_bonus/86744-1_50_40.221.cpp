#include <bits/stdc++.h>
using namespace std;

int solve(int K, long long N, long long M, long long P, long long Q,
          vector<long long>& X, vector<long long>& Y) {

    unordered_map<long long, unordered_map<long long, int>> pos;
    for (int i = 0; i < K; i++) {
        pos[X[i]][Y[i]] = i;
    }

    long long best_t = LLONG_MAX;
    int best_idx = -1;

    long long x = 0, y = 0;

    long long limit = N; 

    for (long long t = 1; t <= limit; t++) {
        x = (x + Q) % N;
        y = (y + P) % M;

        auto itx = pos.find(x);
        if (itx != pos.end()) {
            auto ity = itx->second.find(y);
            if (ity != itx->second.end()) {
                if (t < best_t) {
                    best_t = t;
                    best_idx = ity->second;
                }
            }
        }
    }

    return best_idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int K;
        long long N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<long long> X(K), Y(K);
        for (int i = 0; i < K; i++) {
            cin >> X[i] >> Y[i];
        }

        cout << solve(K, N, M, P, Q, X, Y) << "\n";
    }
}