#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
const int N = 50 + 10;

int n, m;
char g[N][N];
struct Frac {
    int p, q;
    void yf() {int d = abs(__gcd(p, q)); p /= d, q /= d;}
    void init(int a, int b) {p = a; q = b; if(q < 0) p = -p, q = -q; yf();}
    Frac operator * (const Frac &W) const {
        Frac t; t.init(p, q);
        t.p *= W.p, t.q *= W.q, t.yf();
        return t;
    }
    Frac operator + (const Frac &W) const {
        Frac t; t.init(p, q); int d = __gcd(q, W.q);
        t.p = W.q / d * t.p + q / d * W.p, t.q = q / d * W.q;
        t.yf();
        return t;
    }
    Frac operator - (const Frac &W) const {
        Frac t; t.init(p, q); int d = __gcd(q, W.q);
        t.p = W.q / d * t.p - q / d * W.p, t.q = q / d * W.q, t.yf();
        return t;
    }
    Frac operator / (const Frac &W) const {
        Frac t; t.init(p, q);
        t.p *= W.q, t.q *= W.p, t.yf();
        return t;
    }
    bool operator < (const Frac &W) const {Frac t; t.init(p, q); t.yf(); return (t - W).p < 0;}
    bool operator > (const Frac &W) const {Frac t; t.init(p, q); t.yf();return (t - W).p > 0;}
    bool operator <= (const Frac &W) const {Frac t; t.init(p, q); t.yf();return (t - W).p <= 0;}
    bool operator >= (const Frac &W) const {Frac t; t.init(p, q); t.yf();return (t - W).p >= 0;}
    bool operator == (const Frac &W) const {return p == W.p && q == W.q;}
    void print() {yf();cout << p << '/' << q << '\n';}
} a[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, ind[N][N];
bool st[N][N];
bool check(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= m && g[x][y] != '.';
}
queue<pair<int, int> > q;
void ck(int x, int y, Frac c) {
    if(check(x, y) == 0) return ;
    ind[x][y] --, a[x][y] = a[x][y] + c;
    if(!ind[x][y]) q.push({x, y});
}
void bfs() {
    memset(st, 0, sizeof st);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
        if(!ind[i][j]) q.push({i, j});
    }
    while(q.size()) {
        auto [x, y] = q.front(); q.pop();
        if(g[x][y] == 'X' || !check(x, y)) continue;
        // cout << x << " " << y << ' ';/
        // a[x][y].print();
        if(g[x][y] == 'v') ck(x + 1, y, a[x][y]);
        else if(g[x][y] == '>') ck(x, y + 1, a[x][y]);
        else if(g[x][y] == '<') ck(x, y - 1, a[x][y]);
        else if(g[x][y] == '^') ck(x - 1, y, a[x][y]);
        else if(g[x][y] == 'S') {
            int cnt = 0;
            for(int i = 0, xx, yy; i < 4; i ++) {
                xx = x + dx[i], yy = y + dy[i];
                if(check(xx, yy) && ind[xx][yy]) {
                    cnt ++;
                }
            }
            // cout << cnt << endl;
            if(cnt == 0) {
                while(1) ;
            }
            Frac tmp; tmp.init(cnt, 1);
            Frac t = a[x][y] / tmp;
            for(int i = 0, xx, yy; i < 4; i ++) {
                xx = x + dx[i], yy = y + dy[i];
                if(check(xx, yy) && ind[xx][yy]) {
                    a[xx][yy] = a[xx][yy] + t;
                    if(!-- ind[xx][yy])
                        q.push({xx, yy});
                }
            }
        }
    }
}
void work() {
    cin >> n >> m;
    memset(g, 0, sizeof g);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) cin >> g[i][j], ind[i][j] = 0, a[i][j].init(0, 1);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
        if(g[i][j] == 'v') ind[i + 1][j] ++;
        else if(g[i][j] == '>') ind[i][j + 1] ++;
        else if(g[i][j] == '<') ind[i][j - 1] ++;
        else if(g[i][j] == '^') ind[i - 1][j] ++;
        else if(g[i][j] == 'S') {
            for(int d = 0, xx, yy; d < 4; d ++) {
                xx = i + dx[d], yy = j + dy[d];
                if(check(xx, yy) && g[xx][yy] == 'X') {
                    ind[xx][yy] ++;
                }
            }
            if(g[i - 1][j] == '^') ind[i - 1][j] ++;
            if(g[i][j - 1] == '<') ind[i][j - 1] ++;
            if(g[i + 1][j] == 'v') ind[i + 1][j] ++;
            if(g[i][j + 1] == '>') ind[i][j + 1] ++;
        }
    }
    a[1][1].init(1, 1);
    bfs();
    Frac ans = {0, 1};
    for(int i = 1; i <= m; i ++) {
        if(g[1][i] == '^') ans = ans + a[1][i];
        if(g[n][i] == 'v') ans = ans + a[n][i];
    }
    for(int i = 1; i <= n; i ++) {
        if(g[i][1] == '<') ans = ans + a[i][1];
        if(g[i][m] == '>') ans = ans + a[i][m];
    }
    cout << ans.p << ' ' << ans.q << '\n';
    return ;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1; 
    cin >> T;
    while (T--) work();

    return 0;
}
