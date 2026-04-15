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
 
const int maxn = 10005;

int n, P, R, K, a[maxn];

void init(){
    int i;
    scanf("%d%d%d%d", &n, &P, &R, &K);
    for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
}

void work(){
    int cnt = 0, i;
    for (i = 1; i <= n; ++i){
        P -= a[i];
        if (P < 0){
            printf("nah i'd lose\n");
            return;
        }

        if (++cnt == K){
            cnt = 0;
            P += R;
        }
    }

    printf("nah i'd win\n");
}

int main() {
    int t, T;
    // freopen("b.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}