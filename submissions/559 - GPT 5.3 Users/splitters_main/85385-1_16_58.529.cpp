#include <bits/stdc++.h>
using namespace std;
#define int long long
using i2 = array<int, 2>;

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
char dc[] = {'v','^','>','<'};

int n, m;
int id(int x, int y) {
    return x*m+y;
}

i2 simp(i2 a) {
    if (a[0] == 0) return {0, 1};
    int g = gcd(a[0], a[1]);
    return {a[0]/g, a[1]/g};
}

i2 add(i2 a, i2 b) {
    return simp({a[0]*b[1]+a[1]*b[0],a[1]*b[1]});
}

void solve() {
    cin >> n >> m;
    char g[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> g[i][j];
    }

    // solve
    vector<int> in(n*m);
    vector<vector<int>> to(n*m);
    int e = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ij = id(i, j);
            char c = g[i][j];
            if (c == '.' || c == 'X') {
                in[ij] = -1e9;
                continue;
            }
            if (c == 'S') {
                for (int d = 0; d < 4; d++) {
                    int x = i + dx[d], y = j + dy[d];
                    int xy = id(x, y);
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (g[x][y] == '.' || g[x][y] == dc[d]) continue;
                    in[xy]++;
                    to[ij].push_back(xy);
                }
            } else {
                int x = i, y = j;
                if (c == '^') x--;
                if (c == 'v') x++;
                if (c == '>') y++;
                if (c == '<') y--;
                int xy = id(x, y);
                if (x < 0 || x >= n || y < 0 || y >= m) {
                    e = ij;
                } else {
                    in[xy]++;
                    to[ij].push_back(xy);
                }
            }
        }
    }

    // sort
    queue<int> q;
    for (int i = 0; i < n*m; i++) if (in[i] == 0) q.push(i);
    vector<i2> p(n*m, {0, 1});
    p[0] = {1, 1};
    while (size(q)) {
        int ij = q.front();
        q.pop();
        i2 f = simp(p[ij]);
        // cout << ij << ' ';
        // cout << f[0] << ' ' << f[1] << '\n';
        if (ij == e) {
            cout << f[0] << ' ' << f[1] << '\n';
            return;
        }
        f[1] *= size(to[ij]);
        f = simp(f);
        for (auto &xy : to[ij]) {
            p[xy] = add(p[xy], f);
            if (--in[xy] == 0) q.push(xy);
        }
    };
    cout << "0 1\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}