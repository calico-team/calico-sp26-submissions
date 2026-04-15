#include <bits/stdc++.h>
using namespace std;

long long gcdll(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int solve(int K, long long N, long long M, long long P, long long Q,
          vector<long long>& X, vector<long long>& Y) {

    unordered_map<long long, unordered_map<long long, int>> pos;

    for (int i = 0; i < K; i++) {
        pos[X[i]][Y[i]] = i;
    }

    long long x = X[0], y = Y[0];

    long long cycle = (N * M) / gcdll(N, Q) / gcdll(M, P);

    for (long long i = 0; i < cycle; i++) {
        x = (x + Q) % N;
        y = (y + P) % M;

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

    return 0;
}