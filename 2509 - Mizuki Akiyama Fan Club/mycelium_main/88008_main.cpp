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
    x1 += 100;
    y1 += 100;
    x2 += 100;
    y2 += 100;
    vector<vector<int>> grid(200, vector<int>(200, 0));
    grid[x1][y1] = 1;
    grid[x2][y2] = 2;
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {1, 0, -1, 0};
    int ans = 1;
    for (int t = 2; t > 0; t++) {
        if (t % 7 == 0) {
            for (int i = 0; i < 200; i++) {
                for (int j = 0; j < 200; j++) {
                    if (grid[i][j] != 2) {
                        continue;
                    }
                    for (int k = 0; k < 4; k++) {
                        int x = dx[k]+i;
                        int y = dy[k]+j;
                        if (x < 0 || x >= 200 || y < 0 || y >= 200) {
                            continue;
                        }
                        if (grid[x][y] != 1 && grid[x][y] != 2) {
                            grid[x][y] = -22;
                        }
                    }
                }
            }
        }
        if (t % 2 == 0) {
            for (int i = 0; i < 200; i++) {
                for (int j = 0; j < 200; j++) {
                    if (grid[i][j] != 1) {
                        continue;
                    }
                    for (int k = 0; k < 4; k++) {
                        int x = dx[k]+i;
                        int y = dy[k]+j;
                        if (x < 0 || x >= 200 || y < 0 || y >= 200) {
                            continue;
                        }
                        if (grid[x][y] != 1 && grid[x][y] != 2) {
                            grid[x][y] = -11;
                        }
                    }
                }
            }
        }
        int myc = 0;
        for (int i = 0; i < 200; i++) {
            for (int j = 0; j < 200; j++) {
                if (grid[i][j] == -11) {
                    grid[i][j] = 1;
                }
                if (grid[i][j] == -22) {
                    grid[i][j] = 2;
                    myc++;
                    ans++;
                }
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