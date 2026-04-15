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

const int maxn = 1000000;
// const int maxn = 100;

long long m, n, ge, P, Q, x0, yy0, phi[maxn+1];
bool prime[maxn+1];

void calc_phi(){
    int i, j;
    for (i = 1; i <= maxn; ++i) phi[i] = i;
    for (i = 1; i <= maxn; ++i) prime[i] = true;
    prime[1] = false;
    for (i = 2; i <= maxn; ++i) 
        if (prime[i]){
            for (j = i; j <= maxn; j += i){
                if (j > i) prime[j] = false;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
}

void init(){
    scanf("%lld%lld%lld%lld%lld", &ge, &m, &n, &Q, &P);
}

long long cheng(long long a, long long x, long long mo){
    long long b = 1;
    a %= mo;
    // in case mo == 1, needs to remove x %= mo - 1
    // x %= mo - 1; // not mo!!!!!!!!
    while (x){
        if (x % 2 == 1) {
            b = (b * a) % mo;
        }
        a = (a * a) % mo;
        x /= 2;
    }
    
    return b % mo; // in case mo == 1
}

long long gcd(long long a, long long b){
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

bool ky(long long P, long long x, long long m, long long &a, long long &X){    
    long long d = gcd(P, m);
    if (x % d != 0) return false;
    P /= d; m /= d; x /= d;

    if (x < 0){
        x += (-x) / m * m;
        while (x < 0) x += m;
    }

    x %= m;
    X = m;
    if (m == 1){
        if (x == 0){
            a = 0;
            return true;
        }
        else return false;
    }

    long long fP = cheng(P, phi[m] - 1, m);
    a = (1LL * fP * x) % m;
    return true;
}

void work(){
    long long i, x, y, a, b, c, X, Y, Z, cand, res, id = -1;
    for (i = 0; i < ge; ++i){
        scanf("%lld%lld", &x, &y);
        if (i == 0){
            x0 = x; yy0 = y;
        }

        // tP = (x - x0) (mod m)
        if (!ky(P, x - x0, m, a, X)) continue;
        // tQ = (y - y0) (mod n)
        if (!ky(Q, y - yy0, n, b, Y)) continue;

        // t = a + Xu = b + Yv
        if (!ky(X, b - a, Y, c, Z)) continue;
        cand = a + c * X;
        if (cand == 0) cand = a + (c + Z) * X;
        if (id == -1 || (cand < res)){
            res = cand;
            id = i;
        }
    }

    printf("%lld\n", id);
}

int main() {
    long long t, T;
    calc_phi();
    // freopen("d.in", "r", stdin);
    scanf("%lld", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}