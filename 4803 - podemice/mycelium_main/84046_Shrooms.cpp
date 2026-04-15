#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define eb emplace_back
#define pb push_back
#define vc vector
#define fs first
#define sd second

typedef pair<int, int> pii;
typedef vector<int> vi;

bool check(int x, int y, vc<vi> &grid) {
    return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0);
}

void solve() {
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;

    int dx = 2*abs(xg - xm), dy = 2*abs(yg - ym);
    dx = dy = max(dx, dy);
    int bx = min(xg, xm), by = min(yg, ym);
    xg = xg - bx + dx; xm = xm - bx + dx;
    yg = yg - by + dy; ym = ym - by + dy;

    vc<vi> grid(max(xg, xm)+dx+2, vi(max(yg, ym)+dy+2, 0));
    queue<pii> g, m;
    g.push({xg, yg}); grid[xg][yg] = 1;
    m.push({xm, ym}); grid[xm][ym] = 2;
    int t = 1, count = 1;
    while (!m.empty()) {
        if (t % 2 == 0) { 
            int r = g.size();
            rep(i, 0, r) {
                pii top = g.front(); g.pop();

                if (check(top.fs+1, top.sd, grid)) {
                    grid[top.fs+1][top.sd] = 1;
                    g.push({top.fs+1, top.sd});
                }

                if (check(top.fs, top.sd+1, grid)) {
                    grid[top.fs][top.sd+1] = 1;
                    g.push({top.fs, top.sd+1});
                }

                if (check(top.fs-1, top.sd, grid)) {
                    grid[top.fs-1][top.sd] = 1;
                    g.push({top.fs-1, top.sd});
                }

                if (check(top.fs, top.sd-1, grid)) {
                    grid[top.fs][top.sd-1] = 1;
                    g.push({top.fs, top.sd-1});
                }
            }
        }

        if (t % 7 == 0) {
            int r = m.size();
            rep(i, 0, r) {
                pii top = m.front(); m.pop();
                
                if (check(top.fs+1, top.sd, grid)) {
                    grid[top.fs+1][top.sd] = 1;
                    m.push({top.fs+1, top.sd});
                    count++;
                }

                if (check(top.fs, top.sd+1, grid)) {
                    grid[top.fs][top.sd+1] = 1;
                    m.push({top.fs, top.sd+1});
                    count++;
                }

                if (check(top.fs-1, top.sd, grid)) {
                    grid[top.fs-1][top.sd] = 1;
                    m.push({top.fs-1, top.sd});
                    count++;
                }

                if (check(top.fs, top.sd-1, grid)) {
                    grid[top.fs][top.sd-1] = 1;
                    m.push({top.fs, top.sd-1});
                    count++;
                }
            }
        }

        t++;
    }

    cout << count << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) solve();
}