#include <bits/stdc++.h>
using namespace std;

struct SeatNode {
    int r;
    int c;
    int u;
    int v;
    int aura;
    int nxt;
    int prv;
};

struct FenwickPack {
    int n;
    vector<int> bit_cnt;
    vector<long long> bit_sum;

    FenwickPack() {}
    FenwickPack(int sz) { init(sz); }

    void init(int sz) {
        n = sz;
        bit_cnt.assign(n + 1, 0);
        bit_sum.assign(n + 1, 0);
    }

    void add_one(int idx, int delta) {
        int pos = idx + 1;
        long long val = 1LL * idx * delta;
        for (int x = pos; x <= n; x += x & -x) {
            bit_cnt[x] += delta;
            bit_sum[x] += val;
        }
    }

    int total_cnt() const {
        int res = 0;
        for (int x = n; x > 0; x -= x & -x) res += bit_cnt[x];
        return res;
    }

    long long total_sum() const {
        long long res = 0;
        for (int x = n; x > 0; x -= x & -x) res += bit_sum[x];
        return res;
    }

    int kth_index(int need) const {
        int pos = 0;
        int acc = 0;
        int jump = 1;
        while ((jump << 1) <= n) jump <<= 1;
        for (int step = jump; step > 0; step >>= 1) {
            int np = pos + step;
            if (np <= n && acc + bit_cnt[np] < need) {
                pos = np;
                acc += bit_cnt[np];
            }
        }
        return pos;
    }

    int count_prefix(int idx) const {
        int pos = idx + 1;
        int res = 0;
        for (int x = pos; x > 0; x -= x & -x) res += bit_cnt[x];
        return res;
    }

    long long sum_prefix(int idx) const {
        int pos = idx + 1;
        long long res = 0;
        for (int x = pos; x > 0; x -= x & -x) res += bit_sum[x];
        return res;
    }

    long long smallest_k_sum(int need) const {
        if (need <= 0) return 0;
        int spot = kth_index(need);
        int have = 0;
        long long taken = 0;
        for (int x = spot; x > 0; x -= x & -x) {
            have += bit_cnt[x];
            taken += bit_sum[x];
        }
        int left = need - have;
        return taken + 1LL * left * spot;
    }
};

static int area_count(const vector<vector<int>>& pref, int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return 0;
    return pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
}

