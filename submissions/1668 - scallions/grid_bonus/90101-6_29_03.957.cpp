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

const int maxn = 100005;
int n, a[maxn];

void init(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
}

void work(){
    int i;
    for (i = 2; i < n; ++i){
        if (a[i] < a[i + 1] && a[i] < a[i - 1]) a[i] = min(a[i + 1], a[i - 1]);
        if (a[i] > a[i + 1] && a[i] > a[i - 1]) a[i] = max(a[i + 1], a[i - 1]);
    }
    for (i = 1; i <= n; ++i){
        printf("%d", a[i]);
        if (i == n) printf("\n");
        else printf(" ");
    }
}

int main() {
    int t, T;
    // freopen("e.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}