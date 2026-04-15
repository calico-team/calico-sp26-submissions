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

int m, n, a[maxn][maxn];

void init(){
    scanf("%d%d", &m, &n);
}

void work(){
    int i, j, num, d;
    for (i = 1; i <= m; ++i){
        num = ((i - 1) * 2) % 5;
        for (j = 1; j <= n; ++j){
            printf("%d", num);
            if (j == n) printf("\n");
            else printf(" ");
            num = (num + 1) % 5;
        }
    }
}

int main() {
    int t, T;
    // freopen("g.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}