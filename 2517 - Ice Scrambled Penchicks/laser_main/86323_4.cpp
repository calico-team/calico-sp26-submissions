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

//https://cp-algorithms.com/algebra/module-inverse.html
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int mmi(int a, int m){
    int x, y;
    int g = gcd(a, m, x, y);
    if (g != 1) {
        return -1;
    }
    else {
    x = (x % m + m) % m;
    }
   return x;
}
struct Congruence {
    long long a, m;
};
long long crt(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mmi(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
	// YOUR CODE HERE
    vector<vector<bool> > seen(N, vector<bool>(M, false));

    int x0 = X[0];
    int y0 = Y[0];

    while(!seen[x0][y0]){
        seen[x0][y0] = true;

        //cout << x0 << "," << y0 << "\n";

        for(int i= 1; i<X.size(); i++){
            if(X[i] == x0 && Y[i] == y0){
                //cout << "ans: " << i << "\n";
                return i;
            }
        }

        
        x0 = (x0 + Q) % N;
        y0 = (y0 + P) % M;
    }
    //cout << 0;
    return 0;

	//return 0;
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