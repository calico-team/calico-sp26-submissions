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
	pair<int,int> loc = {X[0],Y[0]};
    while (true){
        loc.first += Q;
        loc.second += P;
        loc.first = loc.first % N;
        loc.second = loc.second % M;
        //cout << loc.first << ' ' << loc.second << endl;
        for (int i = 0; i < K; i++){
            if (X[i] == loc.first and Y[i] == loc.second){
                return i;
            } 
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