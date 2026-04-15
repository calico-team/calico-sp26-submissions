#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

struct Seat {
    int r, c, aura;
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
            // left occupied count
            vector<int> left(M, 0);
            int cnt = 0;
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '#') cnt++;
                left[j] = cnt;
            }
            // right occupied count
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

        int bestMetric = INT_MAX;
        int bestMinR = -1, bestMaxR = -1, bestMinC = -1, bestMaxC = -1;

        // Enumerate row ranges
        for (int minR = 0; minR < N; minR++) {
            vector<int> colCount(M, 0);
            for (int maxR = minR; maxR < N; maxR++) {
                // Add row maxR to colCount
                for (int c = 0; c < M; c++) {
                    if (grid[maxR][c] == '-') {
                        colCount[c]++;
                    }
                }

                // Two pointers on columns to find smallest col range with total >= K
                int total = 0;
                int minC = 0;
                for (int maxC = 0; maxC < M; maxC++) {
                    total += colCount[maxC];
                    while (total - colCount[minC] >= K && minC < maxC) {
                        total -= colCount[minC];
                        minC++;
                    }
                    if (total >= K) {
                        int metric = (maxR - minR) + (maxC - minC);
                        if (metric < bestMetric) {
                            bestMetric = metric;
                            bestMinR = minR;
                            bestMaxR = maxR;
                            bestMinC = minC;
                            bestMaxC = maxC;
                        }
                    }
                }
            }
        }

        // Collect seats in the best rectangle
        vector<Seat> candidates;
        for (int r = bestMinR; r <= bestMaxR; r++) {
            for (int c = bestMinC; c <= bestMaxC; c++) {
                if (grid[r][c] == '-') {
                    candidates.push_back({ r, c, aura[r][c] });
                }
            }
        }

        // Sort by aura loss and pick smallest K
        sort(candidates.begin(), candidates.end(), [](const Seat& a, const Seat& b) {
            return a.aura < b.aura;
            });

        for (int i = 0; i < K; i++) {
            cout << candidates[i].r << " " << candidates[i].c << "\n";
        }
    }

    return 0;
}