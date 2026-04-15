#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Seat {
    int r, c;
};

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<string> grid(N);
    vector<Seat> available;
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '-') {
                available.push_back({i, j});
            }
        }
    }

    if (K == 0) return;

    vector<Seat> best_set;
    int min_max_dist = 2e9;
    long long min_aura = 1e18;

    for (auto& start : available) {
        vector<Seat> current_set;
        queue<pair<int, int>> q;
        vector<vector<int>> dist(N, vector<int>(M, -1));

        q.push({start.r, start.c});
        dist[start.r][start.c] = 0;
        
        int local_max_dist = 0;
        long long local_aura = 0;

        while (!q.empty() && current_set.size() < K) {
            pair<int, int> curr = q.front();
            q.pop();

            current_set.push_back({curr.first, curr.second});
            local_max_dist = max(local_max_dist, dist[curr.first][curr.second]);
            local_aura += (curr.first + curr.second); 

            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};

            for (int i = 0; i < 4; ++i) {
                int nr = curr.first + dr[i];
                int nc = curr.second + dc[i];
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] == '-' && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[curr.first][curr.second] + 1;
                    q.push({nr, nc});
                }
            }
        }

        if (local_max_dist < min_max_dist || (local_max_dist == min_max_dist && local_aura < min_aura)) {
            min_max_dist = local_max_dist;
            min_aura = local_aura;
            best_set = current_set;
        }
        
        if (min_max_dist <= 1 && K <= 2) break; 
    }

    for (const auto& s : best_set) {
        cout << s.r << " " << s.c << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}