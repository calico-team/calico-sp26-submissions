#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct block {
    int time;
    int x, y;
};
/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */
int type[201][201];  // 0 no; 1 grass; 2 m
int takeAt[201][201];
int dxdy[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int solve(int X_G, int Y_G, int X_M, int Y_M) {

    for(int i = 0;i<21;i++){
        for(int j =0;j<21;j++){
            type[i][j]=0;
            takeAt[i][j]=-1;
        }
    }

    X_G += 100;
    Y_G += 100;
    X_M += 100;
    Y_M += 100;
    queue<block> g;
    queue<block> m;
    g.push({0, X_G, Y_G});
    m.push({0, X_M, Y_M});
    int t = -1;
    int res = 0;
    while (!m.empty()) {
        t++;
        block cur = m.front();

        while (!m.empty()) {
            cur = m.front();
            if (cur.time != t) {
                break;
            }
            m.pop();
            if (type[cur.x][cur.y] == 0) {
                takeAt[cur.x][cur.y] = t;
                type[cur.x][cur.y] = 2;
                // cout << cur.x << " " << cur.y << endl;
                res++;
                for (int i = 0; i < 4; i++) {
                    int x = cur.x + dxdy[i][0];
                    int y = cur.y + dxdy[i][1];
                    if(x<0||x>200||y<0||y>200){
                        continue;
                    }
                    if (type[x][y] == 0) {
                        m.push({cur.time + 7, x, y});
                        // cout << "push" << endl;
                    }
                }
            }
        }

        // grass

        while (!g.empty()) {
            // cout<<1<<endl;
            cur = g.front();
            if (cur.time != t) {
                break;
            }
            g.pop();
            if (type[cur.x][cur.y] == 0) {
                takeAt[cur.x][cur.y] = t;
                type[cur.x][cur.y] = 1;
                for (int i = 0; i < 4; i++) {
                    int x = cur.x + dxdy[i][0];
                    int y = cur.y + dxdy[i][1];
                    if(x<0||x>200||y<0||y>200){
                        continue;
                    }
                    if (type[x][y] == 0) {
                        g.push({cur.time + 2, x, y});
                    }
                }
            }
            if (type[cur.x][cur.y] == 2 && takeAt[cur.x][cur.y] == t) {
                res--;
                takeAt[cur.x][cur.y] = t;
                type[cur.x][cur.y] = 1;
                for (int i = 0; i < 4; i++) {
                    int x = cur.x + dxdy[i][0];
                    int y = cur.y + dxdy[i][1];
                    if(x<0||x>200||y<0||y>200){
                        continue;
                    }
                    if (type[x][y] == 0) {
                        g.push({cur.time + 2, x, y});
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int X_G, Y_G, X_M, Y_M;
        cin >> X_G >> Y_G >> X_M >> Y_M;
        cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
    }
}
