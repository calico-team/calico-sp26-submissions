#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Seat {
    int r, c, u, v;
    int aura;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> grid(N);
        vector<Seat> avail;
        for (int i = 0; i < N; ++i) {
            cin >> grid[i];
            vector<int> left_occ(M, 0), right_occ(M, 0);
            int cur = 0;
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == '#') cur++;
                else left_occ[j] = cur;
            }
            cur = 0;
            for (int j = M - 1; j >= 0; --j) {
                if (grid[i][j] == '#') cur++;
                else {
                    right_occ[j] = cur;
                    int a = min(left_occ[j], right_occ[j]);
                    // 坐标转换: u = r+c, v = r-c
                    // 为了让 v 非负，加上偏移量 M
                    avail.push_back({i, j, i + j, i - j + M, a});
                }
            }
        }

        int S = N + M + 2;
        vector<vector<int>> pref(S + 1, vector<int>(S + 1, 0));
        for (auto &s : avail) pref[s.u + 1][s.v + 1]++;

        for (int i = 1; i <= S; ++i) {
            for (int j = 1; j <= S; ++j) {
                pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        auto count_in = [&](int u1, int v1, int u2, int v2) {
            u1 = max(1, u1 + 1); v1 = max(1, v1 + 1);
            u2 = min(S, u2 + 1); v2 = min(S, v2 + 1);
            if (u1 > u2 || v1 > v2) return 0;
            return pref[u2][v2] - pref[u1 - 1][v2] - pref[u2][v1 - 1] + pref[u1 - 1][v1 - 1];
        };

        // 1. 二分查找最小 D
        int low = 0, high = N + M, D = N + M;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool ok = false;
            for (auto &s : avail) {
                if (count_in(s.u, s.v, s.u + mid, s.v + mid) >= K) { ok = true; break; }
                if (count_in(s.u - mid, s.v, s.u, s.v + mid) >= K) { ok = true; break; }
                if (count_in(s.u, s.v - mid, s.u + mid, s.v) >= K) { ok = true; break; }
                if (count_in(s.u - mid, s.v - mid, s.u, s.v) >= K) { ok = true; break; }
            }
            if (ok) { D = mid; high = mid - 1; }
            else low = mid + 1;
        }

        // 2. 寻找最优窗口（满足 D 且总 Aura 最小）
        long long min_total_aura = -1;
        int best_u = -1, best_v = -1;

        // 只需要检查以现有座位为边界的窗口
        for (auto &s : avail) {
            int us[] = {s.u, s.u - D};
            int vs[] = {s.v, s.v - D};
            for (int ui : us) {
                for (int vi : vs) {
                    if (count_in(ui, vi, ui + D, vi + D) >= K) {
                        vector<int> auras;
                        for (auto &p : avail) {
                            if (p.u >= ui && p.u <= ui + D && p.v >= vi && p.v <= vi + D)
                                auras.push_back(p.aura);
                        }
                        sort(auras.begin(), auras.end());
                        long long cur_sum = 0;
                        for (int i = 0; i < K; ++i) cur_sum += auras[i];
                        
                        if (min_total_aura == -1 || cur_sum < min_total_aura) {
                            min_total_aura = cur_sum;
                            best_u = ui; best_v = vi;
                        }
                    }
                }
            }
        }

        // 输出结果
        vector<Seat> final_set;
        for (auto &p : avail) {
            if (p.u >= best_u && p.u <= best_u + D && p.v >= best_v && p.v <= best_v + D)
                final_set.push_back(p);
        }
        sort(final_set.begin(), final_set.end(), [](const Seat &a, const Seat &b) {
            return a.aura < b.aura;
        });

        for (int i = 0; i < K; ++i) {
            cout << final_set[i].r << " " << final_set[i].c << "\n";
        }
    }
    return 0;
}