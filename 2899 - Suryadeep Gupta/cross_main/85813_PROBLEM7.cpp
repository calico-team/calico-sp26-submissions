#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> make_the_criss_cross(int n, int m) {
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 3 == 0) {
                // 1 0 1 0 ...
                a[i][j] = (j % 2 == 0 ? 1 : 0);
            }
            else if (i % 3 == 1) {
                // 1 2 3 4 ...
                a[i][j] = (j % 4) + 1;
            }
            else {
                // 4 4 0 0 ...
                a[i][j] = (j % 4 < 2 ? 4 : 0);
            }
        }
    }

    return a;
}

void read_your_input() {
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        auto grid = make_the_criss_cross(n, m);

        for (auto &row : grid) {
            for (int x : row) cout << x << " ";
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    read_your_input();
}