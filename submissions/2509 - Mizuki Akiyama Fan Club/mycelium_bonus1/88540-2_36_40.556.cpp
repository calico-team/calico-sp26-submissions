#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define endl "\n"

constexpr int mod = 998244353;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n = 2000;
    x1 += n/2;
    y1 += n/2;
    x2 += n/2;
    y2 += n/2;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    grid[x1][y1] = 1;
    grid[x2][y2] = 2;
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {1, 0, -1, 0};
    int ans = 1;
    vector<pi> grass = {{x1, y1}};
    vector<pi> mycelium = {{x2, y2}};
    for (int t = 2; t > 0; t++) {
        if (t % 7 == 0) {
            vector<pi> nw;
            for (auto p: mycelium) {
                for (int k = 0; k < 4; k++) {
                    int x = dx[k]+p.f;
                    int y = dy[k]+p.s;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        continue;
                    }
                    if (grid[x][y] != 1 && grid[x][y] != 2 && grid[x][y] != -22) {
                        grid[x][y] = -22;
                        nw.pb({x, y});
                    }
                }
            }
            mycelium = nw;
        }
        if (t % 2 == 0) {
            vector<pi> nw;
            for (auto p: grass) {
                for (int k = 0; k < 4; k++) {
                    int x = dx[k]+p.f;
                    int y = dy[k]+p.s;
                    if (x < 0 || x >= n || y < 0 || y >= n) {
                        continue;
                    }
                    if (grid[x][y] != 1 && grid[x][y] != 2 && grid[x][y] != -11) {
                        grid[x][y] = -11;
                        nw.pb({x, y});
                    }
                }
            }
            grass = nw;
        }
        int myc = 0;
        for (auto p: grass) {
            int i = p.f;
            int j = p.s;
            if (grid[i][j] == -11) {
                grid[i][j] = 1;
            }
        }
        for (auto p: mycelium) {
            int i = p.f;
            int j = p.s;
            if (grid[i][j] == -22) {
                grid[i][j] = 2;
                myc++;
                ans++;
            }
        }
        if (t % 7 == 0 && myc == 0) {
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);     
    ios_base::sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
 
    for (int tc = 0; tc < t; tc++) {
        solve();
    }
 
    return 0;
}