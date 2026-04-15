#include <vector>
#include <iostream>
using namespace std;

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
    // store asteroid positions and their indices
    vector<pair<int, int>> asteroids;
    for (int i = 0; i < K; ++i) {
        asteroids.push_back({X[i], Y[i]});
    }

    // Start position
    int x = X[0], y = Y[0];
    int steps = 0;
    bool first_lap = true;

    while (true) {
        // only check for hit if not the starting asteroid on the first lap
        for (int i = 0; i < K; ++i) {
            if (x == X[i] && y == Y[i]) {
                if (!(first_lap && i == 0)) {
                    return i;
                }
            }
        }
        // Move laser
        x = (x + Q) % N;
        y = (y + P) % M;
        steps++;
        // after one full lap, first_lap is false
        if (x == X[0] && y == Y[0]) first_lap = false;
    }
    // should never reach here
    return -1;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
        vector<int> X(K), Y(K);
        for (int i = 0; i < K; i++) {
            int a, b; cin >> a >> b;
            X[i] = a;
            Y[i] = b;
        }
        cout << solve(K, N, M, P, Q, X, Y) << endl;
    }
    return 0;
}
