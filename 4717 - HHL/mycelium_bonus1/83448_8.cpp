#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Event {
    long long time;
    int x, y;
    int type;

    bool operator>(const Event& other) const {
        if (time != other.time) return time > other.time;
        return type > other.type;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T_cases;
    if (!(cin >> T_cases)) return 0;

    while (T_cases--) {
        long long xg_raw, yg_raw, xm_raw, ym_raw;
        cin >> xg_raw >> yg_raw >> xm_raw >> ym_raw;

        const int OFFSET = 500;
        const int SIZE = 1000;

        vector<vector<int>> grid(SIZE, vector<int>(SIZE, -1));

        priority_queue<Event, vector<Event>, greater<Event>> pq;

        int xg = (int)xg_raw + OFFSET;
        int yg = (int)yg_raw + OFFSET;
        int xm = (int)xm_raw + OFFSET;
        int ym = (int)ym_raw + OFFSET;

        pq.push({0, xg, yg, 0});
        pq.push({0, xm, ym, 1});

        long long mycelium_total = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            Event cur = pq.top();
            pq.pop();

            if (cur.x < 0 || cur.x >= SIZE || cur.y < 0 || cur.y >= SIZE) continue;

            if (grid[cur.x][cur.y] != -1) continue;

            grid[cur.x][cur.y] = cur.type;
            if (cur.type == 1) {
                mycelium_total++;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                    if (grid[nx][ny] == -1) {
                        long long next_time = cur.time + (cur.type == 0 ? 2 : 7);
                        pq.push({next_time, nx, ny, cur.type});
                    }
                }
            }
        }

        cout << mycelium_total << endl;
    }

    return 0;
}
