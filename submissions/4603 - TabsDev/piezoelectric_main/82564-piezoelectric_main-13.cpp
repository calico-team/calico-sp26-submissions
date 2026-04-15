#include <iostream>
typedef long long ll;
using namespace std;

int solve(int L, int W, int E, int R) {
	int perim = 2 * (L + W);
	int per_lap = perim * R;
	return E / per_lap;
}

int main() {
	int T; cin >> T;
	while (T--) {
		int L, W, E, R; 
		cin >> L >> W >> E >> R;

		cout << solve(L, W, E, R) << endl;
	}
	return 0;
}