vector<pair<int, int>> solve(int M, int N, int K, vector<string>& GRID) {
    vector<vector<int>> left_block(M, vector<int>(N, 0));
    vector<vector<int>> right_block(M, vector<int>(N, 0));
    vector<SeatNode> all_open;
    int shift_v = N - 1;
    int span = M + N - 1;
    int best_aura_cap = N;

    for (int r = 0; r < M; r++) {
        int seen_left = 0;
        for (int c = 0; c < N; c++) {
            left_block[r][c] = seen_left;
            if (GRID[r][c] == '#') seen_left++;
        }
        int seen_right = 0;
        for (int c = N - 1; c >= 0; c--) {
            right_block[r][c] = seen_right;
            if (GRID[r][c] == '#') seen_right++;
        }
    }

    vector<vector<int>> mark(span, vector<int>(span, 0));
    vector<vector<int>> by_u(span);

    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            if (GRID[r][c] != '-') continue;
            int aura_here = min(left_block[r][c], right_block[r][c]);
            int up_key = r + c;
            int down_key = r - c + shift_v;
            int id = (int)all_open.size();
            all_open.push_back({r, c, up_key, down_key, aura_here, -1, -1});
            mark[up_key][down_key] = 1;
            by_u[up_key].push_back(id);
            best_aura_cap = max(best_aura_cap, aura_here);
        }
    }

    vector<vector<int>> pref(span + 1, vector<int>(span + 1, 0));
    for (int i = 0; i < span; i++) {
        for (int j = 0; j < span; j++) {
            pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + mark[i][j];
        }
    }

    auto window_ok = [&](int lim) {
        int ways_u = max(1, span - lim);
        int ways_v = max(1, span - lim);
        for (int su = 0; su < ways_u; su++) {
            int eu = min(span - 1, su + lim);
            for (int sv = 0; sv < ways_v; sv++) {
                int ev = min(span - 1, sv + lim);
                if (area_count(pref, su, sv, eu, ev) >= K) return true;
            }
        }
        return false;
    };

    int low = 0;
    int high = span - 1;
    while (low < high) {
        int mid = (low + high) >> 1;
        if (window_ok(mid)) high = mid;
        else low = mid + 1;
    }
    int best_dist = low;

    int ways_u = max(1, span - best_dist);
    int ways_v = max(1, span - best_dist);

    vector<int> head_in_col(span, -1);
    vector<char> active((int)all_open.size(), 0);

    auto add_band_point = [&](int id) {
        int col = all_open[id].v;
        all_open[id].prv = -1;
        all_open[id].nxt = head_in_col[col];
        if (head_in_col[col] != -1) all_open[head_in_col[col]].prv = id;
        head_in_col[col] = id;
        active[id] = 1;
    };

    auto remove_band_point = [&](int id) {
        if (!active[id]) return;
        int col = all_open[id].v;
        int p = all_open[id].prv;
        int n = all_open[id].nxt;
        if (p != -1) all_open[p].nxt = n;
        else head_in_col[col] = n;
        if (n != -1) all_open[n].prv = p;
        active[id] = 0;
    };

    auto use_column = [&](FenwickPack& bag, int col, int delta, int& live_cnt) {
        for (int cur = head_in_col[col]; cur != -1; cur = all_open[cur].nxt) {
            bag.add_one(all_open[cur].aura, delta);
            live_cnt += delta;
        }
    };

    long long best_cost = (1LL << 62);
    int chosen_u = 0;
    int chosen_v = 0;

    int start_u_hi = min(span - 1, best_dist);
    for (int u = 0; u <= start_u_hi; u++) {
        for (int id : by_u[u]) add_band_point(id);
    }

    for (int su = 0; su < ways_u; su++) {
        FenwickPack aura_box(best_aura_cap + 1);
        int live_cnt = 0;

        int first_v_hi = min(span - 1, best_dist);
        for (int v = 0; v <= first_v_hi; v++) {
            use_column(aura_box, v, 1, live_cnt);
        }

        for (int sv = 0; sv < ways_v; sv++) {
            if (live_cnt >= K) {
                long long got = aura_box.smallest_k_sum(K);
                if (got < best_cost) {
                    best_cost = got;
                    chosen_u = su;
                    chosen_v = sv;
                }
            }

            if (sv + 1 < ways_v) {
                use_column(aura_box, sv, -1, live_cnt);
                int nv = sv + best_dist + 1;
                if (nv < span) use_column(aura_box, nv, 1, live_cnt);
            }
        }

        if (su + 1 < ways_u) {
            for (int id : by_u[su]) remove_band_point(id);
            int nu = su + best_dist + 1;
            if (nu < span) {
                for (int id : by_u[nu]) add_band_point(id);
            }
        }
    }

    int end_u = min(span - 1, chosen_u + best_dist);
    int end_v = min(span - 1, chosen_v + best_dist);

    vector<array<int, 3>> inside_pick;
    inside_pick.reserve(K + 10);

    for (auto& seat : all_open) {
        if (seat.u >= chosen_u && seat.u <= end_u && seat.v >= chosen_v && seat.v <= end_v) {
            inside_pick.push_back({seat.aura, seat.r, seat.c});
        }
    }

    nth_element(inside_pick.begin(), inside_pick.begin() + K, inside_pick.end());
    inside_pick.resize(K);
    sort(inside_pick.begin(), inside_pick.end());

    vector<pair<int, int>> answer;
    answer.reserve(K);
    for (auto& item : inside_pick) {
        answer.push_back({item[1], item[2]});
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        vector<string> GRID(M);
        for (int i = 0; i < M; i++) {
            cin >> GRID[i];
        }
        vector<pair<int, int>> result = solve(M, N, K, GRID);
        for (auto& p : result) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}