#include <bits/stdc++.h>
using namespace std;

typedef __int128 i12;
typedef long long ll;

struct F {
    i12 n, d;
};

i12 gd(i12 a, i12 b) {
    return b == 0 ? a : gd(b, a % b);
}

F sm(F a) {
    if (!a.n) return {0, 1};
    i12 k = gd(a.n, a.d);
    return {a.n / k, a.d / k};
}

F ad(F a, F b) {
    i12 k = gd(a.d, b.d);
    i12 l = (a.d / k) * b.d;
    F r = {a.n * (l / a.d) + b.n * (l / b.d), l};
    return sm(r);
}

F me[16][16];
bool vs[16][16];

F df(int r, int c, int n, int m, vector<string>& g) {
    if (r < 0 || r >= n || c < 0 || c >= m) return {1, 1};
    char t = g[r][c];
    if (t == 'x' || t == 'X' || t == '.') return {0, 1};
    if (vs[r][c]) return me[r][c];
    F rs = {0, 1};
    if (t == '^') rs = df(r - 1, c, n, m, g);
    else if (t == 'v') rs = df(r + 1, c, n, m, g);
    else if (t == '<') rs = df(r, c - 1, n, m, g);
    else if (t == '>') rs = df(r, c + 1, n, m, g);
    else if (t == 's' || t == 'S') {
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
        char bk[] = {'v', '^', '>', '<'};
        vector<pair<int, int>> nb;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            char nt = g[nr][nc];
            if (nt == 'x' || nt == 'X' || (string("^v<>").find(nt) != string::npos && nt != bk[i]))
                nb.push_back({nr, nc});
        }
        i12 sz = nb.size();
        for (auto& p : nb) {
            F cu = df(p.first, p.second, n, m, g);
            cu.d *= sz;
            rs = ad(rs, sm(cu));
        }
    }
    vs[r][c] = 1;
    return me[r][c] = rs;
}

pair<long long, long long> solve(int N, int M, vector<string>& factory) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            vs[i][j] = 0;
        }
    }
    F res = df(0, 0, N, M, factory);
    return {(ll)res.n, (ll)res.d};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> factory(N);
        for (int i = 0; i < N; i++) cin >> factory[i];
        auto [P, Q] = solve(N, M, factory);
        cout << P << " " << Q << "\n";
    }
    return 0;
}