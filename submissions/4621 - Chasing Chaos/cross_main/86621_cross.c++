#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solve(int N, int M) {
    vector<vector<int>> grid(N, vector<int>(M, 0));
    
    int pattern[5][5] = {
        {0, 1, 2, 3, 4},
        {1, 2, 3, 4, 0},
        {2, 3, 4, 0, 1},
        {3, 4, 0, 1, 2},
        {4, 0, 1, 2, 3}
    };
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            grid[i][j] = pattern[i % 5][j % 5];
        }
    }
    
    return grid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> result = solve(N, M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (j > 0) cout << ' ';
                cout << result[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}