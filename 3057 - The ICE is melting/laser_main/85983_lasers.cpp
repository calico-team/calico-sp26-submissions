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
    bool hit = false;

    int xcoord = X[0];
    int ycoord = Y[0]; 

    xcoord += Q;
    ycoord += P;

	while (hit == false) {
        for (int i = 0; i < K; i++) {
            if (xcoord == X[i] && ycoord == Y[i]) {
                return i;
            }
        }

        xcoord = (xcoord + Q) % N;
        ycoord = (ycoord + P) % M;

       
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