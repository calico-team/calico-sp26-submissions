
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '!'));
    for (int i = 0; i < n; i++) {
        string r; cin >> r;
        for (int j = 0; j < m; j++) grid[i][j] = r[j];
    }

    vector<tuple<int, int>> indices = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string rev = "<>^v";
    string s = "><v^";
    // vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> ans = {1, 1};

    // visited[0][0] = true;
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 1, 1});

    auto subtract = [&](vector<int> a, vector<int> b) {
        int l = lcm(a[1], b[1]);
        int num = a[0] * (l / a[1]) - b[0] * (l / b[1]);
        int g = gcd(num, l);
        num /= g;
        l /= g;
        vector<int> res = {num, l};
        return res;
    };

    // cout << grid[0][0] << "\n";
    // cout << s.find_first_of(grid[0][0]) << "\n";

    while (not q.empty()) {
        auto [x, y, a, b] = q.front(); q.pop();

        // cout << x << " " << y << " " << a << " " << b << "\n";
        assert (0 <= x and x < n and 0 <= y and y < m);

        if (grid[x][y] == 'X') {
            // cout << ans[0] << " " << ans[1] << " " << a << " " << b << " REM " << "\n";
            ans = subtract(ans, {a, b});
            continue;
        }

        if (grid[x][y] == 'S') {
            vector<tuple<int, int>> amt;
            for (int i = 0; i < 4; i++) {
                auto nx = x + get<0>(indices[i]);
                auto ny = y + get<1>(indices[i]);

                if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] != '.' and grid[nx][ny] != rev[i]) amt.push_back({nx, ny});
            }

            for (auto [nx, ny] : amt) {
                q.push({nx, ny, a, b * amt.size()});
            }
            continue;
        }

        auto dir = s.find_first_of(grid[x][y]);
        auto [cx, cy] = indices[dir];
        auto nx = x + cx, ny = y + cy;
        if (0 <= nx and nx < n and 0 <= ny and ny < m) q.push({nx, ny, a, b});



    }

    if (ans[0] == 0) cout << 0 << " " << 1 << "\n";
    else cout << ans[0] << " " << ans[1] << "\n";


}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();


    return 0;

}
// 1
// 3 3
// S>v
// v.v
// >>X