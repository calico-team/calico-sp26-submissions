#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {

    int x0 = X[0], y0 = Y[0];

    ll bestT = (ll)4e18;
    int ans = 0;

    for (int i = 0; i < K; i++) {

        ll dx = (X[i] - x0) % N;
        if (dx < 0) dx += N;

        ll dy = (Y[i] - y0) % M;
        if (dy < 0) dy += M;

        for (ll t = 0; t < (ll)N * M && t < bestT; t++) {

            if ((t * Q) % N == dx && (t * P) % M == dy) {

                if (t == 0 && i == 0) continue;

                if (t < bestT) {
                    bestT = t;
                    ans = i;
                }
                break;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<int> X(K), Y(K);
        for (int i = 0; i < K; i++) {
            cin >> X[i] >> Y[i];
        }

        cout << solve(K, N, M, P, Q, X, Y) << "\n";
    }

    return 0;
}
