#include <iostream>
#include <vector>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
	long long max_vol = 0;
	long long min_vol = 0;

	for (int z = 0; z < N; z++) {
		long long s1 = 0;
		long long s2 = 0;

		for (int x = 0; x < N; x++) {
			if (S1[z][x] == '#') {
				s1++;
			}
		}
		for (int y = 0; y < N; y++) {
			if (S2[z][y] == '#') {
				s2++;
			}
		}

		max_vol += s1 * s2;
		min_vol += max(s1, s2);
	}

	return to_string(max_vol) + " " + to_string(min_vol);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<string> S1(N);
		for (int i = 0; i < N; i++) {
			cin >> S1[i];
		}
		vector<string> S2(N);
		for (int i = 0; i < N; i++) {
			cin >> S2[i];
		}
		cout << solve(N, S1, S2) << '\n';
	}
}
