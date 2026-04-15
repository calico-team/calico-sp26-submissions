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

const int maxn = 2005;

int a[maxn][maxn], s[maxn][maxn], m, n, K;
char row[maxn];

void init(){
    int i, j;
    scanf("%d%d%d", &m, &n, &K);
    for (i = 0; i < m + n; ++i)
        for (j = 0; j < m + n; ++j)
            a[i][j] = 0;
    for (i = 0; i < m; ++i){
        scanf("%s", row);
        for (j = 0; j < n; ++j)
            if (row[j] == '-')
                a[i + j][i - j + n] = 1;
    }
}

void calc_s(){
    int i, j, now;
    for (i = 0; i < m + n; ++i){
        now = 0;
        for (j = 0; j < m + n; ++j){
            now += a[i][j];
            s[i][j] = now;
            if (i > 0) s[i][j] += s[i - 1][j];
        }
    }
}

void work(){
    int st, ed, mid, D, sx, sy, x, y, qx, qy, t;
    calc_s();
    st = 0; ed = m + n;
    while (st <= ed){
        mid = (st + ed) / 2;
        bool yes = false;
        for (x = 0; x < m + n && !yes; ++x)
            for (y = 0; y < m + n && !yes; ++y){
                qx = min(x + mid, m + n - 1);
                qy = min(y + mid, m + n - 1);
                t = s[qx][qy];
                if (y > 0) t -= s[qx][y - 1];
                if (x > 0) t -= s[x - 1][qy];
                if (x > 0 && y > 0) t += s[x - 1][y - 1];
                if (t >= K){
                    yes = true;
                    sx = x; sy = y;
                    D = mid;
                }
            }

        if (yes) ed = mid - 1;
        else st = mid + 1;
    }

    int ge = 0;
    for (x = sx; x <= sx + D && x < m + n; ++x)
        for (y = sy; y <= sy + D && y < m + n; ++y)
            if (a[x][y] && ge < K){
                ++ge;
                printf("%d %d\n", (x + y - n) / 2, (x - (y - n)) / 2);
            }
}

int main() {
    int t, T;
    // freopen("k.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}