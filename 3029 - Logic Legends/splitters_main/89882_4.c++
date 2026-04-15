#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fraction {
    ll p, q;
    Fraction(ll _p = 0, ll _q = 1) : p(_p), q(_q) { normalize(); }

    void normalize() {
        if (p == 0) {
            q = 1;
            return;
        }
        ll g = gcd(abs(p), abs(q));
        p /= g;
        q /= g;
        if (q < 0) p = -p, q = -q;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(p * other.q + other.p * q, q * other.q);
    }

    Fraction operator/(ll x) const {
        return Fraction(p, q * x);
    }
};

int N, M;
vector<string> grid;
vector<vector<int>> vis;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool points_back(char c, int fromx, int fromy, int tox, int toy) {
    if (c == '^') return tox - 1 == fromx && toy == fromy;
    if (c == 'v') return tox + 1 == fromx && toy == fromy;
    if (c == '<') return tox == fromx && toy - 1 == fromy;
    if (c == '>') return tox == fromx && toy + 1 == fromy;
    return false;
}

Fraction dfs(int x, int y) {
    char c = grid[x][y];

    if (c == 'X') return Fraction(0, 1);

    if (c == '^' || c == 'v' || c == '<' || c == '>') {
        int nx = x, ny = y;
        if (c == '^') nx--;
        if (c == 'v') nx++;
        if (c == '<') ny--;
        if (c == '>') ny++;

        if (!inside(nx, ny)) return Fraction(1, 1);
        return dfs(nx, ny);
    }

    // splitter
    vector<pair<int,int>> nxt;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!inside(nx, ny)) continue;

        char nc = grid[nx][ny];
        if (nc == '.') continue;
        if (nc == 'X') {
            nxt.push_back({nx, ny});
            continue;
        }

        if (nc == '^' || nc == 'v' || nc == '<' || nc == '>') {
            if (!points_back(nc, x, y, nx, ny))
                nxt.push_back({nx, ny});
        }
    }

    Fraction ans(0, 1);
    for (auto [nx, ny] : nxt) {
        ans = ans + dfs(nx, ny) / (ll)nxt.size();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;
        grid.assign(N, "");
        for (int i = 0; i < N; i++) cin >> grid[i];

        Fraction ans = dfs(0, 0);
        cout << ans.p << " " << ans.q << "\n";
    }
    return 0;
}