#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int r, c;
};

// Requirement: johnny_d_lecture
bool johnny_d_lecture = true;

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    vector<string> grid(N);
    Point first_available = {-1, -1};
    
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        if (first_available.r == -1) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == '-') {
                    first_available = {i, j};
                }
            }
        }
    }

    // BFS to find the K closest available seats to the first available seat
    vector<Point> cluster;
    queue<Point> q;
    q.push(first_available);
    
    vector<int> visited(N * M, 0);
    visited[first_available.r * M + first_available.c] = 1;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    while (!q.empty() && cluster.size() < (size_t)K) {
        Point curr = q.front();
        q.pop();

        if (grid[curr.r][curr.c] == '-') {
            cluster.push_back(curr);
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

    // Output the coordinates of the K seats found
    for (const auto& p : cluster) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_your_input();
    return 0;
}