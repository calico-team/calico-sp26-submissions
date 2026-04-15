#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<string> grid;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int bfs_count(pair<int,int> start, int D, vector<vector<int>> &vis) {
    queue<pair<int,int>> q;
    q.push(start);

    vector<vector<int>> seen(n, vector<int>(m, 0));
    seen[start.first][start.second] = 1;

    int cnt = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !seen[nx][ny]) {
                if (grid[nx][ny] == '-' &&
                    abs(nx - start.first) + abs(ny - start.second) <= D) {

                    seen[nx][ny] = 1;
                    q.push({nx, ny});
                    cnt++;

                    if (cnt >= k) return cnt;
                }
            }
        }
    }

    return cnt;
}

bool feasible(int D, vector<pair<int,int>> &empties, pair<int,int> &best_start) {
    for (auto start : empties) {
        vector<vector<int>> dummy;
        if (bfs_count(start, D, dummy) >= k) {
            best_start = start;
            return true;
        }
    }
    return false;
}

vector<pair<int,int>> build_answer(pair<int,int> start, int D) {
    queue<pair<int,int>> q;
    q.push(start);

    vector<vector<int>> seen(n, vector<int>(m, 0));
    seen[start.first][start.second] = 1;

    vector<pair<int,int>> res;
    res.push_back(start);

    while (!q.empty() && (int)res.size() < k) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !seen[nx][ny]) {
                if (grid[nx][ny] == '-' &&
                    abs(nx - start.first) + abs(ny - start.second) <= D) {

                    seen[nx][ny] = 1;
                    q.push({nx, ny});
                    res.push_back({nx, ny});

                    if ((int)res.size() == k) return res;
                }
            }
        }
    }

    return res;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m >> k;

        grid.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        vector<pair<int,int>> empties;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '-') {
                    empties.push_back({i, j});
                }
            }
        }

        if (k == 1) {
            cout << empties[0].first << " " << empties[0].second << "\n";
            continue;
        }

        int lo = 0, hi = n + m;
        pair<int,int> best_start = {-1, -1};
        int best_D = -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            pair<int,int> start;
            bool ok = feasible(mid, empties, start);

            if (ok) {
                best_start = start;
                best_D = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if (best_start.first == -1) {
            for (int i = 0; i < k; i++) {
                cout << empties[i].first << " " << empties[i].second << "\n";
            }
            continue;
        }

        vector<pair<int,int>> ans = build_answer(best_start, best_D);

        for (auto &p : ans) {
            cout << p.first << " " << p.second << "\n";
        }
    }
}

int main() {
    solve();
    return 0;
}