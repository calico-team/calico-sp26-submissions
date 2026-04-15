#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3;
int T, grid[maxN][maxN], M, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;

    int pos[5][2] = {
        {0, 0},
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1}
    };

    for (int i = 0; i < maxN; i++) {
        memset(grid[i], -1, sizeof(grid[i]));
    }

    for (int i = 0; i < maxN; i++) {
        for (int j = 0; j < maxN; j++) {
            grid[i][j] = (j % 5 + (i * 2) % 5) % 5;
        }
    }

    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (grid[j][k] == -1) cout << 4 << " ";
                else cout << grid[j][k] << " ";
            }
            cout << "\n";
        }
    }
}