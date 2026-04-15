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
    vector<vector<int>> cost(n, vector<int>(m, -1));
    vector<int> vals;

    for(int i = 0; i < n; i++) {
        vector<int> row_pre(m + 1);
        for(int j = 0; j < m; j++) {
            row_pre[j + 1] = row_pre[j] + (g[i][j] == '#');
        }
        int tot = row_pre[m];
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '-') {
                int u = i + j;
                int v = i - j + (m - 1);
                a[u][v] = 1;

                int lf = row_pre[j];
                int rg = tot - row_pre[j + 1];
                cost[i][j] = min(lf, rg);
                vals.push_back(cost[i][j]);
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

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int p = s - d;
    int q = p * p;

    vector<int> rem(q, k);
    vector<ll> sum(q);

    vector<vector<int>> b(s, vector<int>(s));
    vector<vector<int>> pre2(s + 1, vector<int>(s + 1));

    for(int x : vals) {
        for(int i = 0; i < s; i++) {
            fill(b[i].begin(), b[i].end(), 0);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(cost[i][j] == x) {
                    int u = i + j;
                    int v = i - j + (m - 1);
                    b[u][v] = 1;
                }
            }
        }

        for(int i = 0; i <= s; i++) {
            fill(pre2[i].begin(), pre2[i].end(), 0);
        }

        for(int i = 0; i < s; i++) {
            for(int j = 0; j < s; j++) {
                pre2[i + 1][j + 1] = pre2[i + 1][j] + pre2[i][j + 1] - pre2[i][j] + b[i][j];
            }
        }

        int id = 0;
        for(int i = 0; i < p; i++) {
            for(int j = 0; j < p; j++) {
                if(rem[id] == 0) {
                    id++;
                    continue;
                }
                int cnt = pre2[i + d + 1][j + d + 1] - pre2[i][j + d + 1] - pre2[i + d + 1][j] + pre2[i][j];
                int take = min(rem[id], cnt);
                rem[id] -= take;
                sum[id] += 1LL * take * x;
                id++;
            }
        }
    }

    ll best = 1e18;
    int id = 0;
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < p; j++) {
            if(rem[id] == 0 && sum[id] < best) {
                best = sum[id];
                bx = i;
                by = j;
            }
            id++;
        }
    }

    vector<array<int, 3>> cand;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] != '-') {
                continue;
            }
            
            int u = i + j;
            int v = i - j + (m - 1);
            if(bx <= u && u <= bx + d && by <= v && v <= by + d) {
                cand.push_back({cost[i][j], i, j});
            }
        }
    }

    sort(cand.begin(), cand.end());

    for(int i = 0; i < k; i++) {
        cout << cand[i][1] << ' ' << cand[i][2] << '\n';
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