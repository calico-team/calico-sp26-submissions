#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long double val, w;
    long double logv;
};

struct TestCase {
    int N = 0, M = 0, D = 0;
    vector<Edge> edges;
};

bool read_your_input(istream& in, TestCase& tc);

static long double clamp_ld(long double x, long double lo, long double hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

static vector<long double> solve_log_system(
    int N,
    const vector<Edge>& edges,
    const vector<char>& active,
    int iters
) {
    vector<vector<pair<int, long double>>> g(N);
    vector<long double> diag(N, 0.0L), rhs(N, 0.0L);
    for (int i = 0; i < (int)edges.size(); i++) {
        if (!active[i]) continue;
        const auto& e = edges[i];
        g[e.u].push_back({e.v, e.w});
        g[e.v].push_back({e.u, e.w});
        diag[e.u] += e.w;
        diag[e.v] += e.w;
        rhs[e.u] += e.w * e.logv;
        rhs[e.v] += e.w * e.logv;
    }

    vector<long double> y(N, 0.0L), ny(N, 0.0L);
    for (int it = 0; it < iters; it++) {
        for (int i = 0; i < N; i++) {
            if (diag[i] == 0.0L) {
                ny[i] = y[i];
                continue;
            }
            long double s = 0.0L;
            for (auto [to, ww] : g[i]) s += ww * y[to];
            ny[i] = (rhs[i] - s) / diag[i];
        }
        y.swap(ny);
    }
    return y;
}

static long double compute_penalty_with_discard(
    const vector<long long>& a,
    const vector<Edge>& edges,
    int D
) {
    vector<long double> errs;
    errs.reserve(edges.size());
    long double sum = 0.0L;
    for (const auto& e : edges) {
        long double p = (long double)a[e.u] * (long double)a[e.v];
        long double err = e.w * fabsl(p - e.val) / e.val;
        errs.push_back(err);
        sum += err;
    }
    if (D <= 0 || errs.empty()) return sum;
    D = min(D, (int)errs.size());
    nth_element(errs.begin(), errs.end() - D, errs.end());
    long double removed = 0.0L;
    for (int i = (int)errs.size() - D; i < (int)errs.size(); i++) removed += errs[i];
    return sum - removed;
}

static vector<char> choose_active_trim(
    const vector<long double>& y,
    const vector<Edge>& edges,
    int D
) {
    int M = (int)edges.size();
    vector<pair<long double, int>> score;
    score.reserve(M);
    for (int i = 0; i < M; i++) {
        const auto& e = edges[i];
        long double pred = expl(y[e.u] + y[e.v]);
        long double err = e.w * fabsl(pred - e.val) / e.val;
        score.push_back({err, i});
    }
    sort(score.begin(), score.end(), [](const auto& A, const auto& B) {
        return A.first > B.first;
    });
    vector<char> active(M, 1);
    for (int i = 0; i < min(D, M); i++) active[score[i].second] = 0;
    return active;
}

static long double weighted_median_scale(const vector<long double>& y, const vector<Edge>& edges) {
    vector<pair<long double, long double>> pts;
    pts.reserve(edges.size());
    for (const auto& e : edges) {
        long double p = expl(y[e.u] + y[e.v]);
        if (p <= 0.0L) continue;
        long double t = e.val / p;
        long double ww = e.w * p / e.val;
        if (t > 0.0L && ww > 0.0L) pts.push_back({t, ww});
    }
    if (pts.empty()) return 1.0L;
    sort(pts.begin(), pts.end(), [](const auto& A, const auto& B) { return A.first < B.first; });
    long double tw = 0.0L;
    for (auto& p : pts) tw += p.second;
    long double cur = 0.0L;
    for (auto& p : pts) {
        cur += p.second;
        if (cur * 2.0L >= tw) return p.first;
    }
    return pts.back().first;
}

static vector<long long> make_integer_solution(
    const vector<long double>& y,
    long double add_shift
) {
    const long double LIM_LOG = logl(1000000000.0L);
    vector<long long> a(y.size(), 1);
    for (int i = 0; i < (int)y.size(); i++) {
        long double z = clamp_ld(y[i] + add_shift, 0.0L, LIM_LOG);
        long double v = expl(z);
        long long x = llround(v);
        if (x < 1) x = 1;
        if (x > 1000000000LL) x = 1000000000LL;
        a[i] = x;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        TestCase tc;
        if (!read_your_input(cin, tc)) return 0;

        vector<char> active(tc.edges.size(), 1);
        vector<long double> y = solve_log_system(tc.N, tc.edges, active, 35);

        for (int rep = 0; rep < 3; rep++) {
            active = choose_active_trim(y, tc.edges, tc.D);
            y = solve_log_system(tc.N, tc.edges, active, 35);
        }

        long double k = weighted_median_scale(y, tc.edges);
        if (!(k > 0.0L) || !isfinite((double)k)) k = 1.0L;
        long double base_shift = 0.5L * logl(k);

        vector<long double> deltas = {-0.8L, -0.4L, -0.2L, 0.0L, 0.2L, 0.4L, 0.8L};
        vector<long long> better_than_me;
        long double best_pen = numeric_limits<long double>::infinity();

        for (long double d : deltas) {
            auto cand = make_integer_solution(y, base_shift + d);
            long double pen = compute_penalty_with_discard(cand, tc.edges, tc.D);
            if (pen < best_pen) {
                best_pen = pen;
                better_than_me = std::move(cand);
            }
        }

        if (better_than_me.empty()) better_than_me = make_integer_solution(y, base_shift);
        for (int i = 0; i < tc.N; i++) {
            if (i) cout << ' ';
            cout << better_than_me[i];
        }
        cout << '\n';
    }
    return 0;
}

bool read_your_input(istream& in, TestCase& tc) {
    if (!(in >> tc.N >> tc.M >> tc.D)) return false;
    vector<long long> raw(4LL * tc.M);
    for (long long i = 0; i < 4LL * tc.M; i++) {
        if (!(in >> raw[i])) return false;
    }

    auto parse_interleaved = [&](vector<Edge>& out) {
        out.clear();
        out.reserve(tc.M);
        int ok = 0;
        for (int i = 0; i < tc.M; i++) {
            long long R = raw[4LL * i + 0];
            long long C = raw[4LL * i + 1];
            long long V = raw[4LL * i + 2];
            long long W = raw[4LL * i + 3];
            if (1 <= R && R <= tc.N && 1 <= C && C <= tc.N && R != C && V > 0 && W > 0) ok++;
            if (V <= 0 || W <= 0) continue;
            Edge e;
            e.u = (int)max(1LL, min((long long)tc.N, R)) - 1;
            e.v = (int)max(1LL, min((long long)tc.N, C)) - 1;
            if (e.u == e.v) e.v = (e.v + 1) % tc.N;
            e.val = (long double)V;
            e.w = (long double)W;
            e.logv = logl(e.val);
            out.push_back(e);
        }
        return ok;
    };

    auto parse_blocked = [&](vector<Edge>& out) {
        out.clear();
        out.reserve(tc.M);
        int ok = 0;
        for (int i = 0; i < tc.M; i++) {
            long long R = raw[i];
            long long C = raw[tc.M + i];
            long long V = raw[2LL * tc.M + i];
            long long W = raw[3LL * tc.M + i];
            if (1 <= R && R <= tc.N && 1 <= C && C <= tc.N && R != C && V > 0 && W > 0) ok++;
            if (V <= 0 || W <= 0) continue;
            Edge e;
            e.u = (int)max(1LL, min((long long)tc.N, R)) - 1;
            e.v = (int)max(1LL, min((long long)tc.N, C)) - 1;
            if (e.u == e.v) e.v = (e.v + 1) % tc.N;
            e.val = (long double)V;
            e.w = (long double)W;
            e.logv = logl(e.val);
            out.push_back(e);
        }
        return ok;
    };

    vector<Edge> a, b;
    int oka = parse_interleaved(a);
    int okb = parse_blocked(b);
    tc.edges = (okb > oka ? b : a);
    if (tc.edges.empty()) {
        tc.edges.reserve(tc.M);
        for (int i = 0; i < tc.M; i++) {
            Edge e;
            e.u = i % tc.N;
            e.v = (i + 1) % tc.N;
            e.val = 1.0L;
            e.w = 1.0L;
            e.logv = 0.0L;
            tc.edges.push_back(e);
        }
    }
    return true;
}
