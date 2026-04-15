#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string> 
#include <utility>
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
 
int solve(int K, int N, int M, int P, int Q, const unordered_map<long long, int>& asteroids, int sx, int sy) {
  
  long long x = sx, y = sy;
	while(true){
	  
	  x = (x + Q) % N;
	  y = (y + P) % M;
	  long long key = x * M + y;
	  if(asteroids.count(key)){
	    
	    return asteroids.at(key);
	    
	  }
	  
	}
	return 0;
	
}


int main() {
	int T; cin >> T;
	while (T--) {
		int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
		unordered_map<long long, int> asteroids;
		int a, b; cin >> a >> b;
		asteroids[(long long)a * M + b] = 0;
		int startx = a, starty = b;
		for (int i = 1; i < K; i++) {
			int a, b; cin >> a >> b;
			asteroids[(long long)a * M + b] = i;
		}
		cout << solve(K, N, M, P, Q, asteroids, startx, starty) << endl;
	}
	return 0;
}