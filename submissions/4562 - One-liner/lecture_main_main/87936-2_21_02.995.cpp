#include <bits/stdc++.h>
using namespace std;

struct Point { int r, c, u, v; };

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    vector<Point> pts;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (grid[i][j] == '-')
                pts.push_back({i, j, i+j, i-j});

    int n = pts.size();
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b){
        return a.u < b.u;
    });

    // v in [-(M-1), N-1], shift by M-1 to get [0, N+M-2]
    int VOFF = M - 1;
    int VSIZ = N + M - 1;

    // BIT for count of points by v
    vector<int> bit(VSIZ + 2, 0);
    auto bit_upd = [&](int i, int val) {
        for (i++; i < (int)bit.size(); i += i & -i) bit[i] += val;
    };
    auto bit_qry = [&](int i) -> int {
        int s = 0; for (i++; i > 0; i -= i & -i) s += bit[i]; return s;
    };
    auto bit_range = [&](int l, int r) -> int {
        return bit_qry(r) - (l > 0 ? bit_qry(l-1) : 0);
    };
    // Find smallest index with prefix_count >= k
    auto bit_kth = [&](int k) -> int {
        int pos = 0;
        for (int pw = 1 << 21; pw; pw >>= 1)
            if (pos + pw < (int)bit.size() && bit[pos + pw] < k)
                { pos += pw; k -= bit[pos]; }
        return pos; // 0-indexed v-coord (shifted)
    };

    // Check if D is feasible; if so, recover one valid set of K indices
    auto check = [&](int D, vector<int>& out_idx) -> bool {
        fill(bit.begin(), bit.end(), 0);
        int lft = 0;
        bool found = false;
        int found_v1 = -1, found_vK = -1, found_rgt = -1;

        for (int rgt = 0; rgt < n; rgt++) {
            bit_upd(pts[rgt].v + VOFF, 1);

            while (pts[rgt].u - pts[lft].u > D) {
                bit_upd(pts[lft].v + VOFF, -1);
                lft++;
            }

            int total = bit_qry(VSIZ - 1);
            if (total < K) continue;

            int v1 = bit_kth(1);
            int vK = bit_kth(K);

            if (vK - v1 <= D) {
                found = true;
                found_v1 = v1;
                found_vK = vK;
                found_rgt = rgt;
                break; // feasible; we'll recover after
            }
        }

        if (!found) return false;

        // Recover K point indices from the window at found_rgt
        // Rerun to get lft at found_rgt
        fill(bit.begin(), bit.end(), 0);
        int lft2 = 0;
        for (int rgt = 0; rgt <= found_rgt; rgt++) {
            bit_upd(pts[rgt].v + VOFF, 1);
            while (pts[rgt].u - pts[lft2].u > D) {
                bit_upd(pts[lft2].v + VOFF, -1);
                lft2++;
            }
        }

        // Collect points in u-window [lft2, found_rgt] with v in [found_v1, found_vK]
        out_idx.clear();
        for (int i = lft2; i <= found_rgt; i++) {
            int vi = pts[i].v + VOFF;
            if (vi >= found_v1 && vi <= found_vK) {
                out_idx.push_back(i);
                if ((int)out_idx.size() == K) break;
            }
        }

        return true;
    };

    // Binary search on D
    int lo = 0, hi = N + M - 2;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        vector<int> dummy;
        if (check(mid, dummy)) hi = mid;
        else lo = mid + 1;
    }

    vector<int> best_idx;
    check(lo, best_idx);

    for (int idx : best_idx)
        cout << pts[idx].r << " " << pts[idx].c << "\n";
}

void read_your_input() {
    int T; cin >> T;
    while (T--) solve();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_your_input();
    return 0;
}