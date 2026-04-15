#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
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
    map<pair<int,int>, int> asteroids; // map asteriod to index in the array
    
    for (int i = 0; i < K; i++) {
      pair<int, int> cur_asteroid = {X[i], Y[i]};
      if (asteroids.find(cur_asteroid) == asteroids.end()) { // currently not found
          asteroids[{X[i], Y[i]}] = i; // add it into the map
      }
    }
    
    pair<int, int> cur_pos = {X[0], Y[0]};
    
    while (true) {
      cur_pos.first = (cur_pos.first + Q) % N;
      cur_pos.second = (cur_pos.second + P) % M;
     
      if (asteroids.find(cur_pos) != asteroids.end()) {
        return asteroids[cur_pos]; // if i find the asteroid then i return its index in orig array (stored in map)
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