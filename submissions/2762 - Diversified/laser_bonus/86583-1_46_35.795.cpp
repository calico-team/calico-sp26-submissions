#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    size_t operator()(const pair<long long,long long>& p) const {
        return p.first * 1315423911ULL + p.second;
    }
};

int solve(int K, long long N, long long M, long long P, long long Q,
          vector<long long>& X, vector<long long>& Y) {

    unordered_map<long long, unordered_map<long long, int>> pos;

    for (int i = 0; i < K; i++) {
        pos[X[i]][Y[i]] = i;
    }

    long long x = X[0], y = Y[0];

    unordered_set<pair<long long,long long>, PairHash> seen;

    while (true) {
        x = (x + Q) % N;
        y = (y + P) % M;

        pair<long long,long long> cur = {x, y};

        if (seen.count(cur)) break;
        seen.insert(cur);

        if (pos.count(x) && pos[x].count(y)) {
            return pos[x][y];
        }
    }

    return -1;
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