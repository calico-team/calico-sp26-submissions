#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solve(int N, int M) {
    vector<vector<int>> quilt_map(N, vector<int>(M, 0));
    for (int row_pick = 0; row_pick < N; row_pick++) {
        for (int col_pick = 0; col_pick < M; col_pick++) {
            quilt_map[row_pick][col_pick] = (row_pick + 2 * col_pick) % 5;
        }
    }
    return quilt_map;
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
                if (j) cout << ' ';
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}