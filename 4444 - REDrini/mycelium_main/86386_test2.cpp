#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Point {
    int x;
    int y;
    int f;
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (T--) {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        vector<vector<int>> arr(501, vector<int>(501));
        xg += 250;
        yg += 250;
        xm += 250;
        ym += 250;
        arr[xg][yg] = 2;
        arr[xm][ym] = 7;
        vector<vector<Point>> query(100'100);
        query[2].push_back({xg, yg, 2});
        query[7].push_back({xm, ym, 7});
        for (int i = 1; i <= 100'000; ++i) {
            auto iterator = query[i].rbegin();
            while (iterator != query[i].rend()) {
                auto [x, y, f] = *iterator;
                for (auto [dx, dy] : dirs) {
                    if (x + dx < 0 || x + dx > 500 || y + dy < 0 || y + dy > 500) {
                        continue;
                    }
                    if (!arr[x + dx][y + dy]) {
                        arr[x + dx][y + dy] = f;
                        query[i + f].push_back({x + dx, y + dy, f});
                    }
                }
                ++iterator;
            }
        }
        int res = 0;
        for (auto& i : arr) {
            for (auto& j : i) {
                res += (j == 7);
            }
        }
        cout << res << '\n';
    }   
}