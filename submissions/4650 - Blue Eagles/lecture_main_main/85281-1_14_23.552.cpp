#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        vector<pair<int, int>> empty;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '-') {
                    empty.push_back({i, j});
                }
            }
        }

        int lo = 0, hi = n + m;
        vector<pair<int, int>> answer;

        auto can = [&](int d, vector<pair<int, int>>& chosen) {
            for (auto &[r, c] : empty) {
                vector<pair<int, int>> temp;

                for (auto &[r2, c2]: empty) {
                    if (abs(r - r2) + abs(c - c2) <= d) {
                        temp.push_back({r2, c2});
                    }
                }

                if ((int)temp.size() >= k) {
                    chosen.assign(temp.begin(), temp.begin() + k);
                    return true;
                }
            }
            return false;
        };

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<pair<int, int>> candidate;

            if (can(mid, candidate)) {
                answer = candidate;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        for (auto &[r, c] : answer) {
            cout << r << " " << c << endl;
        }
    }
    return 0;
}