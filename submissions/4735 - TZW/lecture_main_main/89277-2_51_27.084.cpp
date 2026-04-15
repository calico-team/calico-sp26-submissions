#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

struct Seat {
    int r, c, u, v, aura;
};

struct Result {
    bool found;
    vector<pair<int, int>> coords;
};

Result check_valid(int D, const vector<Seat>& points, int K) {
    long long best_aura_sum = LLONG_MAX;
    vector<pair<int, int>> best_set;
    bool found_any = false;
    int n = points.size();
    int left = 0;

    for (int right = 0; right < n; ++right) {
        while (points[right].u - points[left].u > D) {
            left++;
        }

        if ((right - left + 1) >= K) {
            vector<Seat> sub;
            for (int i = left; i <= right; ++i) {
                sub.push_back(points[i]);
            }

            sort(sub.begin(), sub.end(), [](const Seat& a, const Seat& b) {
                return a.v < b.v;
            });

            int v_left = 0;
            for (int v_right = 0; v_right < sub.size(); ++v_right) {
                while (sub[v_right].v - sub[v_left].v > D) {
                    v_left++;
                }

                if ((v_right - v_left + 1) >= K) {
                    found_any = true;
                    vector<Seat> potential;
                    for (int i = v_left; i <= v_right; ++i) {
                        potential.push_back(sub[i]);
                    }

                    sort(potential.begin(), potential.end(), [](const Seat& a, const Seat& b) {
                        return a.aura < b.aura;
                    });

                    long long current_aura_sum = 0;
                    vector<pair<int, int>> current_set;
                    for (int i = 0; i < K; ++i) {
                        current_aura_sum += potential[i].aura;
                        current_set.push_back({potential[i].r, potential[i].c});
                    }

                    if (current_aura_sum < best_aura_sum) {
                        best_aura_sum = current_aura_sum;
                        best_set = current_set;
                    }
                }
            }
        }
    }
    return {found_any, best_set};
}

void solve() {
    int T;
    if (!(cin >> T)) return;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> grid(N);
        for (int i = 0; i < N; ++i) cin >> grid[i];

        vector<Seat> available_seats;
        for (int r = 0; r < N; ++r) {
            vector<int> left_counts(M, 0);
            vector<int> right_counts(M, 0);

            int curr_left = 0;
            for (int c = 0; c < M; ++c) {
                left_counts[c] = curr_left;
                if (grid[r][c] == '#') curr_left++;
            }

            int curr_right = 0;
            for (int c = M - 1; c >= 0; --c) {
                right_counts[c] = curr_right;
                if (grid[r][c] == '#') curr_right++;
            }

            for (int c = 0; c < M; ++c) {
                if (grid[r][c] == '-') {
                    int aura = min(left_counts[c], right_counts[c]);
                    available_seats.push_back({r, c, r + c, r - c, aura});
                }
            }
        }

        sort(available_seats.begin(), available_seats.end(), [](const Seat& a, const Seat& b) {
            return a.u < b.u;
        });

        int low = 0, high = N + M;
        vector<pair<int, int>> best_overall;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            Result res = check_valid(mid, available_seats, K);
            if (res.found) {
                best_overall = res.coords;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        for (const auto& p : best_overall) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
