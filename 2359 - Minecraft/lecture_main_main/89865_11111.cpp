#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Seat {
    int r, c;
    int aura;
};

// 计算单个座位的 Aura Loss
int get_aura(int r, int c, int M, const string& row) {
    int left = 0, right = 0;
    for (int j = 0; j < c; ++j) if (row[j] == '#') left++;
    for (int j = c + 1; j < M; ++j) if (row[j] == '#') right++;
    return min(left, right);
}

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;

    vector<string> grid(N);
    vector<Seat> avail;
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '-') {
                avail.push_back({i, j, get_aura(i, j, M, grid[i])});
            }
        }
    }

    // 1. 寻找最小的最大曼哈顿距离 D
    // 对于 N, M <= 1000, 必须用转换坐标 + 二分 + 前缀和
    // 但为了确保处理像 2 7 2 这样的细微逻辑，我们在确定 D 后
    // 必须在所有满足 D 的窗口中找 Aura 最小的。

    int S = N + M + 2;
    vector<vector<int>> pref(S, vector<int>(S, 0));
    for (auto& s : avail) {
        pref[s.r + s.c + 1][s.r - s.c + M + 1]++;
    }

    for (int i = 1; i < S; ++i) {
        for (int j = 1; j < S; ++j) {
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    auto query = [&](int r1, int c1, int r2, int c2) {
        if (r1 > r2 || c1 > c2) return 0;
        return pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1];
    };

    int low = 0, high = N + M, D = N + M;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        bool ok = false;
        for (auto& s : avail) {
            // 检查以 s 为顶点的四种窗口可能
            int u = s.r + s.c + 1, v = s.r - s.c + M + 1;
            if (query(u, v, u + mid, v + mid) >= K ||
                query(u - mid, v, u, v + mid) >= K ||
                query(u, v - mid, u + mid, v) >= K ||
                query(u - mid, v - mid, u, v) >= K) {
                ok = true; break;
            }
        }
        if (ok) { D = mid; high = mid - 1; }
        else low = mid + 1;
    }

    // 2. 在所有满足距离 D 的窗口中，找 Aura 损失最小的
    long long min_aura_sum = -1;
    int best_u = -1, best_v = -1;

    for (auto& s : avail) {
        int us[] = {s.r + s.c + 1, s.r + s.c + 1 - D};
        int vs[] = {s.r - s.c + M + 1, s.r - s.c + M + 1 - D};
        for (int ui : us) {
            for (int vi : vs) {
                if (ui < 1 || vi < 1 || ui + D >= S || vi + D >= S) continue;
                if (query(ui, vi, ui + D, vi + D) >= K) {
                    vector<int> window_auras;
                    for (auto& p : avail) {
                        int pu = p.r + p.c + 1, pv = p.r - p.c + M + 1;
                        if (pu >= ui && pu <= ui + D && pv >= vi && pv <= vi + D) {
                            window_auras.push_back(p.aura);
                        }
                    }
                    sort(window_auras.begin(), window_auras.end());
                    long long current_aura = 0;
                    for (int i = 0; i < K; ++i) current_aura += window_auras[i];
                    
                    if (min_aura_sum == -1 || current_aura < min_aura_sum) {
                        min_aura_sum = current_aura;
                        best_u = ui; best_v = vi;
                    }
                }
            }
        }
    }

    // 3. 输出最终结果
    vector<Seat> result;
    for (auto& s : avail) {
        int pu = s.r + s.c + 1, pv = s.r - s.c + M + 1;
        if (pu >= best_u && pu <= best_u + D && pv >= best_v && pv <= best_v + D) {
            result.push_back(s);
        }
    }
    sort(result.begin(), result.end(), [](const Seat& a, const Seat& b) {
        if (a.aura != b.aura) return a.aura < b.aura;
        if (a.r != b.r) return a.r < b.r;
        return a.c < b.c;
    });

    for (int i = 0; i < K; ++i) {
        cout << result[i].r << " " << result[i].c << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) while (T--) solve();
    return 0;
}