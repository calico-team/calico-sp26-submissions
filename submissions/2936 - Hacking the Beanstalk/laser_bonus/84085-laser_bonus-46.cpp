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
  vector<vector<int>> grid(N, vector<int>(M, 0));

  for (long long i = 0; i < K; i++) {
    grid[X[i]][Y[i]] = i + 1;
  }

  long long lx = X[0], ly = Y[0];
  bool hit = false;
  lx += Q;
  ly += P;

  lx %= N;
  ly %= M;
  while (!hit) {
    if (grid[lx][ly] > 0) {
      hit = true;
      return grid[lx][ly] - 1;
    } else {
      lx += Q;
      ly += P;

      lx %= N;
      ly %= M;
    }
  }
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
