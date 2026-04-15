#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

ll mygcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

struct Frac {
    ll p, q;

    Frac(ll a = 0, ll b = 1) {
        p = a;
        q = b;
        if (q < 0) {
            p = -p;
            q = -q;
        }
        ll g = mygcd(p < 0 ? -p : p, q);
        if (g != 0) {
            p /= g;
            q /= g;
        }
    }

    Frac operator+(const Frac &o) const {
        return Frac(p * o.q + o.p * q, q * o.q);
    }

    Frac operator*(const Frac &o) const {
        return Frac(p * o.p, q * o.q);
    }
};

int n, m;
vector<string> g;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char dirs[] = {'<', '>', '^', 'v'};

int ok(int x, int y, int sx, int sy) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (g[x][y] == '.') return 0;
    if (g[x][y] == 'X') return 1;
    for (int d = 0; d < 4; d++) {
        if (g[x][y] == dirs[d]) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx == sx && ny == sy) return 0;
            return 1;
        }
    }
    return 0;
}

Frac dfs(int x, int y, Frac w) {
    if (x < 0 || x >= n || y < 0 || y >= m) return w;
    char c = g[x][y];
    if (c == 'X') return Frac(0, 1);
    if (c == '.') return Frac(0, 1);

    if (c == 'S') {
        vector<pair<int,int>> nxt;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (ok(nx, ny, x, y)) {
                nxt.push_back({nx, ny});
            }
        }
        int k = nxt.size();
        if (k == 0) return Frac(0, 1);
        Frac res(0, 1);
        for (auto &p : nxt) {
            res = res + dfs(p.first, p.second, w * Frac(1, k));
        }
        return res;
    }

    for (int d = 0; d < 4; d++) {
        if (c == dirs[d]) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            return dfs(nx, ny, w);
        }
    }
    return Frac(0, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        g.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        Frac ans = dfs(0, 0, Frac(1, 1));
        cout << ans.p << " " << ans.q << "\n";
    }
    return 0;
}