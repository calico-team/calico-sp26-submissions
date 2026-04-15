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

long long P, A, B;
int len, p3[105], p2[105];
char a[3][2000];


void init(){
    scanf("%lld%lld%lld", &P, &A, &B);
}

void work(){
    long long i, j, k, W = 0, p, mi;
    len = 2 * (A + B) + 1;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < len; ++j) 
            a[i][j] = '.';
    a[0][0] = 'v';
    p = 0;
    for (i = 1; i <= B; ++i){
        a[1][p++] = '>';
        a[1][p] = 'S';
        a[0][p] = a[2][p] = 'X';
        p3[i] = p;
        ++p;
    }

    for (i = 1; i <= A; ++i){
        a[1][p++] = '>';
        a[1][p] = 'S';
        a[2][p] = 'X';
        p2[i] = p;
        ++p;
    }
    
    a[1][p] = 'X';

    for (mi = 0; P; P /= 2, ++mi){
        if (P % 2 == 1){
            // 1/(2^(A-mi)3^B)
            if (A - mi >= 1) a[2][p2[A - mi]] = 'v';
            else W += (1LL<<(mi - A));
        }
    }

    for (mi = 0; W; W /= 3, ++mi){
        if (W % 3 == 1){
            // 1 / (3^(B - mi))
            a[2][p3[B - mi]] = 'v';
        }
        if (W % 3 == 2){
            // 2 / (3^(B - mi))
            a[0][p3[B - mi]] = '^';
            a[2][p3[B - mi]] = 'v';
        }
    }

    printf("%d %d\n", 3, len);
    for (i = 0; i < 3; ++i){
        for (j = 0; j < len; ++j) printf("%c", a[i][j]);
        printf("\n");
    }
}

int main() {
    int t, T;
    // freopen("j.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}