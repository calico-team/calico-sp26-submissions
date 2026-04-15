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
    //cout<<"HI";
	vector<vector<int>> v;
	vector<int>c;
	for(int i = 0; i<N; i++){
	    for(int j = 0; j<M; j++){
	        c.push_back(0);
	    }
	    v.push_back(c);
	    c.clear();
	}
	for(int i = 0; i<X.size(); i++){
	    v[X[i]][Y[i]] = 1;
	}
	int a = X[0];
	int b = Y[0];
	int e;
	int d;
	while(true){
	    a+=Q;
	    b+=P;
	    if(a>=N) a-=N;
	    if(b>=M) b-=M;
	    if(v[a][b] == 1){
	        e = a;
	        d = b;
	        break;
	    }
	}
	for(int i = 0; i<X.size(); i++){
	    if (e==X[i] && d == Y[i]) return i;
	}
	for(int i = 0; i<N; i++){
	    for(int j = 0; j<M; j++){
	        cout<<v[i][j];
	    }
	    cout<<endl;
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