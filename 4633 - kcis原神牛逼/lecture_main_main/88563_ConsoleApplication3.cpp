#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

struct Seat {
    int r, c, aura, u, v;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<string> grid(N);
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
        }

        // Precompute aura loss
        vector<vector<int>> aura(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            vector<int> left(M, 0);
            int cnt = 0;
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '#') cnt++;
                left[j] = cnt;
            }
            vector<int> right(M, 0);
            cnt = 0;
            for (int j = M - 1; j >= 0; j--) {
                if (grid[i][j] == '#') cnt++;
                right[j] = cnt;
            }
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '-') {
                    aura[i][j] = min(left[j], right[j]);
                }
            }
        }

        // Collect empty seats with u = r+c, v = r-c
        vector<Seat> seats;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '-') {
                    seats.push_back({ i, j, aura[i][j], i + j, i - j });
                }
            }
        }

        int S = seats.size();
        if (S < K) continue;

        // Binary search for minimal D
        int low = 0, high = N + M;
        int bestD = high;

        // Sort by u for sliding window
        sort(seats.begin(), seats.end(), [](const Seat& a, const Seat& b) {
            return a.u < b.u;
            });

        // Function to check if D is feasible
        auto can = [&](int D) -> bool {
            // Sliding window on u
            int left = 0;
            multiset<int> vSet;

            for (int right = 0; right < S; right++) {
                vSet.insert(seats[right].v);

                // Shrink window from left until u difference <= D
                while (seats[right].u - seats[left].u > D) {
                    vSet.erase(vSet.find(seats[left].v));
                    left++;
                }

                // Check if there's a v-interval of length D containing at least K points
                // We can slide on sorted v values
                vector<int> vs(vSet.begin(), vSet.end());
                for (int i = 0, j = 0; i < vs.size(); i++) {
                    while (j < vs.size() && vs[j] - vs[i] <= D) j++;
                    if (j - i >= K) return true;
                }
            }
            return false;
            };

        while (low <= high) {
            int mid = (low + high) / 2;
            if (can(mid)) {
                bestD = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Now find the actual set with minimal aura loss
        // Collect all rectangles (u interval, v interval) that achieve bestD
        vector<pair<int, int>> uRanges, vRanges;

        // Find all u intervals that can work
        int left = 0;
        multiset<int> vSet;

        for (int right = 0; right < S; right++) {
            vSet.insert(seats[right].v);
            while (seats[right].u - seats[left].u > bestD) {
                vSet.erase(vSet.find(seats[left].v));
                left++;
            }

            // Check v intervals
            vector<int> vs(vSet.begin(), vSet.end());
            for (int i = 0, j = 0; i < vs.size(); i++) {
                while (j < vs.size() && vs[j] - vs[i] <= bestD) j++;
                if (j - i >= K) {
                    // Found a valid v range [vs[i], vs[j-1]]
                    uRanges.push_back({ seats[left].u, seats[right].u });
                    vRanges.push_back({ vs[i], vs[j - 1] });
                }
            }
        }

        // Collect all seats that fall into any valid rectangle
        vector<Seat> candidates;
        for (int i = 0; i < uRanges.size(); i++) {
            int minU = uRanges[i].first, maxU = uRanges[i].second;
            int minV = vRanges[i].first, maxV = vRanges[i].second;

            for (const Seat& s : seats) {
                if (s.u >= minU && s.u <= maxU && s.v >= minV && s.v <= maxV) {
                    candidates.push_back(s);
                }
            }
        }

        // Remove duplicates and sort by aura
        sort(candidates.begin(), candidates.end(), [](const Seat& a, const Seat& b) {
            if (a.r != b.r) return a.r < b.r;
            if (a.c != b.c) return a.c < b.c;
            return false;
            });
        candidates.erase(unique(candidates.begin(), candidates.end(),
            [](const Seat& a, const Seat& b) { return a.r == b.r && a.c == b.c; }), candidates.end());

        // Sort by aura and pick smallest K
        sort(candidates.begin(), candidates.end(), [](const Seat& a, const Seat& b) {
            return a.aura < b.aura;
            });

        for (int i = 0; i < K; i++) {
            cout << candidates[i].r << " " << candidates[i].c << "\n";
        }
    }

    return 0;
}