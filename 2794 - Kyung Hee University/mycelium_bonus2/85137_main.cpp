#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool vis[10000][10000];

void solve() {
    fill(&vis[0][0], &vis[9999][10000], 0);

    int xg, yg, xm, ym;
    cin>>xg>>yg>>xm>>ym;

    xg += 5000, yg += 5000, xm += 5000, ym += 5000;

    queue<pii> gq, mq;
    int ct = 0;
    int res = 0;
    vis[xg][yg] = 1;
    gq.push({xg, yg});
    vis[xm][ym] = 1;
    mq.push({xm, ym});
    res++;
    while(!mq.empty()) {
        ct++;
        
        if (ct % 2 == 0) {
            int sz = gq.size();
            for (int i=0; i<sz; i++) {
                auto [x, y] = gq.front();
                gq.pop();

                int nx, ny;
                for (int d = -1; d <= 1; d += 2) {
                    nx = x + d, ny = y;
                    if (nx >= 0 && nx < 10000 && ny >= 0 && ny < 10000 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        gq.push({nx, ny});
                    }
                    nx = x, ny = y + d;
                    if (nx >= 0 && nx < 10000 && ny >= 0 && ny < 10000 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        gq.push({nx, ny});
                    }
                }
            }
        }

        if (ct % 7 == 0) {
            int sz = mq.size();
            for (int i=0; i<sz; i++) {
                auto [x, y] = mq.front();
                mq.pop();

                int nx, ny;
                for (int d = -1; d <= 1; d += 2) {
                    nx = x + d, ny = y;
                    if (nx >= 0 && nx < 10000 && ny >= 0 && ny < 10000 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        mq.push({nx, ny});
                        res++;
                    }
                    nx = x, ny = y + d;
                    if (nx >= 0 && nx < 10000 && ny >= 0 && ny < 10000 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        mq.push({nx, ny});
                        res++;
                    }
                }
            }
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