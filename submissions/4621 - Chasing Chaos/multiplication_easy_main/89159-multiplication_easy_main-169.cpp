#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int R, C, V, W;
};

void solve(int N, int M, int D, const vector<Cell>& cells,
           vector<int>& A, vector<int>& discards) {
    vector<vector<int>> touch_list(N);
    touch_list.assign(N, {});
    vector<int> edge_count(N, 0);
    for (const auto& q : cells) {
        edge_count[q.R - 1]++;
        edge_count[q.C - 1]++;
    }
    for (int i = 0; i < N; i++) touch_list[i].reserve(edge_count[i]);
    for (int i = 0; i < M; i++) {
        touch_list[cells[i].R - 1].push_back(i);
        touch_list[cells[i].C - 1].push_back(i);
    }

    const double top_log = log(1e9);
    vector<double> shade_guess(N, 0.0), fresh_guess(N, 0.0), pull_sum(N), pull_weight(N);

    auto run_passes = [&](const vector<char>& skip_mark, int rounds) {
        for (int step = 0; step < rounds; step++) {
            fill(pull_sum.begin(), pull_sum.end(), 0.0);
            fill(pull_weight.begin(), pull_weight.end(), 0.0);

            for (int idx = 0; idx < M; idx++) {
                if (!skip_mark.empty() && skip_mark[idx]) continue;
                int left_spot = cells[idx].R - 1;
                int right_spot = cells[idx].C - 1;
                double wish = log((double)cells[idx].V);
                double mass = (double)cells[idx].W;

                pull_sum[left_spot] += mass * (wish - shade_guess[right_spot]);
                pull_weight[left_spot] += mass;

                pull_sum[right_spot] += mass * (wish - shade_guess[left_spot]);
                pull_weight[right_spot] += mass;
            }

            for (int i = 0; i < N; i++) {
                if (pull_weight[i] == 0.0) {
                    fresh_guess[i] = 0.0;
                } else {
                    double now_val = pull_sum[i] / pull_weight[i];
                    if (now_val < 0.0) now_val = 0.0;
                    if (now_val > top_log) now_val = top_log;
                    fresh_guess[i] = now_val;
                }
            }

            shade_guess.swap(fresh_guess);
        }
    };

    run_passes({}, 12);

    vector<pair<long double, int>> rough_badness;
    rough_badness.reserve(M);
    for (int idx = 0; idx < M; idx++) {
        int left_spot = cells[idx].R - 1;
        int right_spot = cells[idx].C - 1;
        long double made = expl((long double)shade_guess[left_spot] + (long double)shade_guess[right_spot]);
        long double miss = fabsl(made - (long double)cells[idx].V);
        long double bill = (long double)cells[idx].W * miss / (long double)cells[idx].V;
        rough_badness.push_back({bill, idx});
    }

    vector<char> first_cut(M, 0);
    if (D > 0) {
        int kick = min(D, M);
        nth_element(rough_badness.begin(), rough_badness.begin() + kick, rough_badness.end(),
                    [&](const auto& a, const auto& b) {
                        if (a.first != b.first) return a.first > b.first;
                        return a.second < b.second;
                    });
        for (int i = 0; i < kick; i++) first_cut[rough_badness[i].second] = 1;
    }

    run_passes(first_cut, 10);

    A.assign(N, 1);
    for (int i = 0; i < N; i++) {
        long double made = expl((long double)shade_guess[i]);
        long long round_val = llround(made);
        if (round_val < 1) round_val = 1;
        if (round_val > 1000000000LL) round_val = 1000000000LL;
        A[i] = (int)round_val;
    }

    vector<pair<long double, int>> final_badness;
    final_badness.reserve(M);
    for (int idx = 0; idx < M; idx++) {
        int left_spot = cells[idx].R - 1;
        int right_spot = cells[idx].C - 1;
        long double made = (long double)A[left_spot] * (long double)A[right_spot];
        long double miss = fabsl(made - (long double)cells[idx].V);
        long double bill = (long double)cells[idx].W * miss / (long double)cells[idx].V;
        final_badness.push_back({bill, idx + 1});
    }

    discards.clear();
    if (D > 0) {
        int kick = min(D, M);
        nth_element(final_badness.begin(), final_badness.begin() + kick, final_badness.end(),
                    [&](const auto& a, const auto& b) {
                        if (a.first != b.first) return a.first > b.first;
                        return a.second < b.second;
                    });
        discards.reserve(kick);
        for (int i = 0; i < kick; i++) discards.push_back(final_badness[i].second);
        sort(discards.begin(), discards.end());
    }
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