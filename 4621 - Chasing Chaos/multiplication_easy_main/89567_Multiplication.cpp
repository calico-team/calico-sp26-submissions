#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int R, C, V, W;
};

void solve(int N, int M, int D, const vector<Cell>& cells,
           vector<int>& A, vector<int>& discards) {
    vector<int> touch_size(N, 0);
    for (const auto& e : cells) {
        touch_size[e.R - 1]++;
        touch_size[e.C - 1]++;
    }

    vector<vector<int>> near_edges(N);
    for (int i = 0; i < N; i++) near_edges[i].reserve(touch_size[i]);
    for (int i = 0; i < M; i++) {
        near_edges[cells[i].R - 1].push_back(i);
        near_edges[cells[i].C - 1].push_back(i);
    }

    vector<double> log_pick(N, 0.0), next_pick(N, 0.0), sum_need(N), sum_mass(N);
    const double roof_log = log(1e9);

    auto clamp_log = [&](double x) {
        if (x < 0.0) return 0.0;
        if (x > roof_log) return roof_log;
        return x;
    };

    auto run_sweeps = [&](const vector<char>& banned, int rounds) {
        for (int lap = 0; lap < rounds; lap++) {
            fill(sum_need.begin(), sum_need.end(), 0.0);
            fill(sum_mass.begin(), sum_mass.end(), 0.0);

            for (int i = 0; i < M; i++) {
                if (!banned.empty() && banned[i]) continue;
                int x = cells[i].R - 1;
                int y = cells[i].C - 1;
                double target_log = log((double)cells[i].V);
                double w = (double)cells[i].W;

                sum_need[x] += w * (target_log - log_pick[y]);
                sum_mass[x] += w;
                sum_need[y] += w * (target_log - log_pick[x]);
                sum_mass[y] += w;
            }

            for (int i = 0; i < N; i++) {
                if (sum_mass[i] == 0.0) next_pick[i] = log_pick[i];
                else next_pick[i] = clamp_log(sum_need[i] / sum_mass[i]);
            }
            log_pick.swap(next_pick);
        }
    };

    run_sweeps({}, 10);

    vector<long double> rough_bill(M);
    for (int i = 0; i < M; i++) {
        int x = cells[i].R - 1;
        int y = cells[i].C - 1;
        long double made = expl((long double)log_pick[x] + (long double)log_pick[y]);
        long double loss = fabsl(made - (long double)cells[i].V);
        rough_bill[i] = (long double)cells[i].W * loss / (long double)cells[i].V;
    }

    vector<int> heavy_order(M);
    iota(heavy_order.begin(), heavy_order.end(), 0);
    sort(heavy_order.begin(), heavy_order.end(), [&](int a, int b) {
        if (rough_bill[a] != rough_bill[b]) return rough_bill[a] > rough_bill[b];
        return a < b;
    });

    vector<char> skip_mark(M, 0);
    int early_drop = min(D, max(0, min(M, D)));
    for (int i = 0; i < early_drop; i++) skip_mark[heavy_order[i]] = 1;

    run_sweeps(skip_mark, 12);

    vector<long double> vote_sum(N, 0.0), vote_mass(N, 0.0);
    for (int i = 0; i < M; i++) {
        if (skip_mark[i]) continue;
        int x = cells[i].R - 1;
        int y = cells[i].C - 1;
        long double share = sqrt((long double)cells[i].V);
        long double z = log((double)share);
        long double w = (long double)cells[i].W;

        vote_sum[x] += w * z;
        vote_mass[x] += w;
        vote_sum[y] += w * z;
        vote_mass[y] += w;
    }

    for (int i = 0; i < N; i++) {
        if (vote_mass[i] > 0) {
            long double merged = (long double)log_pick[i] * 0.65L + (vote_sum[i] / vote_mass[i]) * 0.35L;
            log_pick[i] = clamp_log((double)merged);
        }
    }

    A.assign(N, 1);
    for (int i = 0; i < N; i++) {
        long double made = expl((long double)log_pick[i]);
        long long put = llround(made);
        if (put < 1) put = 1;
        if (put > 1000000000LL) put = 1000000000LL;
        A[i] = (int)put;
    }

    vector<int> active_nodes;
    active_nodes.reserve(N);
    for (int i = 0; i < N; i++) {
        if (!near_edges[i].empty()) active_nodes.push_back(i);
    }

    auto total_cost = [&](const vector<int>& now_a, vector<long double>* each_line) {
        long double total = 0;
        if (each_line) each_line->assign(M, 0);
        for (int i = 0; i < M; i++) {
            long double made = (long double)now_a[cells[i].R - 1] * (long double)now_a[cells[i].C - 1];
            long double loss = fabsl(made - (long double)cells[i].V);
            long double bill = (long double)cells[i].W * loss / (long double)cells[i].V;
            total += bill;
            if (each_line) (*each_line)[i] = bill;
        }
        return total;
    };

    vector<long double> one_line;
    total_cost(A, &one_line);

    for (int pass = 0; pass < 2; pass++) {
        for (int who : active_nodes) {
            long double score_log = 0.0L, weight_log = 0.0L;
            for (int id : near_edges[who]) {
                if (skip_mark[id]) continue;
                int other = cells[id].R - 1;
                if (other == who) other = cells[id].C - 1;
                long double other_val = (long double)A[other];
                if (other_val <= 0) continue;
                long double wish = (long double)cells[id].V / other_val;
                if (wish < 1.0L) wish = 1.0L;
                if (wish > 1000000000.0L) wish = 1000000000.0L;
                long double w = (long double)cells[id].W;
                score_log += w * log((double)wish);
                weight_log += w;
            }
            if (weight_log == 0.0L) continue;

            long long center = llround(expl(score_log / weight_log));
            if (center < 1) center = 1;
            if (center > 1000000000LL) center = 1000000000LL;

            vector<long long> tries;
            tries.push_back(center);
            if (center > 1) tries.push_back(center - 1);
            if (center < 1000000000LL) tries.push_back(center + 1);

            long long half_low = max(1LL, center / 2);
            long long half_high = min(1000000000LL, center * 2);
            tries.push_back(half_low);
            tries.push_back(half_high);

            sort(tries.begin(), tries.end());
            tries.erase(unique(tries.begin(), tries.end()), tries.end());

            long double best_here = 0.0L;
            for (int id : near_edges[who]) {
                int a = cells[id].R - 1;
                int b = cells[id].C - 1;
                long double made = (long double)A[a] * (long double)A[b];
                long double loss = fabsl(made - (long double)cells[id].V);
                best_here += (long double)cells[id].W * loss / (long double)cells[id].V;
            }

            int old_val = A[who];
            int best_val = old_val;

            for (long long cand : tries) {
                A[who] = (int)cand;
                long double now_here = 0.0L;
                for (int id : near_edges[who]) {
                    int a = cells[id].R - 1;
                    int b = cells[id].C - 1;
                    long double made = (long double)A[a] * (long double)A[b];
                    long double loss = fabsl(made - (long double)cells[id].V);
                    now_here += (long double)cells[id].W * loss / (long double)cells[id].V;
                }
                if (now_here < best_here) {
                    best_here = now_here;
                    best_val = (int)cand;
                }
            }
            A[who] = best_val;
        }
    }

    vector<long double> final_bill;
    total_cost(A, &final_bill);

    vector<int> take_order(M);
    iota(take_order.begin(), take_order.end(), 0);
    sort(take_order.begin(), take_order.end(), [&](int a, int b) {
        if (final_bill[a] != final_bill[b]) return final_bill[a] > final_bill[b];
        return a < b;
    });

    discards.clear();
    int final_drop = min(D, M);
    discards.reserve(final_drop);
    for (int i = 0; i < final_drop; i++) discards.push_back(take_order[i] + 1);
    sort(discards.begin(), discards.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, D;
    cin >> N >> M >> D;
    vector<Cell> cells(M);
    for (int i = 0; i < M; i++) {
        cin >> cells[i].R >> cells[i].C >> cells[i].V >> cells[i].W;
    }

    vector<int> A, discards;
    solve(N, M, D, cells, A, discards);

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
    cout << discards.size();
    for (int idx : discards) cout << ' ' << idx;
    cout << '\n';
    return 0;
}