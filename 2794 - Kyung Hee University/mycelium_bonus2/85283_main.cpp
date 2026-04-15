#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool vis[10000][10000];
pii gq[40000], mq[40000];
pii ngq[40000], nmq[40000];

void solve() {
    fill(&vis[0][0], &vis[9999][10000], 0);

    int xg, yg, xm, ym;
    cin>>xg>>yg>>xm>>ym;

    xg += 5000, yg += 5000, xm += 5000, ym += 5000;

    int ct = 0;
    int res = 0;
    vis[xg][yg] = 1;
    int gqs = 1;
    gq[0] = {xg, yg};
    vis[xm][ym] = 1;
    int mqs = 1;
    mq[0] = {xm, ym};
    res++;
    while(mqs > 0) {
        ct++;
        
        if (ct % 2 == 0) {
            int ngqs = 0;
            for (int i=0; i<gqs; i++) {
                auto [x, y] = gq[i];

                int nx, ny;
                for (int d = -1; d <= 1; d += 2) {
                    nx = x + d, ny = y;
                    if (nx >= 0 && nx < 10000 && ny >= 0 && ny < 10000 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        ngq[ngqs++] = {nx, ny};
                    }
                    nx = x, ny = y + d;
                    if (nx >= 0 && nx < 10000 && ny >= 0 && ny < 10000 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        ngq[ngqs++] = {nx, ny};
                    }
                }
            }
            gqs = ngqs;
            swap(gq, ngq);
        }

        if (ct % 7 == 0) {
            int nmqs = 0;
            for (int i=0; i<mqs; i++) {
                auto [x, y] = mq[i];

                int nx, ny;
                for (int d = -1; d <= 1; d += 2) {
                    nx = x + d, ny = y;
                    if (nx >= 0 && nx < 10000 && ny >= 0 && ny < 10000 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        nmq[nmqs++] = {nx, ny};
                        res++;
                    }
                    nx = x, ny = y + d;
                    if (nx >= 0 && nx < 10000 && ny >= 0 && ny < 10000 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        nmq[nmqs++] = {nx, ny};
                        res++;
                    }
                }
            }
            mqs = nmqs;
            swap(mq, nmq);
        }
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    
    return 0;
}