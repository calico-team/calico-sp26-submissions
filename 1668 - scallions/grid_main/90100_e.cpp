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

const int maxn = 200000;

long long f[maxn + 1], phi[maxn + 1];
bool prime[maxn + 1];

void init(){
    int i, j, k;
    for (i = 2; i <= maxn; ++i) prime[i] = true;
    for (i = 2; i <= maxn; ++i) phi[i] = i;
    phi[1] = 0; prime[1] = false;
    for (i = 2; i <= maxn; ++i)
        if (prime[i]){
            for (j = i; j <= maxn; j += i){
                phi[j] = phi[j] / i * (i - 1);
                if (j > i) prime[j] = false;
            }
        }

    for (i = 2; i <= maxn; ++i)
        if (prime[i]){
            for (j = 2; j * i <= maxn; ++j) f[i * j] += phi[j];
        }

    for (i = 2; i <= maxn; ++i) f[i] += f[i - 1];
}

void work(){
    int Q, x, y, i;
    scanf("%d", &Q);
    for (i = 1; i <= Q; ++i){
        scanf("%d%d", &x, &y);
        printf("%lld\n", f[y] - f[x - 1]);
    }
}

int main() {
    // freopen("e.in", "r", stdin);
    init();
    work();
    return 0;
}