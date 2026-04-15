#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, v, w;
};

struct Item {
    double cur, t, wt;
};

struct Answer {
    double val;
    vector<int> a;
    vector<int> del;
};

int n, m, d;
vector<Edge> es;
vector<double> lg;
vector<vector<int>> g;

inline int clip_ll(long long x) {
    if (x < 1) return 1;
    if (x > 1000000000LL) return 1000000000;
    return (int)x;
}

inline int to_int(double x) {
    if (x < 1.0) return 1;
    if (x > 1e9) return 1000000000;
    return clip_ll((long long)llround(x));
}

inline int get_med(vector<pair<double, double>> &q) {
    sort(q.begin(), q.end(), [](const auto &x, const auto &y) {
        return x.first < y.first;
    });
    double s = 0;
    for (auto &x : q) s += x.second;
    double t = 0;
    for (auto &x : q) {
        t += x.second;
        if (t * 2.0 >= s) return to_int(x.first);
    }
    return to_int(q.back().first);
}

Answer calc_ans(const vector<int> &a) {
    Answer res;
    res.a = a;
    if (d >= m) {
        res.val = 0;
        res.del.resize(m);
        iota(res.del.begin(), res.del.end(), 1);
        return res;
    }

    double sum = 0;
    vector<pair<double, int>> q;
    q.reserve(m);
    for (int i = 0; i < m; i++) {
        const auto &e = es[i];
        double p = (double)a[e.a] * (double)a[e.b];
        double er = (double)e.w * fabs(p - (double)e.v) / (double)e.v;
        sum += er;
        q.push_back({er, i + 1});
    }

    if (d == 0) {
        res.val = sum;
        return res;
    }

    nth_element(q.begin(), q.begin() + d, q.end(), [](const auto &x, const auto &y) {
        return x.first > y.first;
    });

    double cut = 0;
    res.del.reserve(d);
    for (int i = 0; i < d; i++) {
        if (q[i].first > 0) {
            cut += q[i].first;
            res.del.push_back(q[i].second);
        }
    }
    res.val = sum - cut;
    return res;
}

vector<int> init_log() {
    vector<int> a(n, 1);
    vector<double> x(n, 0);
    vector<double> q;
    for (int i = 0; i < n; i++) {
        q.clear();
        q.reserve(g[i].size());
        for (int id : g[i]) q.push_back(lg[id] * 0.5);
        if (!q.empty()) {
            sort(q.begin(), q.end());
            x[i] = q[q.size() >> 1];
        }
    }

    for (int it = 0; it < 4; it++) {
        for (int i = 0; i < n; i++) {
            if (g[i].empty()) continue;
            double s = 0, sw = 0;
            for (int id : g[i]) {
                const auto &e = es[id];
                int j = e.a ^ e.b ^ i;
                s += (double)e.w * (lg[id] - x[j]);
                sw += (double)e.w;
            }
            if (sw > 0) x[i] = s / sw;
        }
    }

    for (int i = 0; i < n; i++) a[i] = to_int(exp(x[i]));
    return a;
}

vector<int> init_sqrt_med() {
    vector<int> a(n, 1);
    vector<pair<double, double>> q;
    for (int i = 0; i < n; i++) {
        q.clear();
        q.reserve(g[i].size());
        for (int id : g[i]) {
            const auto &e = es[id];
            q.push_back({sqrt((double)e.v), (double)e.w});
        }
        if (!q.empty()) a[i] = get_med(q);
    }
    return a;
}

Answer solve_trim_log() {
    vector<int> a = init_log();
    double frac = m ? (double)d / (double)m * 0.8 : 0.0;
    vector<Item> q;

    for (int it = 0; it < 3; it++) {
        for (int i = 0; i < n; i++) {
            int sz = (int)g[i].size();
            if (!sz) continue;
            int k = (int)(sz * frac);
            if (k >= sz) k = sz - 1;

            q.clear();
            q.reserve(sz);
            double ai = (double)a[i];
            for (int id : g[i]) {
                const auto &e = es[id];
                int j = e.a ^ e.b ^ i;
                double aj = (double)a[j];
                double t = (double)e.v / aj;
                double wt = (double)e.w * aj / (double)e.v;
                double cur = (double)e.w * fabs(ai * aj - (double)e.v) / (double)e.v;
                q.push_back({cur, t, wt});
            }

            if (k > 0) {
                sort(q.begin(), q.end(), [](const Item &x, const Item &y) {
                    return x.cur > y.cur;
                });
                sort(q.begin() + k, q.end(), [](const Item &x, const Item &y) {
                    return x.t < y.t;
                });
                double sw = 0;
                for (int j = k; j < sz; j++) sw += q[j].wt;
                double s = 0;
                double r = q[sz - 1].t;
                for (int j = k; j < sz; j++) {
                    s += q[j].wt;
                    if (s * 2.0 >= sw) {
                        r = q[j].t;
                        break;
                    }
                }
                a[i] = to_int(r);
            } else {
                sort(q.begin(), q.end(), [](const Item &x, const Item &y) {
                    return x.t < y.t;
                });
                double sw = 0;
                for (auto &x : q) sw += x.wt;
                double s = 0;
                double r = q.back().t;
                for (auto &x : q) {
                    s += x.wt;
                    if (s * 2.0 >= sw) {
                        r = x.t;
                        break;
                    }
                }
                a[i] = to_int(r);
            }
        }
    }

    return calc_ans(a);
}

Answer solve_phase_sqrt() {
    vector<int> a = init_sqrt_med();
    vector<char> ban(m, 0);
    Answer best;
    best.val = 1e300;
    vector<pair<double, double>> q;

    for (int ph = 0; ph < 2; ph++) {
        for (int i = 0; i < n; i++) {
            q.clear();
            q.reserve(g[i].size());
            for (int id : g[i]) {
                if (ban[id]) continue;
                const auto &e = es[id];
                int j = e.a ^ e.b ^ i;
                double aj = (double)a[j];
                double t = (double)e.v / aj;
                double wt = (double)e.w * aj / (double)e.v;
                q.push_back({t, wt});
            }
            if (!q.empty()) a[i] = get_med(q);
        }

        auto cur = calc_ans(a);
        if (cur.val < best.val) best = cur;

        fill(ban.begin(), ban.end(), 0);
        for (int id : cur.del) ban[id - 1] = 1;
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> d;
    es.resize(m);
    lg.resize(m);
    vector<int> deg(n, 0);

    for (int i = 0; i < m; i++) {
        int r, c, v, w;
        cin >> r >> c >> v >> w;
        --r, --c;
        es[i] = {r, c, v, w};
        lg[i] = log((double)v);
        deg[r]++, deg[c]++;
    }

    g.assign(n, {});
    for (int i = 0; i < n; i++) g[i].reserve(deg[i]);
    for (int i = 0; i < m; i++) {
        g[es[i].a].push_back(i);
        g[es[i].b].push_back(i);
    }

    Answer ans1 = solve_trim_log();
    Answer ans2 = solve_phase_sqrt();
    Answer ans = ans1.val < ans2.val ? ans1 : ans2;

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << ans.a[i];
    }
    cout << '\n';

    cout << ans.del.size();
    for (int x : ans.del) cout << ' ' << x;
    cout << '\n';

    return 0;
}