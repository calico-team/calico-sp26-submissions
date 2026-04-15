#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
    int f;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (T--) {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        vector<vector<int>> arr(1801, vector<int>(1801));
        xg += 900;
        yg += 900;
        xm += 900;
        ym += 900;
        arr[xg][yg] = 2;
        arr[xm][ym] = 7;
        vector<vector<Point>> query(10'100);
        query[2].push_back({xg, yg, 2});
        query[7].push_back({xm, ym, 7});
        int highQ = 0;
        for (int i = 1; i <= 10'000; ++i) {
            auto iterator = query[i].rbegin();
            while (iterator != query[i].rend()) {
                auto [x, y, f] = *iterator;
                for (auto [dx, dy] : dirs) {
                    if (x + dx < 0 || x + dx > 1800 || y + dy < 0 || y + dy > 1800) {
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
        int highI = 0;
        int highJ = 0;
        for (int i = 0; i <= 1800; ++i) {
            for (int j = 0; j <= 1800; ++j) {
                if (arr[i][j] == 7) {
                    ++res;
                }
            }
        }
        cout << res << '\n';
    }   
}