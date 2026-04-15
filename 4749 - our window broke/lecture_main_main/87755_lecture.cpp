#include <bits/stdc++.h>
using namespace std;

struct Point {
    int u, v, aura, r, c;
};
struct BIT {
    int n;
    vector<int> cnt;
    vector<long long> sum;
    BIT(int size) : n(size + 2), cnt(size + 2, 0), sum(size + 2, 0) {}
    void add(int idx, int delta) {
        int i = idx + 1;
        while (i < (int)cnt.size()) {
            cnt[i] += delta;
            sum[i] += delta * idx;
            i += i & -i;
        }
    }
    int prefix_cnt(int idx) {
        if (idx < 0) return 0;
        int i = idx + 1, res = 0;
        while (i > 0) {
            res += cnt[i];
            i -= i & -i;
        }
        return res;
    }
    long long prefix_sum(int idx) {
        if (idx < 0) return 0;
        int i = idx + 1;
        long long res = 0;
        while (i > 0) {
            res += sum[i];
            i -= i & -i;
        }
        return res;
    }
    int total_cnt() { return prefix_cnt(n - 2); }
    int kth(int k) {
        int idx = 0;
        int bit_mask = 1 << (20);
        while (bit_mask) {
            int nxt = idx + bit_mask;
            if (nxt < (int)cnt.size() && cnt[nxt] < k) {
                k -= cnt[nxt];
                idx = nxt;
            }
            bit_mask >>= 1;
        }
        return idx;
    }
};

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> grid(N);
        for (int i = 0; i < N; ++i) cin >> grid[i];
        vector<vector<int>> occ_prefix(N, vector<int>(M + 1, 0));
        vector<int> total_occ(N, 0);
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                occ_prefix[r][c + 1] = occ_prefix[r][c] + (grid[r][c] == '#' ? 1 : 0);
            }
            total_occ[r] = occ_prefix[r][M];
        }

        vector<Point> pts;
        int min_u = 1e9, max_u = -1e9, min_v = 1e9, max_v = -1e9;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (grid[r][c] == '-') {
                    int left = occ_prefix[r][c];
                    int right = total_occ[r] - occ_prefix[r][c + 1];
                    int aura = min(left, right);
                    int u = r + c;
                    int v = r - c;
                    pts.push_back({u, v, aura, r, c});
                    min_u = min(min_u, u);
                    max_u = max(max_u, u);
                    min_v = min(min_v, v);
                    max_v = max(max_v, v);
                }
            }
        }

        if (pts.empty()) {
            for (int i = 0; i < K; ++i) cout << "0 0\n";
            continue;
        }

        sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) { return a.u < b.u; });

        int u_range = max_u - min_u;
        int v_range = max_v - min_v;

        auto can = [&](int D) -> bool {
            int v_len = max_v - min_v + 1;
            vector<int> cnt_v(v_len, 0);
            int left = 0, right = 0;
            int n = pts.size();
            for (int u_low = min_u; u_low <= max_u - D; ++u_low) {
                int u_high = u_low + D;
                while (right < n && pts[right].u <= u_high) {
                    int v_idx = pts[right].v - min_v;
                    cnt_v[v_idx]++;
                    right++;
                }
                while (left < n && pts[left].u < u_low) {
                    int v_idx = pts[left].v - min_v;
                    cnt_v[v_idx]--;
                    left++;
                }
                if (D >= v_range) {
                    int total = accumulate(cnt_v.begin(), cnt_v.end(), 0);
                    if (total >= K) return true;
                } else {
                    int window_sum = 0;
                    for (int i = 0; i <= D; ++i) window_sum += cnt_v[i];
                    if (window_sum >= K) return true;
                    for (int v_low = 1; v_low + D < v_len; ++v_low) {
                        window_sum = window_sum - cnt_v[v_low - 1] + cnt_v[v_low + D];
                        if (window_sum >= K) return true;
                    }
                }
            }
            return false;
        };

        int lo = 0, hi = max(u_range, v_range);
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (can(mid)) hi = mid;
            else lo = mid + 1;
        }
        int D_min = lo;

        int u_len = max_u - min_u + 1;
        int u_off = min_u;
        vector<vector<pair<int, int>>> points_by_u(u_len);
        for (const auto& p : pts) {
            points_by_u[p.u - u_off].emplace_back(p.v, p.aura);
        }

        int v_off = min_v;
        int v_len = max_v - min_v + 1;
        int max_aura = M;

        long long best_sum = 1e18;
        int best_u_low = -1, best_v_low = -1;
        for (int u_low = min_u; u_low <= max_u - D_min; ++u_low) {
            int u_high = u_low + D_min;
            vector<pair<int, int>> strip;
            for (int u_val = u_low; u_val <= u_high; ++u_val) {
                int idx = u_val - u_off;
                if (idx >= 0 && idx < u_len) {
                    for (auto& pv : points_by_u[idx]) {
                        strip.push_back(pv);
                    }
                }
            }
            if (strip.empty()) continue;
            sort(strip.begin(), strip.end());

            int left = 0, right = 0;
            int n_strip = strip.size();
            BIT bit(max_aura);
            int v_low = min_v;
            int v_high = v_low + D_min;
            while (right < n_strip && strip[right].first <= v_high) {
                bit.add(strip[right].second, 1);
                right++;
            }
            int total = bit.total_cnt();
            if (total >= K) {
                int need = K;
                int lo_a = 0, hi_a = max_aura;
                while (lo_a < hi_a) {
                    int mid_a = (lo_a + hi_a) / 2;
                    if (bit.prefix_cnt(mid_a) >= need) hi_a = mid_a;
                    else lo_a = mid_a + 1;
                }
                int thresh = lo_a;
                int cnt_less = bit.prefix_cnt(thresh - 1);
                long long sum_less = bit.prefix_sum(thresh - 1);
                long long cur_sum = sum_less + (need - cnt_less) * 1LL * thresh;
                if (cur_sum < best_sum) {
                    best_sum = cur_sum;
                    best_u_low = u_low;
                    best_v_low = v_low;
                    if (best_sum == 0) break;
                }
            }
            for (int v_low = min_v + 1; v_low <= max_v - D_min; ++v_low) {
                v_high = v_low + D_min;
                while (left < right && strip[left].first < v_low) {
                    bit.add(strip[left].second, -1);
                    left++;
                }
                while (right < n_strip && strip[right].first <= v_high) {
                    bit.add(strip[right].second, 1);
                    right++;
                }
                total = bit.total_cnt();
                if (total >= K) {
                    int need = K;
                    int lo_a = 0, hi_a = max_aura;
                    while (lo_a < hi_a) {
                        int mid_a = (lo_a + hi_a) / 2;
                        if (bit.prefix_cnt(mid_a) >= need) hi_a = mid_a;
                        else lo_a = mid_a + 1;
                    }
                    int thresh = lo_a;
                    int cnt_less = bit.prefix_cnt(thresh - 1);
                    long long sum_less = bit.prefix_sum(thresh - 1);
                    long long cur_sum = sum_less + (need - cnt_less) * 1LL * thresh;
                    if (cur_sum < best_sum) {
                        best_sum = cur_sum;
                        best_u_low = u_low;
                        best_v_low = v_low;
                        if (best_sum == 0) break;
                    }
                }
            }
            if (best_sum == 0) break;
        }

        int u_low = best_u_low, u_high = u_low + D_min;
        int v_low = best_v_low, v_high = v_low + D_min;
        vector<tuple<int, int, int>> candidates;
        for (const auto& p : pts) {
            if (p.u >= u_low && p.u <= u_high && p.v >= v_low && p.v <= v_high) {
                candidates.emplace_back(p.aura, p.r, p.c);
            }
        }
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < K; ++i) {
            auto [aura, r, c] = candidates[i];
            cout << r << " " << c << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}