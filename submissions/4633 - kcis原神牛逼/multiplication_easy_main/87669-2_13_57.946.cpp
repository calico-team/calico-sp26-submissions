#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

using ll = long long;
using ld = long double;

struct Constraint {
    int r, c;
    ll v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, D;
    cin >> N >> M >> D;

    vector<Constraint> cons(M);
    vector<vector<pair<int, int>>> adj(N + 1); // (other, idx)

    for (int i = 0; i < M; ++i) {
        int r, c;
        ll v, w;
        cin >> r >> c >> v >> w;
        cons[i] = { r, c, v, w };
        adj[r].emplace_back(c, i);
        adj[c].emplace_back(r, i);
    }

    vector<ll> a(N + 1, 1);
    vector<bool> discarded(M, false);

    // Helper: compute weighted median for node i using active edges
    auto update_node = [&](int i) {
        vector<pair<ld, ld>> t_w; // (target, weight)
        for (auto [other, idx] : adj[i]) {
            if (discarded[idx]) continue;
            ll v = cons[idx].v;
            ll w = cons[idx].w;
            ll a_other = a[other];
            if (a_other == 0) continue; // safety
            ld t = (ld)v / a_other;
            ld weight = (ld)w * a_other / v;
            t_w.emplace_back(t, weight);
        }
        if (t_w.empty()) return;
        sort(t_w.begin(), t_w.end(),
            [](const pair<ld, ld>& x, const pair<ld, ld>& y) {
                return x.first < y.first;
            });
        ld total_w = 0;
        for (auto& p : t_w) total_w += p.second;
        ld cum = 0;
        ld median_t = t_w[0].first;
        for (auto& p : t_w) {
            cum += p.second;
            if (cum >= total_w * 0.5) {
                median_t = p.first;
                break;
            }
        }
        ll new_a = llround(median_t);
        if (new_a < 1) new_a = 1;
        if (new_a > 1000000000) new_a = 1000000000;
        a[i] = new_a;
        };

    // Phase 1: initial fitting with all edges
    const int PHASE1_ITERS = 20;
    for (int iter = 0; iter < PHASE1_ITERS; ++iter) {
        for (int i = 1; i <= N; ++i) {
            update_node(i);
        }
    }

    // Compute error for each edge (non-discarded)
    vector<pair<ld, int>> errors; // (error, idx)
    errors.reserve(M);
    for (int i = 0; i < M; ++i) {
        if (discarded[i]) continue;
        ll prod = a[cons[i].r] * a[cons[i].c];
        ld err = (ld)cons[i].w * fabsl(prod - cons[i].v) / cons[i].v;
        errors.emplace_back(err, i);
    }

    // Discard up to D worst edges
    int d = min(D, (int)errors.size());
    if (d > 0) {
        nth_element(errors.begin(), errors.begin() + d - 1, errors.end(),
            [](const pair<ld, int>& x, const pair<ld, int>& y) {
                return x.first > y.first; // descending
            });
        for (int k = 0; k < d; ++k) {
            discarded[errors[k].second] = true;
        }
    }

    // Phase 2: refine using remaining edges
    const int PHASE2_ITERS = 10;
    for (int iter = 0; iter < PHASE2_ITERS; ++iter) {
        for (int i = 1; i <= N; ++i) {
            update_node(i);
        }
    }

    // Output a
    for (int i = 1; i <= N; ++i) {
        cout << a[i] << (i == N ? '\n' : ' ');
    }

    // Output discarded indices (1-based)
    vector<int> discarded_idx;
    for (int i = 0; i < M; ++i) {
        if (discarded[i]) discarded_idx.push_back(i + 1);
    }
    cout << discarded_idx.size();
    for (int idx : discarded_idx) cout << ' ' << idx;
    cout << '\n';

    return 0;
}