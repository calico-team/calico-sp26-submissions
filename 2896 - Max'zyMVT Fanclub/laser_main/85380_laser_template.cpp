#include <bits/stdc++.h>
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
int solve(int k, int n, int m, int p, int q, vector<int> x, vector<int> y) {
	int currx=x[0],curry=y[0];
	set<pair<int,int>> s;
	for (int i=0;i<k;i++) {
		s.insert({x[i],y[i]});
	}
	do {
		currx+=q,curry+=p;
		currx%=n,curry%=m;
		if (s.count({currx,curry})) {
			for (int i=0;i<k;i++) {
				if (x[i]==currx&&y[i]==curry) {
					return i;
				}
			}
		}
	}
	while(currx!=x[0]||curry!=y[0]);
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