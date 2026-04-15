#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;

const ll LIMIT = 1'000'000'000'000LL; // 1e12

ll safe_mul(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    if (a > LIMIT / b) return LIMIT + 1;
    return a * b;
}

ll pow2_lim(int e) {
    ll res = 1;
    for (int i = 0; i < e; ++i) {
        res = safe_mul(res, 2);
        if (res > LIMIT) return LIMIT + 1;
    }
    return res;
}

ll pow3_lim(int e) {
    ll res = 1;
    for (int i = 0; i < e; ++i) {
        res = safe_mul(res, 3);
        if (res > LIMIT) return LIMIT + 1;
    }
    return res;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        ll P;
        int A, B;
        cin >> P >> A >> B;

        vector<pair<char, vector<bool>>> ops;
        ll cur = P;

        // 二进制分裂器（每次将流量平分到两条路径）
        for (int i = 1; i <= A; ++i) {
            ll val = safe_mul(pow2_lim(A - i), pow3_lim(B));
            bool collect = false;
            if (val <= LIMIT && cur >= val) {
                collect = true;
                cur -= val;
            }
            ops.push_back({ '2', {collect} });
        }

        // 三进制分裂器（每次将流量平分到三条路径，我们只使用左右两条，中间主线延续）
        for (int j = 1; j <= B; ++j) {
            ll unit = safe_mul(pow2_lim(A), pow3_lim(B - j));
            int cnt = 0;
            if (unit <= LIMIT) {
                while (cnt < 2 && cur >= unit) {
                    cur -= unit;
                    ++cnt;
                }
            }
            vector<bool> coll(2, false);
            if (cnt >= 1) coll[1] = true; // 右分支收集
            if (cnt >= 2) coll[0] = true; // 左分支收集
            ops.push_back({ '3', coll });
        }

        int K = ops.size();                // 分裂器总数
        int N = K + 2;                     // 行数：起始行 + K 行分裂器 + 末尾销毁行
        int M = 5;                         // 列数（紧凑设计）
        int main_col = 2;                  // 中央垂直列

        vector<string> grid(N, string(M, '.'));

        // 起点 (0, main_col)，物品从上方进入
        grid[0][main_col] = 'v';

        for (int i = 0; i < K; ++i) {
            int r = i + 1;                 // 当前分裂器所在行
            char type = ops[i].first;
            vector<bool> flags = ops[i].second;

            // 上一行的向下传送带（第一行已经设好）
            if (i > 0) {
                grid[r - 1][main_col] = 'v';
            }

            // 放置分裂器
            grid[r][main_col] = 'S';

            // 向下的延续（如果不是最后一个分裂器）
            if (i < K - 1) {
                grid[r + 1][main_col] = 'v';
            }

            // 左分支（仅 3 分裂器有）
            if (type == '3') {
                bool left_coll = flags[0];
                grid[r][main_col - 1] = '<';
                for (int c = main_col - 2; c > 0; --c) {
                    grid[r][c] = '<';
                }
                grid[r][0] = left_coll ? '<' : 'X';
            }

            // 右分支（2 分裂器和 3 分裂器都有）
            bool right_coll = (type == '2') ? flags[0] : flags[1];
            grid[r][main_col + 1] = '>';
            for (int c = main_col + 2; c < M - 1; ++c) {
                grid[r][c] = '>';
            }
            grid[r][M - 1] = right_coll ? '>' : 'X';
        }

        // 最后主线上剩余的物品进入销毁格
        grid[K + 1][main_col] = 'X';

        // 输出工厂（格式与题目要求完全一致）
        cout << N << " " << M << "\n";
        for (int i = 0; i < N; ++i) {
            cout << grid[i] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}