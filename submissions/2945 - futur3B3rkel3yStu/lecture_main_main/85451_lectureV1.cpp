#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Pt { int r, c, a, v; };
const int MX = 2005;
int S[MX][MX], b1[MX], b2[MX];
vector<Pt> pu[MX];
vector<pair<int, int>> sl[MX];

void up(int i, int v1, int v2) {
    for (i++; i < MX; i += i & -i) {
        b1[i] += v1;
        b2[i] += v2;
    }
}

int gs(int k) {
    int i = 0, c = 0, s = 0;
    for (int j = 1024; j > 0; j >>= 1) {
        if (i + j < MX && c + b1[i + j] < k) {
            i += j;
            c += b1[i];
            s += b2[i];
        }
    }
    return s + (k - c) * i;
}

bool ck(int d, int l, int k) {
    for (int i = d + 1; i <= l; i++) {
        for (int j = d + 1; j <= l; j++) {
            if (S[i][j] - S[i - d - 1][j] - S[i][j - d - 1] + S[i - d - 1][j - d - 1] >= k) return 1;
        }
    }
    return 0;
}

void add(int v, int a) {
    for (auto& p : sl[v]) if (p.first == a) { p.second++; return; }
    sl[v].push_back({a, 1});
}

void rem(int v, int a) {
    for (int i = 0; i < (int)sl[v].size(); i++) {
        if (sl[v][i].first == a) {
            if (--sl[v][i].second == 0) sl[v].erase(sl[v].begin() + i);
            return;
        }
    }
}

vector<pair<int, int>> solve(int N, int M, int K, vector<string>& g) {
    vector<vector<int>> pr(N, vector<int>(M));
    int l = N + M + 1;
    for (int i = 0; i <= l; i++) {
        pu[i].clear();
        sl[i].clear();
        for (int j = 0; j <= l; j++) S[i][j] = 0;
    }
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < M; j++) if (g[i][j] == '#') cnt++;
        int cur = 0;
        for (int j = 0; j < M; j++) {
            if (g[i][j] == '-') {
                int a = min(cur, cnt - cur);
                int u = i + j + 1, v = i - j + M;
                S[u][v]++;
                pu[u].push_back({i, j, a, v});
            } else cur++;
        }
    }
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++)
            S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];

    int lo = 0, hi = N + M, D = hi;
    while (lo <= hi) {
        int md = (lo + hi) / 2;
        if (ck(md, l, K)) { D = md; hi = md - 1; }
        else lo = md + 1;
    }

    ll mn = 4e18;
    int bu = -1, bv = -1;
    vector<int> sc(l + 1, 0);
    for (int u0 = 1; u0 <= l - D; u0++) {
        if (u0 == 1) {
            for (int u = 1; u <= 1 + D; u++)
                for (auto& p : pu[u]) { sc[p.v]++; add(p.v, p.a); }
        } else {
            for (auto& p : pu[u0 - 1]) { sc[p.v]--; rem(p.v, p.a); }
            if (u0 + D <= l)
                for (auto& p : pu[u0 + D]) { sc[p.v]++; add(p.v, p.a); }
        }
        int bc = 0;
        for (int i = 0; i < MX; i++) b1[i] = b2[i] = 0;
        for (int v = 1; v <= 1 + D; v++) {
            if (sc[v]) {
                bc += sc[v];
                for (auto& p : sl[v]) up(p.first, p.second, p.second * p.first);
            }
        }
        for (int v0 = 1; v0 <= l - D; v0++) {
            if (bc >= K) {
                ll cur = gs(K);
                if (cur < mn) { mn = cur; bu = u0; bv = v0; }
            }
            if (v0 + D + 1 <= l) {
                if (sc[v0]) {
                    bc -= sc[v0];
                    for (auto& p : sl[v0]) up(p.first, -p.second, -p.second * p.first);
                }
                int vn = v0 + D + 1;
                if (sc[vn]) {
                    bc += sc[vn];
                    for (auto& p : sl[vn]) up(p.first, p.second, p.second * p.first);
                }
            }
        }
    }

    vector<Pt> r;
    for (int u = bu; u <= bu + D; u++)
        for (auto& p : pu[u])
            if (p.v >= bv && p.v <= bv + D) r.push_back(p);
    sort(r.begin(), r.end(), [](const Pt& a, const Pt& b) { return a.a < b.a; });
    vector<pair<int, int>> res;
    for (int i = 0; i < K; i++) res.push_back({r[i].r, r[i].c});
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        vector<string> GRID(M);
        for (int i = 0; i < M; i++) {
            cin >> GRID[i];
        }
        vector<pair<int, int>> result = solve(M, N, K, GRID);
        for (auto& p : result) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}