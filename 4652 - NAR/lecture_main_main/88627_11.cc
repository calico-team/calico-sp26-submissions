#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for(int i = 0; i < n; i++) {
        cin >> g[i];
    }

    int s = n + m - 1;
    vector<vector<int>> a(s, vector<int>(s));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '-') {
                int u = i + j;
                int v = i - j + (m - 1);
                a[u][v] = 1;
            }
        }
    }


    vector<vector<int>> pre(s + 1, vector<int>(s + 1));
    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + a[i][j];
        }
    }

    int bx = -1, by = -1;

    auto check = [&](int d, bool save) {
        for(int i = 0; i + d < s; i++) {
            for(int j = 0; j + d < s; j++) {
                int sum = pre[i + d +  1][j + d + 1] - pre[i][j + d + 1] - pre[i + d + 1][j] + pre[i][j];
                if(sum >= k) {
                    if(save) {
                        bx = i;
                        by = j;
                    }
                    return true;
                }
            }
        }
        return false;
    };

    int l = 0, r = n + m - 2;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(check(mid, false)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    int d = l;
    check(d, true);

    int rem = k;
    for(int i = 0; i < n && rem > 0; i++) {
        for(int j = 0; j < m && rem > 0; j++) {
            if(g[i][j] != '-') {
                continue;
            }
            int u = i + j;
            int v = i - j + (m - 1);
            if(bx <= u && u <= bx + d && by <= v && v <= by + d) {
                cout << i << ' ' << j << '\n';
                rem--;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.out", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}