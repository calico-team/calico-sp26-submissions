#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;

/**
 * Find the index of the first asteroid hit by the laser.
 *
 * K: Number of asteroids
 * N, M: Bounds for x- and y-coordinates
 * P, Q: Laser movement (P along y-axis, Q along x-axis)
 * X: List of x-coordinates of asteroids
 * Y: List of y-coordinates of asteroids
 */
int solve(int K, int N, int M, int P, int Q, vector<pair<int, int>> asteroids) {
    int laser_x = asteroids[0].first, laser_y = asteroids[0].second;
    while (true) {
        laser_x += Q;
        laser_y += P;
        if (laser_x > N) laser_x -= N;
        if (laser_y > M) laser_y -= M;

        auto it = find(asteroids.begin(), asteroids.end(), make_pair(laser_x, laser_y));
        if (it != asteroids.end()) {
            int idx = it - asteroids.begin();
            return idx;
        }
    }
}


int main() {
    int T; cin >> T;
    while (T--) {
        int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
        vector<pair<int, int>> asteroids(K);
        for (int i = 0; i < K; i++) {
            int a, b; cin >> a >> b;
            asteroids[i] = make_pair(a, b);
        }
        cout << solve(K, N, M, P, Q, asteroids) << endl;
    }
    return 0;
}