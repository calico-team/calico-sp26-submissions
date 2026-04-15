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

int L, W, E, R;

void init(){
    scanf("%d%d%d%d", &L, &W, &E, &R);
}

void work(){
    printf("%d\n", E / (2 * (L + W) * R));
}

int main() {
    int t, T;
    // freopen("a.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}