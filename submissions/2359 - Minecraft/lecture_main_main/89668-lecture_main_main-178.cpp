#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct P { int r, c, u, v, a; };

int s[2005][2005];

void solve() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;

    vector<string> g(n);
    vector<P> pts;
    vector<vector<P>> u_pts(n + m);
    
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        int tot = 0;
        for (char c : g[i]) if (c == '#') tot++;
        int l = 0;
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '#') l++;
            else {
                int a = min(l, tot - l);
                P p = {i, j, i + j, i - j + m - 1, a};
                pts.push_back(p);
                u_pts[p.u].push_back(p);
            }
        }
    }

    int um = n + m - 2, vm = n + m - 2;

    for (int i = 0; i <= um + 1; ++i)
        for (int j = 0; j <= vm + 1; ++j) s[i][j] = 0;

    for (auto& p : pts) s[p.u + 1][p.v + 1] = 1;

    for (int i = 1; i <= um + 1; ++i)
        for (int j = 1; j <= vm + 1; ++j)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    auto check = [&](int d) {
        for (int i = d + 1; i <= um + 1; ++i)
            for (int j = d + 1; j <= vm + 1; ++j)
                if (s[i][j] - s[i - d - 1][j] - s[i][j - d - 1] + s[i - d - 1][j - d - 1] >= k) return true;
        return false;
    };

    int L = 0, R = n + m;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (check(M)) R = M; else L = M + 1;
    }
    int d = L;

    int ans = 2e9, bu = -1, bv = -1;
    vector<int> col[2005];

    for (int us = 0; us <= um - d; ++us) {
        int ue = us + d;
        if (ue <= um) for (auto& p : u_pts[ue]) col[p.v].push_back(p.a);

        int f[505] = {0}, cur = 0;
        for (int v = 0; v < d && v <= vm; ++v)
            for (int a : col[v]) { f[a]++; cur++; }

        for (int vs = 0; vs <= vm - d; ++vs) {
            int ve = vs + d;
            if (ve <= vm) for (int a : col[ve]) { f[a]++; cur++; }

            if (cur >= k) {
                int tmp = 0, req = k;
                for (int a = 0; a <= 500; ++a) {
                    int t = min(req, f[a]);
                    tmp += t * a; req -= t;
                    if (!req) break;
                }
                if (tmp < ans) { ans = tmp; bu = us; bv = vs; }
            }
            for (int a : col[vs]) { f[a]--; cur--; }
        }
        for (auto& p : u_pts[us]) {
            auto& v = col[p.v];
            for (int i = 0; i < v.size(); ++i)
                if (v[i] == p.a) { v[i] = v.back(); v.pop_back(); break; }
        }
    }

    vector<P> res;
    for (auto& p : pts)
        if (p.u >= bu && p.u <= bu + d && p.v >= bv && p.v <= bv + d) res.push_back(p);
    
    sort(res.begin(), res.end(), [](P& x, P& y){ return x.a < y.a; });

    for (int i = 0; i < k; ++i) cout << res[i].r << " " << res[i].c << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; if (cin >> t) while (t--) solve();
    return 0;
}
