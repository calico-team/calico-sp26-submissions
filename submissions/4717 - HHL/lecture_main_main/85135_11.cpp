#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Seat {
    int r, c, x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<Seat> available;
        int max_dim = N + M + 2;
        vector<vector<int>> grid_sum(max_dim, vector<int>(max_dim, 0));

        for (int i = 0; i < N; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < M; ++j) {
                if (row[j] == '-') {
                    int x = i + j + 1;
                    int y = i - j + M;
                    available.push_back({i, j, x, y});
                    grid_sum[x][y]++;
                }
            }
        }

        for (int i = 1; i < max_dim; ++i) {
            for (int j = 1; j < max_dim; ++j) {
                grid_sum[i][j] += grid_sum[i - 1][j] + grid_sum[i][j - 1] - grid_sum[i - 1][j - 1];
            }
        }

        int low = 0, high = N + M, best_dist = N + M;
        int best_x = 1, best_y = 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            bool found = false;
            for (int i = 1; i < max_dim - mid && !found; ++i) {
                for (int j = 1; j < max_dim - mid && !found; ++j) {
                    int x2 = i + mid;
                    int y2 = j + mid;
                    int count = grid_sum[x2][y2] - grid_sum[i - 1][y2] - grid_sum[x2][j - 1] + grid_sum[i - 1][j - 1];
                    if (count >= K) {
                        best_dist = mid;
                        best_x = i;
                        best_y = j;
                        found = true;
                    }
                }
            }
            if (found) high = mid - 1;
            else low = mid + 1;
        }

        int count = 0;
        for (const auto& s : available) {
            if (s.x >= best_x && s.x <= best_x + best_dist && s.y >= best_y && s.y <= best_y + best_dist) {
                cout << s.r << " " << s.c << "\n";
                if (++count == K) break;
            }
        }
    }

    return 0;
}