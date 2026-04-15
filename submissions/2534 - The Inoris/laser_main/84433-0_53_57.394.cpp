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
	
    int x_a=X[0],y_a=Y[0];

    while(true)
    {
        x_a=(x_a+Q)%N;
        y_a=(y_a+P)%M;


        for(int i=0;i<K;i++)
        {
            if(X[i]==x_a&&Y[i]==y_a)
            {
                return i;
            }
        }
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