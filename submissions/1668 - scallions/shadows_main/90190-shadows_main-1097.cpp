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
int n, a[maxn], b[maxn];
char s[maxn];

void init(){
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i){
        scanf("%s", s);
        a[i] = 0;
        for (j = 0; j < n; ++j)
            if (s[j] == '#') ++a[i];
    }

    for (i = 1; i <= n; ++i){
        scanf("%s", s);
        b[i] = 0;
        for (j = 0; j < n; ++j)
            if (s[j] == '#') ++b[i];
    }
}

void work(){
    int i, zx = 0, zd = 0;
    for (i = 1; i <= n; ++i){
        zd += a[i] * b[i];
        zx += max(a[i], b[i]);
    }

    printf("%d %d\n", zd, zx);
}

int main() {
    int t, T;
    // freopen("f.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}