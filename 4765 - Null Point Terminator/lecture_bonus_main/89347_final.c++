#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> t;
    BIT() {}
    BIT(int n): n(n), t(n + 1, 0) {}

    void add(int i, long long delta) {
        for (; i <= n; i += i & -i) t[i] += delta;
    }

    long long sum(int i) const {
        long long s = 0;
        for (; i > 0; i -= i & -i) s += t[i];
        return s;
    }

    int kth(long long k) const {
        int idx = 0;
        int bit = 1;
        while ((bit << 1) <= n) bit <<= 1;
        for (; bit; bit >>= 1) {
            int nxt = idx + bit;
            if (nxt <= n && t[nxt] < k) {
                idx = nxt;
                k -= t[nxt];
            }
        }
        return idx + 1;
    }
};

struct RowPoint {
    int v, aura, idx, r, c;
    bool operator<(const RowPoint& other) const {
        return v < other.v;
    }
};

struct ColPoint {
    int u, aura, idx;
    bool operator<(const ColPoint& other) const {
        return u < other.u;
    }
};

vector<pair<int,int>> solve(int N, int M, int K, const vector<string>& GRID) {
    int total = N + M - 1;
    int shift = M - 1;

    vector<vector<int>> seats(total);
    vector<tuple<int,int,int,int,int>> seat_list;
    vector<int> aura_vals;

    for (int r = 0; r < N; r++) {
        const string& row = GRID[r];
        int occ = 0;
        for (char ch : row) if (ch == '#') occ++;
        int left = 0;
        for (int c = 0; c < M; c++) {
            char ch = row[c];
            if (ch == '#') {
                left++;
            } else {
                int aura = min(left, occ - left);
                int u = r + c;
                int v = r - c + shift;
                seats[u].push_back(v);
                seat_list.emplace_back(u, v, aura, r, c);
                aura_vals.push_back(aura);
            }
        }
    }

    sort(aura_vals.begin(), aura_vals.end());
    aura_vals.erase(unique(aura_vals.begin(), aura_vals.end()), aura_vals.end());
    int A = (int)aura_vals.size();

    unordered_map<int,int> aura_id;
    aura_id.reserve(A * 2 + 1);
    for (int i = 0; i < A; i++) aura_id[aura_vals[i]] = i + 1;

    vector<vector<RowPoint>> row_points(total);
    vector<vector<ColPoint>> col_points(total);

    for (auto &[u, v, aura, r, c] : seat_list) {
        int idx = aura_id[aura];
        row_points[u].push_back({v, aura, idx, r, c});
        col_points[v].push_back({u, aura, idx});
    }

    vector<vector<int>> row_vs(total), col_us(total);

    for (int u = 0; u < total; u++) {
        sort(row_points[u].begin(), row_points[u].end());
        row_vs[u].reserve(row_points[u].size());
        for (auto &x : row_points[u]) row_vs[u].push_back(x.v);
    }

    for (int v = 0; v < total; v++) {
        sort(col_points[v].begin(), col_points[v].end());
        col_us[v].reserve(col_points[v].size());
        for (auto &x : col_points[v]) col_us[v].push_back(x.u);
    }

    auto find_any = [&](int d) -> pair<int,int> {
        int L = total - d;
        int w = d + 1;
        vector<int> cnt_v(total, 0);
        int right_u = -1;

        for (int left_u = 0; left_u < L; left_u++) {
            int lim = left_u + d;
            while (right_u < lim) {
                ++right_u;
                for (int v : seats[right_u]) cnt_v[v]++;
            }

            int cur = 0;
            for (int i = 0; i < w; i++) cur += cnt_v[i];
            if (cur >= K) return {left_u, 0};

            for (int sv = 1; sv < L; sv++) {
                cur += cnt_v[sv + w - 1] - cnt_v[sv - 1];
                if (cur >= K) return {left_u, sv};
            }

            for (int v : seats[left_u]) cnt_v[v]--;
        }
        return {-1, -1};
    };

    int lo = 0, hi = total - 1, best_d = total - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        auto res = find_any(mid);
        if (res.first != -1) {
            best_d = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    int w = best_d + 1;
    int L = total - best_d;

    BIT bit_cnt(A), bit_sum(A);

    auto add_point = [&](int idx, int aura) {
        bit_cnt.add(idx, 1);
        bit_sum.add(idx, aura);
    };

    auto remove_point = [&](int idx, int aura) {
        bit_cnt.add(idx, -1);
        bit_sum.add(idx, -aura);
    };

    auto kth_sum = [&](int k) -> long long {
        int p = bit_cnt.kth(k);
        long long cnt_before = bit_cnt.sum(p - 1);
        long long sum_before = bit_sum.sum(p - 1);
        long long val = aura_vals[p - 1];
        long long need = k - cnt_before;
        return sum_before + need * val;
    };

    long long cur_cnt = 0;
    int cur_v0 = 0;

    for (int u = 0; u < w; u++) {
        auto &arr = row_points[u];
        auto &vals = row_vs[u];
        int l = lower_bound(vals.begin(), vals.end(), 0) - vals.begin();
        int r = upper_bound(vals.begin(), vals.end(), best_d) - vals.begin();
        cur_cnt += (r - l);
        for (int i = l; i < r; i++) {
            add_point(arr[i].idx, arr[i].aura);
        }
    }

    long long best_sum = -1;
    pair<int,int> best_window = {-1, -1};

    for (int cur_u0 = 0; cur_u0 < L; cur_u0++) {
        if (cur_cnt >= K) {
            long long s = kth_sum(K);
            if (best_sum == -1 || s < best_sum) {
                best_sum = s;
                best_window = {cur_u0, cur_v0};
            }
        }

        if ((cur_u0 & 1) == 0) {
            while (cur_v0 + 1 < L) {
                int out_v = cur_v0;
                int in_v = cur_v0 + w;

                {
                    auto &uu = col_us[out_v];
                    auto &arr = col_points[out_v];
                    int l = lower_bound(uu.begin(), uu.end(), cur_u0) - uu.begin();
                    int r = upper_bound(uu.begin(), uu.end(), cur_u0 + best_d) - uu.begin();
                    cur_cnt -= (r - l);
                    for (int i = l; i < r; i++) {
                        remove_point(arr[i].idx, arr[i].aura);
                    }
                }

                {
                    auto &uu = col_us[in_v];
                    auto &arr = col_points[in_v];
                    int l = lower_bound(uu.begin(), uu.end(), cur_u0) - uu.begin();
                    int r = upper_bound(uu.begin(), uu.end(), cur_u0 + best_d) - uu.begin();
                    cur_cnt += (r - l);
                    for (int i = l; i < r; i++) {
                        add_point(arr[i].idx, arr[i].aura);
                    }
                }

                cur_v0++;

                if (cur_cnt >= K) {
                    long long s = kth_sum(K);
                    if (best_sum == -1 || s < best_sum) {
                        best_sum = s;
                        best_window = {cur_u0, cur_v0};
                    }
                }
            }
        } else {
            while (cur_v0 - 1 >= 0) {
                int out_v = cur_v0 + best_d;
                int in_v = cur_v0 - 1;

                {
                    auto &uu = col_us[out_v];
                    auto &arr = col_points[out_v];
                    int l = lower_bound(uu.begin(), uu.end(), cur_u0) - uu.begin();
                    int r = upper_bound(uu.begin(), uu.end(), cur_u0 + best_d) - uu.begin();
                    cur_cnt -= (r - l);
                    for (int i = l; i < r; i++) {
                        remove_point(arr[i].idx, arr[i].aura);
                    }
                }

                {
                    auto &uu = col_us[in_v];
                    auto &arr = col_points[in_v];
                    int l = lower_bound(uu.begin(), uu.end(), cur_u0) - uu.begin();
                    int r = upper_bound(uu.begin(), uu.end(), cur_u0 + best_d) - uu.begin();
                    cur_cnt += (r - l);
                    for (int i = l; i < r; i++) {
                        add_point(arr[i].idx, arr[i].aura);
                    }
                }

                cur_v0--;

                if (cur_cnt >= K) {
                    long long s = kth_sum(K);
                    if (best_sum == -1 || s < best_sum) {
                        best_sum = s;
                        best_window = {cur_u0, cur_v0};
                    }
                }
            }
        }

        if (cur_u0 + 1 == L) break;

        int out_u = cur_u0;
        int in_u = cur_u0 + w;
        int left_v = cur_v0;
        int right_v = cur_v0 + best_d;

        {
            auto &arr = row_points[out_u];
            auto &vals = row_vs[out_u];
            int l = lower_bound(vals.begin(), vals.end(), left_v) - vals.begin();
            int r = upper_bound(vals.begin(), vals.end(), right_v) - vals.begin();
            cur_cnt -= (r - l);
            for (int i = l; i < r; i++) {
                remove_point(arr[i].idx, arr[i].aura);
            }
        }

        {
            auto &arr = row_points[in_u];
            auto &vals = row_vs[in_u];
            int l = lower_bound(vals.begin(), vals.end(), left_v) - vals.begin();
            int r = upper_bound(vals.begin(), vals.end(), right_v) - vals.begin();
            cur_cnt += (r - l);
            for (int i = l; i < r; i++) {
                add_point(arr[i].idx, arr[i].aura);
            }
        }
    }

    int u0 = best_window.first;
    int v0 = best_window.second;
    int v1 = v0 + best_d;

    vector<tuple<int,int,int>> cand;
    for (int u = u0; u < u0 + w; u++) {
        auto &arr = row_points[u];
        auto &vals = row_vs[u];
        int l = lower_bound(vals.begin(), vals.end(), v0) - vals.begin();
        int r = upper_bound(vals.begin(), vals.end(), v1) - vals.begin();
        for (int i = l; i < r; i++) {
            cand.emplace_back(arr[i].aura, arr[i].r, arr[i].c);
        }
    }

    sort(cand.begin(), cand.end());

    vector<pair<int,int>> ans;
    ans.reserve(K);
    for (int i = 0; i < K; i++) {
        ans.push_back({get<1>(cand[i]), get<2>(cand[i])});
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> GRID(N);
        for (int i = 0; i < N; i++) cin >> GRID[i];

        auto ans = solve(N, M, K, GRID);
        for (auto &[r, c] : ans) {
            cout << r << ' ' << c << '\n';
        }
    }
    return 0;
}