#include <bits/stdc++.h>
using namespace std;

int n, m;

void fill(vector<vector<int>>& ans, int row, int col, int num) {
    while (row < n || col < m) {
        int row1 = row, col1 = col, row2 = row, col2 = col;
        while (row1 < n || col1 >= 0) {
            if (0 <= row1 && row1 < n && 0 <= col1 && col1 < m) ans[row1][col1] = num;
            row1 += 1, col1 -= 2;
        }
        while (row2 >= 0 || col2 < m) {
            if (0 <= row2 && row2 < n && 0 <= col2 && col2 < m) ans[row2][col2] = num;
            row2 -= 1, col2 += 2;
        }
        row += 2, col += 1;
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m));

    fill(ans, 0, 0, 0);
    fill(ans, 0, 1, 1);
    fill(ans, 0, 2, 2);
    fill(ans, 0, 3, 3);
    fill(ans, 0, 4, 4);

    for (auto i : ans) {
        for (int j : i) cout << j << " ";
        cout << endl;
    }

}

int main() {
	int t; cin >> t;
    while (t--) solve();
}
