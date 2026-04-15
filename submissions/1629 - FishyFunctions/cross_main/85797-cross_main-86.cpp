#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define si set<int>
#define vvi vector<vector<int>>

int dirs[4][2] = {{-2, 0}, {2, 0}, {0, 2}, {0, -2}};
int poss[1000][1000][5];
int cnt[1000][1000];
int n, m;
vvi vis;

bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void setp(int x, int y, int val) {
    vis[x][y] = 1;
    rep(i, 0, 5)
        poss[x][y][i] = val == i;
    rep(i, max(0ll, x - 1), min(n, x + 2)) {
        rep(j, max(0ll, y - 1), min(m, y + 2))
            if (j - y || i - x) {
                cnt[i][j] -= poss[i][j][val];
                poss[i][j][val] = 0;
                if (cnt[i][j] == 1 && !vis[i][j])
                    rep(k, 0, 5)
                        if (poss[i][j][k])
                            setp(i, j, k);
            }
    }
    rep(i, 0, 4)
        if (in(x + dirs[i][0], y + dirs[i][1])) {
            cnt[x + dirs[i][0]][y + dirs[i][1]] -= poss[x + dirs[i][0]][y + dirs[i][1]][val];
            poss[x + dirs[i][0]][y + dirs[i][1]][val] = 0;
            if (cnt[x + dirs[i][0]][y + dirs[i][1]] == 1 && !vis[x + dirs[i][0]][y + dirs[i][1]]) {
                rep(k, 0, 5)
                    if (poss[x + dirs[i][0]][y + dirs[i][1]][k])
                        setp(x + dirs[i][0], y + dirs[i][1], k);
            }
        }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n)
            rep(j, 0, m)
            rep(k, 0, 5)
            poss[i][j][k] = 1, cnt[i][j] = 5;;
        vis = vvi(n, vi(m));
        setp(0, 1, 0);
        setp(1, 0, 1);
        setp(1, 1, 2);
        setp(1, 2, 3);
        setp(2, 1, 4);
        rep(ii, 0, n + m - 1) {
            rep(i, max(0ll, ii - m + 1), min(ii + 1, n)) {
                rep(k, 0, 5)
                if (!vis[i][ii - i] && poss[i][ii - i][k]) {
                    setp(i, ii - i, k);
                    break;
                }
            }
        }
        rep(i, 0, n) {
            rep(j, 0, m)
                rep(k, 0, 5)
                    if (poss[i][j][k])
                        cout << k << ' ';
            cout << endl;
        }
    }
}
