#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
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
	// YOUR CODE HERE
	unordered_map<long long, int> pos;

	for (int i = 0; i < K; i++) {
		long long key = 1LL * X[i] * 1e6 + Y[i]; // just to make a unique key instead of checking pair of points.
		pos[key] = i;
	}

	int x = X[0], y = Y[0];

	while (true) {
		x = (x + Q) % N;
		y = (y + P) % M;

		long long key = 1LL * x * 1e6 + y;

		if (pos.count(key)) return pos[key];

		if (x == X[0] && y == Y[0]) return 0;
	}
	
	return -1; // never reach bcz ans deterministic ha.
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