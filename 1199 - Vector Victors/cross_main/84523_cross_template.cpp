#include <iostream>
#include <vector>
using namespace std;

/*
 * Create an N x M grid such that every valid cross contains 0-4 exactly once.
 * 
 * N: number of rows in the grid
 * M: number of columns in the grid
 */
vector<vector<int>> solve(int N, int M) {
	// YOUR CODE HERE
	vector<vector<int>> answer(N, vector<int>(M, 0));

	for (long i = 0; i < N; i++){
		for (long j = 0; j < M; j++){
			answer[i][j] = (2*i + j) % 5;
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<vector<int>> grid = solve(N, M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (j > 0) cout << ' ';
				cout << grid[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
