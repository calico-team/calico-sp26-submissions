#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef __int128_t i128;

struct Ratio {
    i128 n, d;
    void fix() {
        if (!n) { d = 1; return; }
        i128 a = n, b = d;
        while (b) { a %= b; swap(a, b); }
        n /= a; d /= a;
    }
};

void print(i128 x) {
    if (!x) { cout << "0"; return; }
    string s;
    while (x > 0) { s += (char)('0' + (x % 10)); x /= 10; }
    reverse(s.begin(), s.end());
    cout << s;
}

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> g(r);
    for (int i = 0; i < r; ++i) cin >> g[i];

    vector<vector<Ratio>> f(r, vector<Ratio>(c, {0, 1}));
    f[0][0] = {1, 1};
    Ratio out = {0, 1};

    for (int step = 0; step < r * c + 5; ++step) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!f[i][j].n) continue;
                Ratio val = f[i][j];
                f[i][j] = {0, 1};
                char tile = g[i][j];
                if (tile == 'X' || tile == '.') continue;
                if (tile == 'S') {
                    vector<pair<int, int>> nexts;
                    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
                    char rev[] = {'v', '^', '>', '<'};
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dr[k], nj = j + dc[k];
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                            if (g[ni][nj] == 'X' || (g[ni][nj] != '.' && g[ni][nj] != 'S' && g[ni][nj] != rev[k]))
                                nexts.push_back({ni, nj});
                        }
                    }
                    for (auto& p : nexts) {
                        Ratio split = {val.n, val.d * (i128)nexts.size()};
                        split.fix();
                        f[p.first][p.second] = {f[p.first][p.second].n * split.d + split.n * f[p.first][p.second].d, f[p.first][p.second].d * split.d};
                        f[p.first][p.second].fix();
                    }
                } else {
                    int ni = i, nj = j;
                    if (tile == '^') ni--; else if (tile == 'v') ni++; else if (tile == '<') nj--; else if (tile == '>') nj++;
                    if (ni < 0 || ni >= r || nj < 0 || nj >= c) {
                        out = {out.n * val.d + val.n * out.d, out.d * val.d};
                        out.fix();
                    } else {
                        f[ni][nj] = {f[ni][nj].n * val.d + val.n * f[ni][nj].d, f[ni][nj].d * val.d};
                        f[ni][nj].fix();
                    }
                }
            }
        }
    }
    print(out.n); cout << " "; print(out.d); cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}