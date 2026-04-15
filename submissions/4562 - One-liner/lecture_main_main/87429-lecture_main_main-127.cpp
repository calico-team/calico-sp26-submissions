#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Point {
    int r, c;
};


void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    vector<string> grid(N);
    vector<Point> available;
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '-') available.push_back({i, j});
        }
    }

    // 1. Calculate Aura Loss
    vector<vector<int>> aura(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        vector<int> left(M), right(M);
        int count = 0;
        for (int j = 0; j < M; ++j) {
            left[j] = count;
            if (grid[i][j] == '#') count++;
        }
        count = 0;
        for (int j = M - 1; j >= 0; --j) {
            right[j] = count;
            if (grid[i][j] == '#') count++;
        }
        for (int j = 0; j < M; ++j) {
            aura[i][j] = min(left[j], right[j]);
        }
    }

    int min_max_d = INT_MAX;
    long long min_aura_sum = LLONG_MAX;
    vector<Point> best_set;

    // 2. Sample Seeds - Use size_t for unsigned comparisons
    size_t num_seeds = 150; 
    size_t step = max((size_t)1, available.size() / num_seeds);

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    for (size_t s = 0; s < available.size(); s += step) {
        Point seed = available[s];
        vector<Point> cluster;
        queue<Point> q;
        q.push(seed);
        
        // Using a single vector for visited is faster than vector of vectors
        vector<int> visited(N * M, 0);
        visited[seed.r * M + seed.c] = 1;

        long long current_aura = 0;
        int min_rc = INT_MAX, max_rc = INT_MIN;
        int min_rmc = INT_MAX, max_rmc = INT_MIN;

        while (!q.empty() && cluster.size() < (size_t)K) {
            Point curr = q.front();
            q.pop();

            if (grid[curr.r][curr.c] == '-') {
                cluster.push_back(curr);
                current_aura += aura[curr.r][curr.c];
                min_rc = min(min_rc, curr.r + curr.c);
                max_rc = max(max_rc, curr.r + curr.c);
                min_rmc = min(min_rmc, curr.r - curr.c);
                max_rmc = max(max_rmc, curr.r - curr.c);
            }

            for (int i = 0; i < 4; ++i) {
                int nr = curr.r + dr[i];
                int nc = curr.c + dc[i];
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr * M + nc]) {
                    visited[nr * M + nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        if (cluster.size() == (size_t)K) {
            int current_max_d = max(max_rc - min_rc, max_rmc - min_rmc);
            if (current_max_d < min_max_d || (current_max_d == min_max_d && current_aura < min_aura_sum)) {
                min_max_d = current_max_d;
                min_aura_sum = current_aura;
                best_set = cluster;
            }
        }
        if (min_max_d <= 1) break; 
    }

    for (const auto& p : best_set) {
        cout << p.r << " " << p.c << "\n";
    }
}

// Requirement: read_your_input
void read_your_input() {
    int T;
    if (!(cin >> T)) return;
    while (T--) {
        solve();
    }
}

int main() {
    // Fast I/O is critical for 10^6 constraints
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_your_input();
    return 0;
}