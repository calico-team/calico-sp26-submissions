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

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
	set<pair<int,int> > s;
	for(int i=0;i<K;i++){
		s.insert(make_pair(X[i],Y[i]));
	}
	int xcoor=X[0]+Q,ycoor=Y[0]+P,x0=X[0],y0=Y[0];
	while(!(xcoor==x0&&ycoor==y0)){
		if(s.count(make_pair(xcoor,ycoor))){
			for(int i=0;i<K;i++){
				if(xcoor==X[i]&&ycoor==Y[i]){
					return i;
				}
			}
		}
		xcoor+=Q;xcoor%=N;
		ycoor+=P;ycoor%=M;
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
