#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <unordered_set>
#include <map>
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
	map<pair<int, int>, size_t> asteroids;
	for (size_t i {0}; i < X.size(); i++) {
		asteroids.insert({{X[i], Y[i]}, i});
	}
	int laserX = X[0] + Q;
	int laserY = Y[0] + P;
	while (1) {
		auto it = asteroids.find({laserX, laserY});
		if (it != asteroids.end()) {
			return it->second;
		}
		laserX += Q;
		laserY += P;
		laserX = laserX % N;
		laserY = laserY % M;
	}
	return 0;
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