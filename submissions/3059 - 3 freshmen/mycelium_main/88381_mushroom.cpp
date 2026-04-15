#include <bits/stdc++.h>
using namespace std;

/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
const int big = 10000;
int grid[big][big] = {0}; //1 = g, 2 = m
int solve(int X_G, int Y_G, int X_M, int Y_M) {
    queue<pair<int,int>> grass, mush;
    int cnt = 1;
    grass.push({X_G+floor(big/2),Y_G+floor(big/2)});
    mush.push({X_M+floor(big/2),Y_M+floor(big/2)});
    grid[grass.front().first][grass.front().second] = 1;
    grid[mush.front().first][mush.front().second] = 2;
    int order[] = {0,0,0,1,0,0,0,2};
    int i=-1;
    pair<int,int> spacer = {-1,-1};
    grass.push(spacer);
    mush.push(spacer);
    while (mush.size() > 1) {
        i++;
        i%=8;
        if (order[i] != 1) {
            //grass grwo!
            pair<int,int> at = grass.front();
            grass.pop();
            while (at!=spacer) {
                for (int j = 0; j < 4; j ++) {
                    int nextx = at.first + dx[j];
                    int nexty = at.second + dy[j];
                    if (grid[nextx][nexty] == 0) {
                        grid[nextx][nexty] = 1;
                        grass.push({nextx, nexty});
                    }
                }
                at = grass.front();
                grass.pop();
            }
            grass.push(spacer);
            
        }
        if (order[i] != 0) {
            pair<int,int> at = mush.front();
            mush.pop();
            while (at!=spacer) {
                for (int j = 0; j < 4; j ++) {
                    int nextx = at.first + dx[j];
                    int nexty = at.second + dy[j];
                    if (grid[nextx][nexty] == 0) {
                        cnt++;
                        grid[nextx][nexty] = 2;
                        mush.push({nextx, nexty});
                    }
                }
                at = mush.front();
                mush.pop();
            }
            mush.push(spacer);
        }

    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        memset(grid, 0, sizeof(grid));
        int X_G, Y_G, X_M, Y_M;
        cin >> X_G >> Y_G >> X_M >> Y_M;
        cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
    }
}
