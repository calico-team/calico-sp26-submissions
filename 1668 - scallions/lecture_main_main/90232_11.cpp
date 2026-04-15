#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

static const ll LIM = (ll)4e18; // practical cap for output values

struct Edge {
    int u, v;
    ll V, W;
    int id; // 1-based original index
};

struct Solver {
    int N, M, D;
    vector<Edge> edges;
    vector<vector<int>> adj;

    // ---------- utility ----------
    static ll clamp_ll(long double x) {
        if (x < 1.0L) return 1;
        if (x > (long double)LIM) return LIM;
        ll y = ll(llround(x));
        if (y < 1) y = 1;
        if (y > LIM) y = LIM;
        return y;
    }

    ld edge_cost_with_values(const Edge& e, ll au, ll av) const {
        ld prod = (ld)au * (ld)av;
        return (ld)e.W * fabsl(prod - (ld)e.V) / (ld)e.V;
    }

    ld total_score(const vector<ll>& a, const vector<char>& discard) const {
        ld res = 0;
        for (int i = 0; i < M; ++i) {
            if (discard[i]) continue;
            const auto& e = edges[i];
            res += edge_cost_with_values(e, a[e.u], a[e.v]);
        }
        return res;
    }

    vector<ld> all_contribs(const vector<ll>& a) const {
        vector<ld> c(M);
        for (int i = 0; i < M; ++i) {
            const auto& e = edges[i];
            c[i] = edge_cost_with_values(e, a[e.u], a[e.v]);
        }
        return c;
    }

    vector<char> choose_discards(const vector<ll>& a) const {
        vector<char> discard(M, 0);
        if (D <= 0) return discard;

        vector<pair<ld,int>> ord;
        ord.reserve(M);
        for (int i = 0; i < M; ++i) {
            const auto& e = edges[i];
            ld c = edge_cost_with_values(e, a[e.u], a[e.v]);
            ord.push_back({c, i});
        }

        int d = min(D, M);
        if (d == M) {
            for (int i = 0; i < M; ++i) discard[i] = 1;
            return discard;
        }

        nth_element(ord.begin(), ord.begin() + d, ord.end(),
                    [](const auto& A, const auto& B) {
                        return A.first > B.first;
                    });

        for (int i = 0; i < d; ++i) {
            discard[ord[i].second] = 1;
        }
        return discard;
    }

    // Exact 1D objective for one node, with all others fixed:
    // sum alpha_j * |x - beta_j|
    // where alpha_j = W * a_neighbor / V, beta_j = V / a_neighbor
    ll best_value_for_node(int x, const vector<ll>& a, const vector<char>& discard) const {
        vector<pair<ld, ld>> terms; // (beta, alpha)
        terms.reserve(adj[x].size());

        for (int ei : adj[x]) {
            if (discard[ei]) continue;
            const Edge& e = edges[ei];
            int y = (e.u == x ? e.v : e.u);
            ll ay = a[y];
            if (ay <= 0) continue;

            ld beta = (ld)e.V / (ld)ay;
            ld alpha = (ld)e.W * (ld)ay / (ld)e.V;
            terms.push_back({beta, alpha});
        }

        if (terms.empty()) return a[x];

        sort(terms.begin(), terms.end(),
             [](const auto& A, const auto& B) {
                 return A.first < B.first;
             });

        ld total_w = 0;
        for (auto &p : terms) total_w += p.second;

        ld pref = 0;
        ld med = terms.back().first;
        for (auto &p : terms) {
            pref += p.second;
            if (pref * 2 >= total_w) {
                med = p.first;
                break;
            }
        }

        // Because x must be integer, test a small neighborhood around the weighted median.
        vector<ll> cand;
        cand.push_back(a[x]);
        ll f = (ll)floor(med);
        ll c = (ll)ceil(med);
        for (ll t = f - 2; t <= c + 2; ++t) {
            if (t >= 1) cand.push_back(t);
        }
        cand.push_back(1);
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());

        auto local_cost = [&](ll val) -> ld {
            ld s = 0;
            for (int ei : adj[x]) {
                if (discard[ei]) continue;
                const Edge& e = edges[ei];
                int y = (e.u == x ? e.v : e.u);
                s += edge_cost_with_values(e, val, a[y]);
            }
            return s;
        };

