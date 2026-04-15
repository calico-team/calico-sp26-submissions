#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> PII;
const int MAXN = 20;
char buf[MAXN][MAXN];
int n, m;
pair<int,int> ans[MAXN][MAXN];

const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int q[MAXN*MAXN][2];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

PII myadd(PII a, PII b) {
    PII s = make_pair(a.first * b.second + b.first * a.second, a.second * b.second);
    int gg = gcd(s.first, s.second);
    s.first /= gg; s.second /= gg;
    return s;
}

PII mydiv(PII a, int k) {
    if (a.first % k == 0) return make_pair(a.first / k, a.second);
    return make_pair(a.first, a.second * k);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n,&m);
        for (int i = 0 ; i < n ; ++i)
            scanf("%s", buf[i]);
        PII cur;
        for (int i = 0 ; i < n ; ++i)
            for (int j = 0 ; j < m ; ++j)
                ans[i][j] = make_pair(0, 1);
        ans[0][0] = make_pair(1, 1);
        q[0][0] = 0; q[0][1] = 0;
        int qh = 0, qt = 1;
        while (qh < qt) {
            int tx = q[qh][0], ty = q[qh][1];
            printf("=== ans[%d][%d]:(%d,%d)\n", tx, ty, ans[tx][ty].first, ans[tx][ty].second);
            ++qh;
            int d = -1;
            if (buf[tx][ty] == '^') {
                d = 0;
            } else if (buf[tx][ty] == 'v') {
                d = 1;
            } else if (buf[tx][ty] == '<') {
                d = 2;
            } else if (buf[tx][ty] == '>') {
                d = 3;
            }
            printf("tx: %d, ty: %d, d: %d\n", tx, ty, d);
            if (d != -1) {
                int nexti = tx + dir[d][0];
                int nextj = ty + dir[d][1];
                if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m) {
                    cur = ans[tx][ty];
                } else {
                    ans[nexti][nextj] = myadd(ans[nexti][nextj], ans[tx][ty]);
                    printf("ans[%d][%d]:(%d,%d)\n", nexti, nextj, ans[nexti][nextj].first, ans[nexti][nextj].second);
                    q[qt][0] = nexti;
                    q[qt][1] = nextj;
                    ++qt;
                }
                continue;
            }
            // S, X
            if (buf[tx][ty] == 'S') {
                vector<int> dests;
                for (int d = 0 ; d < 4 ; ++d) {
                    int tmpx = tx + dir[d][0];
                    int tmpy = ty + dir[d][1];
                    if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) continue;
                    char ch = buf[tmpx][tmpy];
                    if (d == 0 && ch == 'V' || d == 1 && ch == '^' || d == 2 && ch == '>' || d == 3 && ch == '<')
                        continue;
                    if (ch == '.') continue;
                    dests.push_back(d);
                }
                for (int d: dests) {
                    int tmpx = tx + dir[d][0];
                    int tmpy = ty + dir[d][1];
                    ans[tmpx][tmpy] = myadd(ans[tmpx][tmpy], mydiv(ans[tx][ty], dests.size()));
                    q[qt][0] = tmpx;
                    q[qt][1] = tmpy;
                    ++qt;
                }
                continue;
            }
        }
        printf("%d %d\n", cur.first, cur.second);
        for (int i = 0 ; i < n; ++i) {
            for (int j = 0 ; j < m; ++j)
                printf("(%d,%d) ", ans[i][j].first, ans[i][j].second);
            printf("\n");
        }
    }
    return 0;
}