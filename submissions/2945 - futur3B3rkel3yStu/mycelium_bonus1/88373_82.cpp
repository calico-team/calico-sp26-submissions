#include <bits/stdc++.h>
using namespace std;
int ditu[805][805], offset = 400;
struct Dian { int x, y; };
void solve() {
    int xg, yg, xm, ym;
    if (scanf("%d %d %d %d", &xg, &yg, &xm, &ym) != 4) return;
    memset(ditu, 0, sizeof(ditu));
    queue<Dian> q_cao, q_junsi;
    q_cao.push({xg + offset, yg + offset});
    q_junsi.push({xm + offset, ym + offset});
    ditu[xg + offset][yg + offset] = 1;
    ditu[xm + offset][ym + offset] = 2;
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    for (int t = 1; t <= 1500; t++) {
        if (t % 2 != 0 && t % 7 != 0) continue;
        vector<Dian> n_junsi;
        if (t % 7 == 0) {
            int sz = q_junsi.size();
            while (sz--) {
                Dian p = q_junsi.front(); q_junsi.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = p.x + dx[i], ny = p.y + dy[i];
                    if (nx >= 0 && nx < 800 && ny >= 0 && ny < 800 && ditu[nx][ny] == 0) {
                        ditu[nx][ny] = 3;
                        n_junsi.push_back({nx, ny});
                    }
                }
                q_junsi.push(p); 
            }
        }
        if (t % 2 == 0) {
            int sz = q_cao.size();
            while (sz--) {
                Dian p = q_cao.front(); q_cao.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = p.x + dx[i], ny = p.y + dy[i];
                    if (nx >= 0 && nx < 800 && ny >= 0 && ny < 800) {
                        if (ditu[nx][ny] == 0 || ditu[nx][ny] == 3) {
                            ditu[nx][ny] = 1;
                            q_cao.push({nx, ny});
                        }
                    }
                }
            }
        }
        for (auto &p : n_junsi) {
            if (ditu[p.x][p.y] == 3) {
                ditu[p.x][p.y] = 2;
                q_junsi.push(p);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 800; i++)
        for (int j = 0; j < 800; j++)
            if (ditu[i][j] == 2) res++;
    printf("%d\n", res);
}
int main() {
    int t_cases;
    if (scanf("%d", &t_cases) == 1)
        while (t_cases--) solve();
    return 0;
}