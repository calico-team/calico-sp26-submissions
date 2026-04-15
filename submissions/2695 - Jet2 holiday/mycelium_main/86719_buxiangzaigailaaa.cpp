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

int main()
{

    int T;
    cin >> T;
    while (T--) {

        memset(grid, 0, sizeof(grid));
        queue<Point> q1, q2;

        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        xg += OFFSET; yg += OFFSET;
        xm += OFFSET; ym += OFFSET;


        grid[xg][yg] = 1;
        q1.push({xg, yg});

        grid[xm][ym] = 2;
        q2.push({xm, ym});



        int tick = 0;
        int cnt = 1;

        while (!q1.empty() || !q2.empty()) {
            tick++;

            bool grass_ok = (tick % 2 == 0);
            bool myce_ok = (tick % 7 == 0);

            // 草生长
            if (grass_ok) {
                int sz = q1.size();
                for (int i = 0; i < sz; i++) {
                    auto p = q1.front(); q1.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];
                        if (nx >=0 && nx < MAXN && ny >=0 && ny < MAXN && grid[nx][ny] == 0) {
                            grid[nx][ny] = 1;
                            q1.push({nx, ny});
                        }
                    }
                }
            }






            // 菌丝生长
            if (myce_ok) {
                int sz = q2.size();
                for (int i = 0; i < sz; i++) {
                    auto p = q2.front(); q2.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];
                        if (nx >=0 && nx < MAXN && ny >=0 && ny < MAXN) {
                            if (grid[nx][ny] == 0) {
                                grid[nx][ny] = 2;
                                q2.push({nx, ny});
                                cnt++;
                            } else if (grid[nx][ny] == 1 && grass_ok) {
                                q2.push(p);
                            } else {
                                q2.push(p);
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}