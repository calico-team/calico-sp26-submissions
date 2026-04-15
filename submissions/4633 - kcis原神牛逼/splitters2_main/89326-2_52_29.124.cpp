#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;

const ll LIMIT = 1'000'000'000'000LL;

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

        // 二进制分裂器（2^A）
        for (int i = 1; i <= A; ++i) {
            ll val = safe_mul(pow2_lim(A - i), pow3_lim(B));
            bool collect = false;
            if (val <= LIMIT && cur >= val) {
                collect = true;
                cur -= val;
            }
            ops.push_back({ '2', {collect} });
        }

        // 三进制分裂器（3^B）
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
            if (cnt >= 1) coll[1] = true;
            if (cnt >= 2) coll[0] = true;
            ops.push_back({ '3', coll });
        }

        int K = ops.size();
        int N = K + 2;
        int M = 6;
        int main_col = 2;

        vector<string> grid(N, string(M, '.'));

        // 起始传送带（左上角）
        grid[0][main_col] = 'v';

        for (int i = 0; i < K; ++i) {
            int r = i + 1;
            char type = ops[i].first;
            vector<bool> flags = ops[i].second;

            // 确保物品能从上一行传到当前行
            if (i > 0) {
                grid[r - 1][main_col] = 'v';
            }

            // 分裂器
            grid[r][main_col] = 'S';

            // 左分支（三进制分裂器）
            if (type == '3') {
                bool left_coll = flags[0];
                grid[r][main_col - 1] = '<';
                grid[r][main_col - 2] = left_coll ? '<' : 'X';
            }

            // 右分支（二进制和三进制都有）
            bool right_coll = (type == '2') ? flags[0] : flags[1];
            grid[r][main_col + 1] = '>';
            grid[r][main_col + 2] = '>';
            grid[r][main_col + 3] = right_coll ? '>' : 'X';
        }

        // 主线剩余物品销毁
        grid[K + 1][main_col] = 'X';

        // 输出
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