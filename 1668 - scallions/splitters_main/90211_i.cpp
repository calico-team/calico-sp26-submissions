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

const int maxn = 20;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// .: -1, S: 4, X: 5
int m, n, a[maxn][maxn], indeg[maxn][maxn];
bool done[maxn][maxn];
vector<pair<int, int> > g[maxn][maxn];
pair<long long, long long> f[maxn][maxn], res;

void init(){
    int i, j;
    char s[maxn];
    scanf("%d%d", &m, &n);
    for (i = 1; i <= m; ++i){
        scanf("%s", s + 1);
        for (j = 1; j <= n; ++j){
            if (s[j] == '^') a[i][j] = 0;
            if (s[j] == '<') a[i][j] = 1;
            if (s[j] == 'v') a[i][j] = 2;
            if (s[j] == '>') a[i][j] = 3;
            if (s[j] == '.') a[i][j] = -1;
            if (s[j] == 'S') a[i][j] = 4;
            if (s[j] == 'X') a[i][j] = 5;
        }
    }
}

void calc_deg(){
    int d, x, y, nx, ny;
    for (x = 1; x <= m; ++x)
        for (y = 1; y <= n; ++y){
            g[x][y].clear();
            indeg[x][y] = 0;
            done[x][y] = false;
        }

    for (x = 1; x <= m; ++x)
        for (y = 1; y <= n; ++y){
            if (a[x][y] == -1 || a[x][y] == 5) continue;
            for (d = 0; d < 4; ++d){
                if (a[x][y] >= 0 && a[x][y] < 4 && a[x][y] != d) continue;

                nx = x + dx[d]; ny = y + dy[d];
                if (nx >= 1 && nx <= m && ny >= 1 && ny <= n){
                    if (a[nx][ny] >= 0 && a[nx][ny] < 4 && nx + dx[a[nx][ny]] == x && ny + dy[a[nx][ny]] == y) continue;
                    if (a[nx][ny] == -1) continue;
                    g[x][y].push_back({nx, ny});
                    ++indeg[nx][ny];
                }
                else{
                    if (a[x][y] >= 0 && a[x][y] < 4) g[x][y].push_back({-1, -1});
                }
            }        
        }
}

long long gcd(long long a, long long b){
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

pair<long long, long long> add(pair<long long, long long> a, pair<long long, long long> b, long long chu){
    pair<long long, long long> c;
    long long d;
    b.second *= chu;
    c.first = a.first * b.second + b.first * a.second;
    c.second = a.second * b.second;
    if (c.first == 0) c.second = 1;
    else{
        d = gcd(c.first, c.second);
        c.first /= d; c.second /= d;
    }

    return c;
}

void work(){
    int x, y, nx, ny, d;
    calc_deg();
    for (x = 1; x <= m; ++x)
        for (y = 1; y <= n; ++y)
            f[x][y] = {0, 1};

    res = {0, 1};
    f[1][1] = {1, 1};
    while (true){
        bool change = false;
        for (x = 1; x <= m; ++x)
            for (y = 1; y <= n; ++y)
                if (!done[x][y] && indeg[x][y] == 0){
                    change = done[x][y] = true;
                    for (auto p : g[x][y]){
                        nx = p.first; ny = p.second;
                        if (nx == -1 && ny == -1){
                            printf("%lld %lld\n", f[x][y].first, f[x][y].second);                            
                            return;
                        }

                        f[nx][ny] = add(f[nx][ny], f[x][y], g[x][y].size());
                        --indeg[nx][ny];
                    }
                }
        if (!change) break;
    }

    printf("0 1\n");
}

int main() {
    int t, T;
    // freopen("i.in", "r", stdin);
    scanf("%d", &T);
    for (t = 1; t <= T; ++t){
        init();
        work();
    }
    return 0;
}