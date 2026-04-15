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
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int solve(int K, int N, int M, int P, int Q, vector<int> X, vector<int> Y) {
    unordered_map<ll, int> mp;

    for (int i = 0; i < K; i++) {
        ll key = (ll)X[i] * M + Y[i];
        mp[key] = i;
    }

    int x = X[0];
    int y = Y[0];

    int cycle = lcm(N / gcd(Q, N), M / gcd(P, M));

    for (int step = 0; step < cycle; step++) {
        x = (x + Q) % N;
        y = (y + P) % M;

        ll key = (ll)x * M + y;
        if (mp.count(key)) {
            return mp[key];
        }
    }

    return -1;
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