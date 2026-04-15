#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solve(int N, int M) {
    vector<vector<int>> g(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            g[i][j] = (i + 2 * j) % 5;
        }
    }
    return g;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
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
}