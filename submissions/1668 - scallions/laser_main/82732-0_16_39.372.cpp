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

const int maxn = 1005;

int bh[maxn][maxn], m, n, ge, P, Q, x0, yy0;

void init(){
    int i, j, x, y;
    scanf("%d%d%d%d%d", &ge, &m, &n, &Q, &P);
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
            bh[i][j] = -1;

    for (i = 0; i < ge; ++i){
        scanf("%d%d", &x, &y);
        if (i == 0){
            x0 = x; yy0 = y;
        }

        bh[x][y] = i;
    }
}

void work(){
    int i, j, x, y;
    x = x0; y = yy0;
    while (true){
        x = (x + P) % m;
        y = (y + Q) % n;
        if (bh[x][y] != -1){
            printf("%d\n", bh[x][y]);
            return;
        }
    }
}

int main() {
    int t, T;
    // freopen("d.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}