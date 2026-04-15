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
int solve(int K, int N, int M, int P, int Q, vector<pair<int, int>> XY) {
	// YOUR CODE HERE
	int x = XY[0].first;
	int y = XY[0].second;
	bool notFound = true;
	while (notFound) {
		x = (x + Q) % N;
		y = (y + P) % M;
		std::pair<int,int> test;
		test.first = x;
		test.second = y;
		auto t = std::find(XY.begin(), XY.end(), test);
		if (t != XY.end()) {
			return t - XY.begin();
		}
	}
	return 0;
}


int main() {
	int T; cin >> T;
	while (T--) {
		int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		vector<pair<int, int>> XY(K);
		for (int i = 0; i < K; i++) {
			int a, b; cin >> a >> b;
			XY[i].first = a;
			XY[i].second = b;
		}
		cout << solve(K, N, M, P, Q, XY) << endl;
	}
	return 0;
}