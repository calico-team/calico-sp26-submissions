#include <bits/stdc++.h>

using namespace std;

const int OFFSET = 50;
const int SIZE = 100;
int grid[SIZE][SIZE];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Point {
    int x, y;
};

Point grass_q[SIZE * SIZE], next_grass_q[SIZE * SIZE];
Point mycelium_q[SIZE * SIZE], next_mycelium_q[SIZE * SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int xG, yG, xM, yM;
        cin >> xG >> yG >> xM >> yM;

        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                grid[i][j] = 0;

        int g_cnt = 1, m_cnt = 1;
        grass_q[0] = {xG + OFFSET, yG + OFFSET};
        mycelium_q[0] = {xM + OFFSET, yM + OFFSET};
        grid[xG + OFFSET][yG + OFFSET] = 1;
        grid[xM + OFFSET][yM + OFFSET] = 2;

        int total_mycelium = 1;

        for (int tick = 1; tick <= 1000; tick++) {
            if (tick % 2 == 0) {
                int next_g_cnt = 0;
                for (int i = 0; i < g_cnt; i++) {
                    for (int d = 0; d < 4; d++) {
                        int nx = grass_q[i].x + dx[d], ny = grass_q[i].y + dy[d];
                        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && grid[nx][ny] == 0) {
                            grid[nx][ny] = 1;
                            next_grass_q[next_g_cnt++] = {nx, ny};
                        }
                    }
                }
                g_cnt = next_g_cnt;
                for (int i = 0; i < g_cnt; i++) grass_q[i] = next_grass_q[i];
            }

            if (tick % 7 == 0) {
                int next_m_cnt = 0;
                for (int i = 0; i < m_cnt; i++) {
                    for (int d = 0; d < 4; d++) {
                        int nx = mycelium_q[i].x + dx[d], ny = mycelium_q[i].y + dy[d];
                        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            next_mycelium_q[next_m_cnt++] = {nx, ny};
                            total_mycelium++;
                        }
                    }
                }
                m_cnt = next_m_cnt;
                for (int i = 0; i < m_cnt; i++) mycelium_q[i] = next_mycelium_q[i];
                if (m_cnt == 0) break;
            }
        }
        cout << total_mycelium << endl;
    }
    return 0;
}