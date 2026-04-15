#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1010;
char a[MAXN][MAXN], b[MAXN][MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0 ; i < n ; i++)
            scanf("%s", &a[i]);
        for (int i = 0 ; i < n ; ++i)
            scanf("%s", &b[i]);
        
        int v1 = 0, v2 = 0;
        for (int L = 0 ; L < n ; ++L) {
            int ca = 0, cb = 0;
            for (int i = 0 ; i < n ; ++i) {
                if (a[L][i] == '#') ++ca;
            }
            for (int i = 0 ; i < n ; ++i) {
                if (b[L][i] == '#') ++cb;
            }
            v1 += n * n - (n - ca) * n - (n - cb) * n + (n - ca) * (n - cb);
            v2 += max(ca, cb);
        }
        printf("%d %d\n", v1, v2);
    }
    return 0;
}