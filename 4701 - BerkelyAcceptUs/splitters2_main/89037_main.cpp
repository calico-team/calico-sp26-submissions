
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;


void solve() {
    int p, a, b; cin >> p >> a >> b;
    int n = 1000;
    int m = 1000;
    vector<vector<char>> grid(n, vector<char>(m, '.'));
    grid[0][0] = '>';
    grid[0][1] = 'v';
    vector<int> cur = {1, 1};

    auto fill_col = [&](int x, int y) {for (int i = x; i < n; i++) grid[i][y] = 'v';};
    auto fill_row = [&](int x, int y) {for (int j = y; j < m; j++) grid[x][j] = '>';};


    for (int i = 0; i < b; i++) {
        grid[cur[0]][cur[1]] = 'S';
        grid[cur[0]][cur[1] - 1] = 'X';
        grid[cur[0] + 1][cur[1]] = 'X';
        grid[cur[0]][cur[1] + 1] = '>';
        grid[cur[0]][cur[1] + 2] = 'v';

        if ((int) ceil(log2(p)) - 1 >= a) {
            if (p % 3 == 1 or p % 3 == 2) fill_col(cur[0], cur[1] - 1);
            if (p % 3 == 2) fill_col(cur[0] + 1, cur[1]);
            p /= 3;
        }

        cur[0] += 1;
        cur[1] += 2;
    }

    while (a > 0) {
        grid[cur[0]][cur[1]] = 'S';
        if (p & (1 << (a - 1))) fill_row(cur[0], cur[1] + 1);
        else grid[cur[0]][cur[1] + 1] = 'X';
        grid[cur[0] + 1][cur[1]] = 'v';

        a--;
        cur[0] += 2;
    }

    grid[cur[0]][cur[1]] = 'X';

    for (int i = 0; i < n; i++) {
        for (auto c : grid[i]) cout << c;
        cout << "\n";
    }




}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();


    return 0;

}