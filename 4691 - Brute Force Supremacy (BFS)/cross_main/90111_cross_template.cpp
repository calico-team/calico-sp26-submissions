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
    vector<vector<int>> ans(N, vector<int>(M, -1));
    vector<pair<int,int>> neighbors = {{-1,0},{0,1},{0,-1},{1,0}};
    ans[1][1] = 0;
    ans[0][0] = 0;
    ans[0][M-1] = 0;
    ans[N-1][0] = 0;
    ans[N-1][M-1] = 0;
    vector<vector<int>> n = {{1,2,3,4},{2,3,4,0},{3,4,0,1},{4,0,1,2},{0,1,2,3}};

    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            for (int k = 0; k < 4; k++) {
                auto [dx, dy] = neighbors[k];
                ans[i+dx][j+dy] = n[ans[i][j]][k];
            }
        }
    }

return ans;
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
