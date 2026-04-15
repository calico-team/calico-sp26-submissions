#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solve(int N, int M) {
    vector<vector<int>> grid(N, vector<int>(M, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = 2;
                }
            } else {
                if (j % 2 == 0) {
                    grid[i][j] = 1;
                } else {
                    grid[i][j] = 3;
                }
            }
        }
    }
    
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            int up = grid[i-1][j];
            int down = grid[i+1][j];
            int left = grid[i][j-1];
            int right = grid[i][j+1];
            int center = grid[i][j];
            
            bool bad = false;
            int seen[5] = {0};
            seen[center] = 1;
            seen[up] = 1;
            seen[down] = 1;
            seen[left] = 1;
            seen[right] = 1;
            
            for (int k = 0; k < 5; k++) {
                if (!seen[k]) {
                    bad = true;
                    break;
                }
            }
            
            if (!bad) continue;
            
            for (int try_center = 0; try_center < 5; try_center++) {
                int try_seen[5] = {0};
                try_seen[try_center] = 1;
                try_seen[up] = 1;
                try_seen[down] = 1;
                try_seen[left] = 1;
                try_seen[right] = 1;
                
                bool ok = true;
                for (int k = 0; k < 5; k++) {
                    if (!try_seen[k]) {
                        ok = false;
                        break;
                    }
                }
                
                if (ok) {
                    grid[i][j] = try_center;
                    break;
                }
            }
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