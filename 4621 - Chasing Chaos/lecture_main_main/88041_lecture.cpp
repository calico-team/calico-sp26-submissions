#include <bits/stdc++.h>
using namespace std;

struct SpotPick {
    int row_id;
    int col_id;
    int rise_key;
    int fall_key;
};

static int rect_sum(const vector<vector<int>>& glow_prefix, int r1, int c1, int r2, int c2) {
    if (r1 > r2 || c1 > c2) return 0;
    return glow_prefix[r2 + 1][c2 + 1] - glow_prefix[r1][c2 + 1] - glow_prefix[r2 + 1][c1] + glow_prefix[r1][c1];
}

vector<pair<int, int>> solve(int M, int N, int K, vector<string>& GRID) {
    vector<SpotPick> open_spots;
    int tilt_shift = N - 1;
    int band_size = M + N - 1;

    for (int rr = 0; rr < M; rr++) {
        for (int cc = 0; cc < N; cc++) {
            if (GRID[rr][cc] == '-') {
                int up_diag = rr + cc;
                int down_diag = rr - cc + tilt_shift;
                open_spots.push_back({rr, cc, up_diag, down_diag});
            }
        }
    }

    vector<vector<int>> seat_marks(band_size, vector<int>(band_size, 0));
    for (auto& node : open_spots) {
        seat_marks[node.rise_key][node.fall_key]++;
    }

    vector<vector<int>> glow_prefix(band_size + 1, vector<int>(band_size + 1, 0));
    for (int a = 0; a < band_size; a++) {
        for (int b = 0; b < band_size; b++) {
            glow_prefix[a + 1][b + 1] = glow_prefix[a][b + 1] + glow_prefix[a + 1][b] - glow_prefix[a][b] + seat_marks[a][b];
        }
    }

    auto can_fit_group = [&](int max_gap) {
        for (int top_u = 0; top_u < band_size; top_u++) {
            int bot_u = min(band_size - 1, top_u + max_gap);
            for (int top_v = 0; top_v < band_size; top_v++) {
                int bot_v = min(band_size - 1, top_v + max_gap);
                if (rect_sum(glow_prefix, top_u, top_v, bot_u, bot_v) >= K) return true;
            }
        }
        return false;
    };

    int low_gap = 0;
    int high_gap = M + N;
    while (low_gap < high_gap) {
        int mid_gap = (low_gap + high_gap) / 2;
        if (can_fit_group(mid_gap)) high_gap = mid_gap;
        else low_gap = mid_gap + 1;
    }

    int best_gap = low_gap;
    int keep_u1 = 0, keep_u2 = 0, keep_v1 = 0, keep_v2 = 0;

    for (int top_u = 0; top_u < band_size; top_u++) {
        int bot_u = min(band_size - 1, top_u + best_gap);
        bool done_here = false;
        for (int top_v = 0; top_v < band_size; top_v++) {
            int bot_v = min(band_size - 1, top_v + best_gap);
            if (rect_sum(glow_prefix, top_u, top_v, bot_u, bot_v) >= K) {
                keep_u1 = top_u;
                keep_u2 = bot_u;
                keep_v1 = top_v;
                keep_v2 = bot_v;
                done_here = true;
                break;
            }
        }
        if (done_here) break;
    }

    vector<pair<int, int>> answer_set;
    for (auto& node : open_spots) {
        if (node.rise_key >= keep_u1 && node.rise_key <= keep_u2 &&
            node.fall_key >= keep_v1 && node.fall_key <= keep_v2) {
            answer_set.push_back({node.row_id, node.col_id});
            if ((int)answer_set.size() == K) break;
        }
    }

    return answer_set;
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