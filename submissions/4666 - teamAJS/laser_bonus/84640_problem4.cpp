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

int r(int k, int x, int m){
  if(k==0) return 1;
  int a = r(k/2,x,m)%m;
  return ((a*a)%m)*(k%2==0?1:x%m)%m;
}

int inverse(int x, int mod){
  return r(mod - 2,x,mod);
}

bool cansolve(int k, int a, int m) {
  int tK = k;
  int tM = m;
  while (tM != 0) {
    int t = tM;
    tM = tK%tM;
    tK = t;
  }
  return (a%tK==0);
}

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
  int mk = -1;
  int id = -1;
  int x0 = X[0];
  int y0 = Y[0];
  for (int i = 0; i < K; i++) {
    int tx = (X[i]-x0+N)%N;
    int ty = (Y[i]-y0+M)%M;
    if (cansolve(Q, tx, N) && cansolve(P, ty, M)) {
      int kx = -1, ky = -1;
      int tQ = Q, tP = P, tN = N, tM = M;
      while (tN != 0) { int t = tN; tN = tQ%tN; tQ = t; }
      int gX = tQ;
      tN = N; tQ = Q;
      while (tM != 0) { int t = tM; tM = tP%tM; tP = t; }
      int gY = tP;
      int mX = N/gX, mY = M/gY;
      for (int v=0; v<mX; v++) if((v*(Q/gX))%mX == (tx/gX)%mX) { kx = v; break; }
      for (int v=0; v<mY; v++) if((v*(P/gY))%mY == (ty/gY)%mY) { ky = v; break; }
      int k = ky;
      bool hit = false;
      for (int j = 0; j <= mX; j++) {
        if (k%mX == kx) {
          if (i == 0 && k == 0) {
            k += mY;
            if (j == mX) break;
            continue;
          }
          hit = true;
          break;
        }
        k += mY;
      }
      if (hit) {
        if (mk == -1 || k < mk) {
          mk = k;
          id = i;
        }
      }
    }
  }
  return id;
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