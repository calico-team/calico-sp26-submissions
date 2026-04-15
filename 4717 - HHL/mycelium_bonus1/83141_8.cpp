#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// 定义扩散事件
struct Event {
    long long time;
    int x, y;
    int type; // 0 代表草 (Grass), 1 代表菌丝 (Mycelium)

    // 优先级队列排序：时间小的优先；时间相同时，类型小的（草）优先
    bool operator>(const Event& other) const {
        if (time != other.time) return time > other.time;
        return type > other.type;
    }
};

int main() {
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T_cases;
    if (!(cin >> T_cases)) return 0;

    while (T_cases--) {
        long long xg_raw, yg_raw, xm_raw, ym_raw;
        cin >> xg_raw >> yg_raw >> xm_raw >> ym_raw;

        // 设定网格偏移量和大小
        // 对于 Bonus 1，坐标范围在 [-200, 200]，扩散范围不会超过该范围太多
        // 我们取一个安全的 1000x1000 网格，中心点设在 500
        const int OFFSET = 500;
        const int SIZE = 1000;

        // grid 存储占领情况：-1 未占领, 0 草, 1 菌丝
        vector<vector<int>> grid(SIZE, vector<int>(SIZE, -1));

        // 优先级队列 (最小堆)
        priority_queue<Event, vector<Event>, greater<Event>> pq;

        // 初始位置
        int xg = (int)xg_raw + OFFSET;
        int yg = (int)yg_raw + OFFSET;
        int xm = (int)xm_raw + OFFSET;
        int ym = (int)ym_raw + OFFSET;

        // 初始状态加入队列
        pq.push({0, xg, yg, 0});
        pq.push({0, xm, ym, 1});

        long long mycelium_total = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            Event cur = pq.top();
            pq.pop();

            // 越界检查（安全保障）
            if (cur.x < 0 || cur.x >= SIZE || cur.y < 0 || cur.y >= SIZE) continue;

            // 如果该格子已被占领，跳过
            if (grid[cur.x][cur.y] != -1) continue;

            // 正式占领
            grid[cur.x][cur.y] = cur.type;
            if (cur.type == 1) {
                mycelium_total++;
            }

            // 向四周扩散
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
