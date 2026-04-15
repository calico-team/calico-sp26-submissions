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

    for (auto & i : grid) {
        memset(i, -1, sizeof(i));
    }

    for (int i = 1; i < maxN - 1; i++) {
        for (int j = 1; j < maxN - 1; j++) {
            bool curr[5] = {};
            for (auto p : pos) {
                if (grid[i + p[1]][j + p[0]] != -1) {
                    curr[grid[i + p[1]][j + p[0]]] = true;
                }
            }
            for (auto p : pos) {
                if (grid[i + p[1]][j + p[0]] == -1) {
                    for (int k = 0; k < 5; k++) {
                        if (!curr[k]) {
                            curr[k] = true;
                            grid[i + p[1]][j + p[0]] = k;
                            break;
                        }
                    }
                }
            }
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