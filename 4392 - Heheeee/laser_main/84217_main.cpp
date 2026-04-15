#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;

        int x, y;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        // vector<vector<int>> idx(n, vector<int>(m));
        for (int i = 0; i < k; ++i) {
            if (i == 0) {
                cin >> x >> y;
                grid[x][y] = i;
            }
            else {
                int x1, y1;
                cin >> x1 >> y1;
                grid[x1][y1] = i;
                // idx[x1][y1] = i;
            }
        }

        int i = 0;
        while (i < 10000) {
            x = (x + q) % n;
            y = (y + p) % m;

            if (grid[x][y] != -1) {
                cout << grid[x][y] << '\n';
                break;
            }
            ++i;
        }
    }

    return 0;
}