#include <iostream>
#include <vector>
using namespace std;

/*
 * Create an N x M grid such that every valid cross contains 0-4 exactly once.
 * 
 * N: number of rows in the grid
 * M: number of columns in the grid
 */
vector<int> dirx = {0, 1, 0, -1};
vector<int> diry = {1, 0, -1, 0};

vector<vector<int>> solve(int N, int M) {
    vector<vector<int>> v(N, vector<int>(M, -1));
    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < M - 1; j++){
            if(v[i][j] == -1){
                v[i][j] = 0;
            }
            vector<bool> used(5, false);
            used[v[i][j]] = true;
            for(int k = 0; k < 4; k++){
                int x = i + dirx[k];
                int y = j + diry[k];
                if(v[x][y] != -1){
                    used[v[x][y]] = true;
                    continue;
                }
            }
            for(int k = 0; k < 4; k++){
                int x = i + dirx[k];
                int y = j + diry[k];
                if(v[x][y] == -1){
                    for(int n = 0; n <= 4; n++){
                        if(!used[n]){
                            v[x][y] = n;
                            used[n] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(v[i][j] == -1){
                v[i][j] = 0;
            }
        }
    }
    return v;
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
