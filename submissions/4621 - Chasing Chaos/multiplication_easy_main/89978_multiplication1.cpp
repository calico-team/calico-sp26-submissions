#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int R, C, V, W;
};

static long double bound_value(long double x, long double lo, long double hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

void solve(int N, int M, int D, const vector<Cell>& cells,
           vector<int>& A, vector<int>& discards) {
    vector<int> degree_hint(N, 0);
    for (const auto& it : cells) {
        degree_hint[it.R - 1]++;
        degree_hint[it.C - 1]++;
    }

    vector<vector<int>> around(N);
    for (int i = 0; i < N; i++) around[i].reserve(degree_hint[i]);
    for (int i = 0; i < M; i++) {
        around[cells[i].R - 1].push_back(i);
        around[cells[i].C - 1].push_back(i);
    }

    const long double low_log = 0.0L;
    const long double high_log = logl(1000000000.0L);

    vector<long double> shade(N, 0.0L), fresh(N, 0.0L), want_sum(N), mass_sum(N);
    vector<char> drop_mark(M, 0);

    auto relax_logs = [&](int rounds) {
        for (int step = 0; step < rounds; step++) {
            fill(want_sum.begin(), want_sum.end(), 0.0L);
            fill(mass_sum.begin(), mass_sum.end(), 0.0L);

            for (int i = 0; i < M; i++) {
                if (drop_mark[i]) continue;
                int x = cells[i].R - 1;
                int y = cells[i].C - 1;
                long double target = logl((long double)cells[i].V);
                long double w = (long double)cells[i].W;

                want_sum[x] += w * (target - shade[y]);
                mass_sum[x] += w;
                want_sum[y] += w * (target - shade[x]);
                mass_sum[y] += w;
            }

            for (int i = 0; i < N; i++) {
                if (mass_sum[i] == 0.0L) fresh[i] = shade[i];
                else fresh[i] = bound_value(want_sum[i] / mass_sum[i], low_log, high_log);
            }
            shade.swap(fresh);
        }
    };

    relax_logs(8);

    vector<pair<long double, int>> first_bad;
    first_bad.reserve(M);
    for (int i = 0; i < M; i++) {
        int x = cells[i].R - 1;
        int y = cells[i].C - 1;
        long double made = expl(shade[x] + shade[y]);
        long double miss = fabsl(made - (long double)cells[i].V);
        long double score = (long double)cells[i].W * miss / (long double)cells[i].V;
        first_bad.push_back({score, i});
    }

    if (D > 0) {
        int cut = min(D, M);
        nth_element(first_bad.begin(), first_bad.begin() + cut, first_bad.end(),
                    [&](const auto& a, const auto& b) {
                        if (a.first != b.first) return a.first > b.first;
                        return a.second < b.second;
                    });
        for (int i = 0; i < cut; i++) drop_mark[first_bad[i].second] = 1;
    }

    relax_logs(8);

    A.assign(N, 1);
    for (int i = 0; i < N; i++) {
        long long v = llround(expl(shade[i]));
        if (v < 1) v = 1;
        if (v > 1000000000LL) v = 1000000000LL;
        A[i] = (int)v;
    }

    vector<int> active_nodes;
    active_nodes.reserve(N);
    for (int i = 0; i < N; i++) {
        if (!around[i].empty()) active_nodes.push_back(i);
    }

    auto node_cost = [&](int who) {
        long double res = 0.0L;
        for (int id : around[who]) {
            int x = cells[id].R - 1;
            int y = cells[id].C - 1;
            long double made = (long double)A[x] * (long double)A[y];
            long double miss = fabsl(made - (long double)cells[id].V);
            res += (long double)cells[id].W * miss / (long double)cells[id].V;
        }
        return res;
    };

    for (int pass = 0; pass < 2; pass++) {
        for (int who : active_nodes) {
            long double blend_sum = 0.0L;
            long double blend_mass = 0.0L;

            for (int id : around[who]) {
                if (drop_mark[id]) continue;
                int x = cells[id].R - 1;
                int y = cells[id].C - 1;
                int other = (x == who ? y : x);
                long double wish = (long double)cells[id].V / (long double)A[other];
                wish = bound_value(wish, 1.0L, 1000000000.0L);
                long double w = (long double)cells[id].W;
                blend_sum += w * logl(wish);
                blend_mass += w;
            }

            if (blend_mass == 0.0L) continue;

            long long mid = llround(expl(blend_sum / blend_mass));
            if (mid < 1) mid = 1;
            if (mid > 1000000000LL) mid = 1000000000LL;

            vector<long long> tries;
            tries.push_back(mid);
            if (mid > 1) tries.push_back(mid - 1);
            if (mid < 1000000000LL) tries.push_back(mid + 1);
            tries.push_back(max(1LL, mid / 2));
            tries.push_back(min(1000000000LL, mid * 2));
            tries.push_back(A[who]);

            sort(tries.begin(), tries.end());
            tries.erase(unique(tries.begin(), tries.end()), tries.end());

            int old_value = A[who];
            int keep_value = old_value;
            long double keep_cost = node_cost(who);

            for (long long cand : tries) {
                A[who] = (int)cand;
                long double here = node_cost(who);
                if (here < keep_cost) {
                    keep_cost = here;
                    keep_value = (int)cand;
                }
            }

            A[who] = keep_value;
        }
    }

    vector<pair<long double, int>> final_bad;
    final_bad.reserve(M);
    for (int i = 0; i < M; i++) {
        int x = cells[i].R - 1;
        int y = cells[i].C - 1;
        long double made = (long double)A[x] * (long double)A[y];
        long double miss = fabsl(made - (long double)cells[i].V);
        long double score = (long double)cells[i].W * miss / (long double)cells[i].V;
        final_bad.push_back({score, i + 1});
    }

    discards.clear();
    if (D > 0) {
        int cut = min(D, M);
        nth_element(final_bad.begin(), final_bad.begin() + cut, final_bad.end(),
                    [&](const auto& a, const auto& b) {
                        if (a.first != b.first) return a.first > b.first;
                        return a.second < b.second;
                    });
        discards.reserve(cut);
        for (int i = 0; i < cut; i++) discards.push_back(final_bad[i].second);
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