#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

const int OFFSET = 500;
const int MAXN = 1000;
int grid[MAXN][MAXN]; // 0 empty, 1 grass, 2 mycelium

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        memset(grid, 0, sizeof(grid));
        queue<Point> q_grass, q_mycelium;

        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        xg += OFFSET; yg += OFFSET;
        xm += OFFSET; ym += OFFSET;

        grid[xg][yg] = 1;
        q_grass.push({xg, yg});

        grid[xm][ym] = 2;
        q_mycelium.push({xm, ym});

        int tick = 0;
        int cnt = 1; // 初始菌丝块

        while (!q_grass.empty() || !q_mycelium.empty()) {
            tick++;

            bool grass_turn = (tick % 2 == 0);
            bool myce_turn  = (tick % 7 == 0);

            //草扩张 
            if (grass_turn) {
                int sz = q_grass.size();
                for (int i = 0; i < sz; i++) {
                    Point p = q_grass.front(); q_grass.pop();
                    bool has_empty = false;
                    for (int d = 0; d < 4; d++) {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];
                        if (nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN) {
                            if (grid[nx][ny] == 0) {
                                grid[nx][ny] = 1;
                                q_grass.push({nx, ny});
                                has_empty = true; // 成功占领，同时说明原块周围曾有（现在已不是）空地
                            } 
                        }
                    }
                   
                    // 简便判断：只要周围存在任意空地，就保留原块
                    bool keep = false;
                    for (int d = 0; d < 4; d++) {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];
                        if (nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN) {
                            if (grid[nx][ny] == 0) {
                                keep = true;
                                break;
                            }
                        }
                    }
                    if (keep) q_grass.push(p);
                }
            }

            // ---------- 菌丝扩张 ----------
            if (myce_turn) {
                int sz = q_mycelium.size();
                for (int i = 0; i < sz; i++) {
                    Point p = q_mycelium.front(); q_mycelium.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];
                        if (nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN) {
                            if (grid[nx][ny] == 0) {
                                grid[nx][ny] = 2;
                                q_mycelium.push({nx, ny});
                                cnt++;
                            }
                            // 如果是草且草在同一 tick 扩张，则草优先，菌丝不占领（什么都不做）
                        }
                    }
                    bool keep = false;
                    for (int d = 0; d < 4; d++) {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];
                        if (nx >= 0 && nx < MAXN && ny >= 0 && ny < MAXN) {
                            if (grid[nx][ny] == 0) {
                                keep = true;
                                break;
                            }
                        }
                    }
                    if (keep) q_mycelium.push(p);
                }
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}