        ll best = a[x];
        ld bestc = local_cost(best);
        for (ll v : cand) {
            if (v < 1) continue;
            ld cur = local_cost(v);
            if (cur < bestc) {
                bestc = cur;
                best = v;
            }
        }
        return best;
    }

    vector<ll> initial_all_ones() const {
        return vector<ll>(N, 1);
    }

    vector<ll> initial_sqrt_medianV() const {
        vector<ll> a(N, 1);
        for (int i = 0; i < N; ++i) {
            vector<pair<ll,ll>> vals; // (V, W)
            vals.reserve(adj[i].size());
            for (int ei : adj[i]) {
                const Edge& e = edges[ei];
                vals.push_back({e.V, e.W});
            }
            if (vals.empty()) {
                a[i] = 1;
                continue;
            }
            sort(vals.begin(), vals.end());
            long long total = 0;
            for (auto &p : vals) total += p.second;
            long long pref = 0;
            ll medV = vals.back().first;
            for (auto &p : vals) {
                pref += p.second;
                if (pref * 2 >= total) {
                    medV = p.first;
                    break;
                }
            }
            a[i] = max<ll>(1, (ll)floor(sqrt((long double)medV)));
        }
        return a;
    }

    vector<ll> run_from_initial(vector<ll> a, mt19937_64& rng) const {
        // Warm-up without discards
        {
            vector<char> no_discard(M, 0);
            vector<int> order(N);
            iota(order.begin(), order.end(), 0);
            for (int pass = 0; pass < 3; ++pass) {
                shuffle(order.begin(), order.end(), rng);
                for (int x : order) {
                    a[x] = best_value_for_node(x, a, no_discard);
                }
            }
        }

        vector<char> discard(M, 0);
        vector<int> order(N);
        iota(order.begin(), order.end(), 0);

        for (int outer = 0; outer < 12; ++outer) {
            discard = choose_discards(a);

            for (int pass = 0; pass < 2; ++pass) {
                shuffle(order.begin(), order.end(), rng);
                bool changed = false;
                for (int x : order) {
                    ll oldv = a[x];
                    ll newv = best_value_for_node(x, a, discard);
                    if (newv != oldv) {
                        a[x] = newv;
                        changed = true;
                    }
                }
                if (!changed) break;
            }
        }

        return a;
    }

    pair<vector<ll>, vector<int>> solve() const {
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

        vector<vector<ll>> starts;
        starts.push_back(initial_all_ones());
        starts.push_back(initial_sqrt_medianV());

        // One more perturbed start
        {
            vector<ll> b = initial_sqrt_medianV();
            for (int i = 0; i < N; ++i) {
                int t = (int)(rng() % 3);
                if (t == 1 && b[i] < LIM) b[i]++;
                if (t == 2 && b[i] > 1) b[i]--;
                if (b[i] < 1) b[i] = 1;
            }
            starts.push_back(b);
        }

        ld bestScore = numeric_limits<ld>::infinity();
        vector<ll> bestA;
        vector<int> bestDiscardList;

        for (auto start : starts) {
            vector<ll> a = run_from_initial(start, rng);
            vector<char> discard = choose_discards(a);
            ld sc = total_score(a, discard);

            if (sc < bestScore) {
                bestScore = sc;
                bestA = a;
                bestDiscardList.clear();
                for (int i = 0; i < M; ++i) {
                    if (discard[i]) bestDiscardList.push_back(edges[i].id);
                }
                sort(bestDiscardList.begin(), bestDiscardList.end());
            }
        }

        return {bestA, bestDiscardList};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver solver;
    cin >> solver.N >> solver.M >> solver.D;
    solver.edges.resize(solver.M);
    solver.adj.assign(solver.N, {});

    for (int i = 0; i < solver.M; ++i) {
        int R, C;
        ll V, W;
        cin >> R >> C >> V >> W;
        --R; --C;
        solver.edges[i] = {R, C, V, W, i + 1};
        solver.adj[R].push_back(i);
        solver.adj[C].push_back(i);
    }

    auto ans = solver.solve();
    const vector<ll>& a = ans.first;
    const vector<int>& disc = ans.second;

    for (int i = 0; i < solver.N; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';

    cout << disc.size();
    for (int id : disc) cout << ' ' << id;
    cout << '\n';

    return 0;
}