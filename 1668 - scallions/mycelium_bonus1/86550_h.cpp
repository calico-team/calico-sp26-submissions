#include <bitset>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

pair<int, int> a[2][2][10000];
int res, old[2], now[2], top[2][2], bx, by;
bitset<6310> done[6310];

void init(){
    int x, y, x1, y1, i, j;
    scanf("%d%d%d%d", &x, &y, &x1, &y1);
    bx = -200 - 2900; by = -200 - 2900;
    for (i = 0; i <= 6300; ++i) done[i].reset();
    now[0] = now[1] = 0;
    a[0][now[0]][0] = {x, y};
    done[x-bx][y-by] = 1;
    a[1][now[1]][0] = {x1, y1};
    done[x1-bx][y1-by] = 1;
    top[0][0] = top[1][0] = 1;
}

void work(){
    int i, j, d, x, y, nx, ny, t, w, tot = 0;
    res = 1;
    for (t = 1; ; ++t){
        // if (t % 100 == 0) printf("%d\n", t);
        for (w = 2, i = 0; w <= 7; w += 5, ++i)
            if (t % w == 0){
                old[i] = now[i]; now[i] = 1 - now[i];
                top[i][now[i]] = 0;
                for (j = 0; j < top[i][old[i]]; ++j){
                    x = a[i][old[i]][j].first; y = a[i][old[i]][j].second;
                    for (d = 0; d < 4; ++d){
                        nx = x + dx[d]; ny = y + dy[d];
                        if (done[nx-bx][ny-by] == 0){
                            done[nx-bx][ny-by] = 1;
                            a[i][now[i]][top[i][now[i]]++] = {nx, ny};
                            if (w == 7) ++res;
                            ++tot;
                        }
                    }
                }

                if (w == 7 && top[i][now[i]] == 0){
                    printf("%d\n", res);
                    return;
                }
            }
    }
}

int main() {
    long long t, T;
    // freopen("h.in", "r", stdin);
    scanf("%lld", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}