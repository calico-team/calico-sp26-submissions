#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct node { 
    int x, y, u, v; 
};
int qry(const vector<vector<int>>& S, int x1, int y1, int x2, int y2) {
    return S[x2 + 1][y2 + 1] - S[x1][y2 + 1] - S[x2 + 1][y1] + S[x1][y1];
}
bool chk(const vector<vector<int>>& S, int sz, int k, int d, int& rx, int& ry) {
    for (int i = 0; i < sz; ++i) {
        int ex = min(sz - 1, i + d);
        for (int j = 0; j < sz; ++j) {
            int ey = min(sz - 1, j + d);
            if (qry(S, i, j, ex, ey) >= k) {
                rx = i;
                ry = j;
                return true;
            }
        }
    }
    return false;
}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> mp(n);
    for (int i = 0; i < n; ++i) {
        cin >> mp[i];
    }
    int sz = n + m - 1;
    vector<vector<int>> S(sz + 2, vector<int>(sz + 2, 0));
    vector<node> vec;
    vec.reserve(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == '-') {
                int u = i + j;
                int v = i - j + m - 1;
                S[u + 1][v + 1]++;
                vec.push_back({i, j, u, v});
            }
        }
    }
    for (int i = 1; i <= sz; ++i) {
        for (int j = 1; j <= sz; ++j) {
            S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }
    int rx = 0, ry = 0;
    int l = 0, r = sz - 1, ans = r;
    while (l <= r) {
        int mid = l + r >> 1;
        if (chk(S, sz, k, mid, rx, ry)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    chk(S, sz, k, ans, rx, ry);
    int bx = min(sz - 1, rx + ans);
    int by = min(sz - 1, ry + ans);

    int cnt = 0;
    for (auto& p : vec) {
        if (p.u >= rx && p.u <= bx && p.v >= ry && p.v <= by) {
            cout << p.x << ' ' << p.y << '\n';
            if (++cnt == k) break;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}