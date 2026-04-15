#include <vector>
#include <iostream>
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
int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
    // grid[x][y] = index of asteroid, or -1
    vector<vector<int>> grid(N, vector<int>(M, -1));

    for (int i = 0; i < K; i++) {
        grid[X[i]][Y[i]] = i;
    }

    int x = X[0], y = Y[0];
    int x0 = x, y0 = y;

    // simulate until cycle
    while (true) {
        x = (x + Q) % N;
        y = (y + P) % M;

        if (grid[x][y] != -1) {
            return grid[x][y];
        }
    }
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