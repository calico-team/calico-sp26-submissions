#include "bits/stdc++.h"

using namespace std;

struct Seat {
    int r, c, x, y, aura;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<Seat> available;
        int max_dim = N + M + 2;
        vector<vector<int>> grid_sum(max_dim, vector<int>(max_dim, 0));
        vector<string> grid(N);

        for (int i = 0; i < N; ++i) {
            cin >> grid[i];
            int total_occupied = 0;
            for (char ch : grid[i]) if (ch == '#') total_occupied++;

            int left_occupied = 0;
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == '-') {
                    int x = i + j + 1;
                    int y = i - j + M;
                    int right_occupied = total_occupied - left_occupied;
                    int aura = min(left_occupied, right_occupied);
                    
                    available.push_back({i, j, x, y, aura});
                    grid_sum[x][y]++;
                } else {
                    left_occupied++;
                }
            }
        }

        for (int i = 1; i < max_dim; ++i) {
            for (int j = 1; j < max_dim; ++j) {
                grid_sum[i][j] += grid_sum[i - 1][j] + grid_sum[i][j - 1] - grid_sum[i - 1][j - 1];
            }
        }

        int low = 0, high = N + M, best_dist = N + M;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool found = false;
            for (int i = 1; i < max_dim - mid && !found; ++i) {
                for (int j = 1; j < max_dim - mid && !found; ++j) {
                    int x2 = i + mid, y2 = j + mid;
                    if (grid_sum[x2][y2] - grid_sum[i - 1][y2] - grid_sum[x2][j - 1] + grid_sum[i - 1][j - 1] >= K) {
                        found = true;
                    }
                }
            }
            if (found) {
                best_dist = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        long long min_total_aura = -1;
        vector<Seat> best_seats;

        for (int i = 1; i < max_dim - best_dist; ++i) {
            for (int j = 1; j < max_dim - best_dist; ++j) {
                int x2 = i + best_dist, y2 = j + best_dist;
                int count = grid_sum[x2][y2] - grid_sum[i - 1][y2] - grid_sum[x2][j - 1] + grid_sum[i - 1][j - 1];
                
                if (count >= K) {
                    vector<int> current_auras;
                    vector<Seat> current_seats;
                    for (const auto& s : available) {
                        if (s.x >= i && s.x <= x2 && s.y >= j && s.y <= y2) {
                            current_auras.push_back(s.aura);
                            current_seats.push_back(s);
                        }
                    }

                    sort(current_seats.begin(), current_seats.end(), [](const Seat& a, const Seat& b) {
                        return a.aura < b.aura;
                    });

                    long long current_total_aura = 0;
                    for (int k = 0; k < K; ++k) current_total_aura += current_seats[k].aura;

                    if (min_total_aura == -1 || current_total_aura < min_total_aura) {
                        min_total_aura = current_total_aura;
                        best_seats.assign(current_seats.begin(), current_seats.begin() + K);
                    }

                    if (min_total_aura == 0) goto output;
                }
            }
        }

    output:
        for (const auto& s : best_seats) {
            cout << s.r << " " << s.c << "\n";
        }
    }

    return 0;
}