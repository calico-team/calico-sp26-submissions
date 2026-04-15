#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        long long K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;

        vector<long long> X(K), Y(K);
        for (int i = 0; i < K; i++) cin >> X[i] >> Y[i];

        map<pair<long long,long long>, int> asteroids;
        for (int i = 0; i < K; i++)
            asteroids[{X[i], Y[i]}] = i;

        long long cx = X[0], cy = Y[0];
        long long period = N / __gcd(N, M) * M; // laser revisits start after lcm(N,M) steps

        int ans = -1;
        for (long long s = 1; s <= period; s++) {
            cx = (cx + Q) % N;
            cy = (cy + P) % M;
            if (asteroids.count({cx, cy})) {
                ans = asteroids[{cx, cy}];
                break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}