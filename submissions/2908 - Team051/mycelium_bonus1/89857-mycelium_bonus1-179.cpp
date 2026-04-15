#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
const int OFFSET = 500;
int grid[MAX][MAX];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int XG, YG, XM, YM;
        cin >> XG >> YG >> XM >> YM;
        memset(grid, 0, sizeof(grid));
        int gx = XG + OFFSET, gy = YG + OFFSET;
        int mx = XM + OFFSET, my = YM + OFFSET;
        grid[gx][gy] = 1;
        grid[mx][my] = 2;
        const int MAX_TICKS = 500;
        for (int tick = 1; tick <= MAX_TICKS; ++tick) {
            if (tick % 2 == 0) {
                vector<pair<int,int>> nuevas;
                for (int i = 0; i < MAX; ++i) {
                    for (int j = 0; j < MAX; ++j) {
                        if (grid[i][j] == 1) {
                            for (int d = 0; d < 4; ++d) {
                                int ni = i + dx[d], nj = j + dy[d];
                                if (ni >= 0 && ni < MAX && nj >= 0 && nj < MAX && grid[ni][nj] == 0) {
                                    nuevas.push_back({ni, nj});
                                }
                            }
                        }
                    }
                }
                for (auto& p : nuevas) {
                    if (grid[p.first][p.second] == 0) grid[p.first][p.second] = 1;
                }
            }
            if (tick % 7 == 0) {
                vector<pair<int,int>> nuevas;
                for (int i = 0; i < MAX; ++i) {
                    for (int j = 0; j < MAX; ++j) {
                        if (grid[i][j] == 2) {
                            for (int d = 0; d < 4; ++d) {
                                int ni = i + dx[d], nj = j + dy[d];
                                if (ni >= 0 && ni < MAX && nj >= 0 && nj < MAX && grid[ni][nj] == 0) {
                                    nuevas.push_back({ni, nj});
                                }
                            }
                        }
                    }
                }
                for (auto& p : nuevas) {
                    if (grid[p.first][p.second] == 0) grid[p.first][p.second] = 2;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                if (grid[i][j] == 2) total++;
        
        cout << total << endl;
    }
    return 0;
}