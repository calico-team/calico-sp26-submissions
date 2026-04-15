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

char a[150], b[150];

void init(){
    scanf("%s%s", a, b);
}

void work(){
    int i, p = 0, len = strlen(b);
    for (i = 0; i < len; ++i){
        while (a[p] != b[i]) a[p++] = '#';
        ++p;
    }

    len = strlen(a);
    while (p < len) a[p++] = '#';

    printf("%s\n", a);
}

int main() {
    int t, T;
    // freopen("c.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}