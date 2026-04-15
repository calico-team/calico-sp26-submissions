#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		ll P, A, B;
		cin >> P >> A >> B;

		vector<int> twos(A), threes(B);
		for (int i = 0; i < A; i++) {
			twos[i] = P % 2;
			P /= 2;
		}
		for (int i = 0; i < B; i++) {
			threes[i] = P % 3;
			P /= 3;
		}

		vector<string> grid {".v."};
		while (threes.size()) {
			string line = "XSX";
			if (threes.back() == 2)
				line = "<S>";
			else if (threes.back() == 1)
				line[0] = '<';
			threes.pop_back();
			grid.push_back(line);
			grid.push_back(".v.");
		}
		while (twos.size()) {
			string line = "XS.";
			if (twos.back() == 1)
				line[0] = '<';
			twos.pop_back();
			grid.push_back(line);
			grid.push_back(".v.");
		}
		grid.back()[1] = 'X';

		int N = grid.size(), M = grid[0].size();
		cout << N << ' ' << M << '\n';
		for (int i = 0; i < N; i++)
			cout << grid[i] << '\n';
	}
}
