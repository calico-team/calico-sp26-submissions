#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Seat {
    int r, c;
};

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    vector<string> grid(N);
    vector<Seat> all;
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '-') {
                all.push_back({i, j});
            }
        }
    }

    if (K == 0) return;

    int min_dist = 1e9;
    long long min_aura = 2e18;
    vector<Seat> best;

    for (int r1 = 0; r1 < N; ++r1) {
        vector<int> row_counts(M, 0);
        for (int r2 = r1; r2 < N; ++r2) {
            if (r2 - r1 >= min_dist) break;

            vector<int> cols;
            for (const auto& s : all) {
                if (s.r >= r1 && s.r <= r2) {
                    cols.push_back(s.c);
                }
            }

            if (cols.size() < K) continue;
            sort(cols.begin(), cols.end());

            for (int i = 0; i <= (int)cols.size() - K; ++i) {
                int c1 = cols[i];
                int c2 = cols[i + K - 1];
                int current_max_dist = (r2 - r1) + (c2 - c1);

                if (current_max_dist <= min_dist) {
                    vector<Seat> current_set;
                    long long current_aura = 0;
                    
                    int found = 0;
                    for (const auto& s : all) {
                        if (s.r >= r1 && s.r <= r2 && s.c >= c1 && s.c <= c2) {
                            current_set.push_back(s);
                            current_aura += (s.r + s.c);
                            found++;
                            if (found == K) break;
                        }
                    }

                    if (current_max_dist < min_dist || current_aura < min_aura) {
                        min_dist = current_max_dist;
                        min_aura = current_aura;
                        best = current_set;
                    }
                }
            }
        }
    }

    for (int i = 0; i < K; ++i) {
        cout << best[i].r << " " << best[i].c << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}