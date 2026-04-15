#include <iostream>
using namespace std;

int solve(int L, int W, int E, int R) {
	int p = 2 * L + 2 * W;
	int perLap = R * p;
	return E / perLap + (E % perLap == 0 ? 0 : 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		int L, W, E, R; 
		cin >> L >> W >> E >> R;
		cout << solve(L, W, E, R) << "\n";
	}
}