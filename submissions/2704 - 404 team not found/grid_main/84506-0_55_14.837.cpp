#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100100;
int a[MAXN];
int n;
set<int> ss;
long long best;
vector<int> bestv;

void solve(int p, vector<int> &v) {
    if (p == n) {
        long long tmp = 0;
        for (int i = 0 ; i < n ; ++i) {
            tmp += abs(v[i] - a[i]);
        }
        for (int i = 0 ; i < n-1 ; ++i) {
            tmp += abs(a[i] - a[i+1]);
            tmp += abs(v[i] - v[i+1]);
        }
        if (best == -1 || tmp < best) {
            best = tmp;
            bestv = v;
        }
        return;
    }
    for (auto tmp: ss) {
        v.push_back(tmp);
        solve(p+1, v);
        v.pop_back();
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ss.clear();
        for (int i = 0 ; i < n ; ++i) {
            scanf("%d", &a[i]);
            ss.insert(a[i]);
        }
        vector<int> v;
        best = -1;
        solve(0, v);
        for (int i = 0 ; i < n ; ++i) {
            if (i) printf(" ");
            printf("%d", bestv[i]);
        }      
        printf("\n");
    }
    return 0;
}