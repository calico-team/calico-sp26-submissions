//this was written using chatgpt as a test
#include <bits/stdc++.h>
using namespace std;

struct FastScanner {
    static constexpr size_t BUFSIZE = 1 << 20;
    int idx = 0, size = 0;
    char buf[BUFSIZE];

    inline char getChar() {
        if (idx >= size) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }

    template <class T>
    bool readInt(T &out) {
        char c;
        T sign = 1;
        T val = 0;
        c = getChar();
        if (!c) return false;
        while (c != '-' && (c < '0' || c > '9')) {
            c = getChar();
            if (!c) return false;
        }
        if (c == '-') {
            sign = -1;
            c = getChar();
        }
        while (c >= '0' && c <= '9') {
            val = (T)(val * 10 + (c - '0'));
            c = getChar();
        }
        out = val * sign;
        return true;
    }
};

struct Solver {
    static constexpr long long MIN_A = 1;
    static constexpr long long MAX_A = 1000000000LL;

    int N = 0, M = 0, D = 0;
    vector<int> U, V, Val, W;
    vector<double> LogVal, InvVal;

    vector<int> degCnt;
    vector<int> adjStart;
    vector<int> adj;
    int maxDeg = 0;

    vector<int> nodeOrder;
    vector<int> revNodeOrder;

    vector<unsigned char> active;
    vector<double> degW, rhs, x, logA, penalties;
    vector<long long> a, better_than_me;
    vector<int> order;

    struct Item {
        double t;
        double lam;
        bool operator<(const Item &other) const { return t < other.t; }
    };
    vector<Item> scratch;

    inline long long clampA(long long z) const {
        if (z < MIN_A) return MIN_A;
        if (z > MAX_A) return MAX_A;
        return z;
    }

    inline long long expToA(double z) const {
        static const double LOG_MAX_A = log((double)MAX_A);
        if (z <= 0.0) return MIN_A;
        if (z >= LOG_MAX_A) return MAX_A;
        long long v = llround(exp(z));
        return clampA(v);
    }

    void read_input() {
        FastScanner fs;
        fs.readInt(N);
        fs.readInt(M);
        fs.readInt(D);

        U.resize(M);
        V.resize(M);
        Val.resize(M);
        W.resize(M);
        LogVal.resize(M);
        InvVal.resize(M);
        degCnt.assign(N, 0);

        for (int i = 0; i < M; ++i) {
            int r, c, v, w;
            fs.readInt(r);
            fs.readInt(c);
            fs.readInt(v);
            fs.readInt(w);
            --r; --c;
            U[i] = r;
            V[i] = c;
            Val[i] = v;
            W[i] = w;
            LogVal[i] = log((double)v);
            InvVal[i] = 1.0 / (double)v;
            ++degCnt[r];
            ++degCnt[c];
        }

        maxDeg = 0;
        adjStart.assign(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            maxDeg = max(maxDeg, degCnt[i]);
            adjStart[i + 1] = adjStart[i] + degCnt[i];
        }
        adj.assign(2 * M, 0);
        vector<int> cur = adjStart;
        for (int i = 0; i < M; ++i) {
            adj[cur[U[i]]++] = i;
            adj[cur[V[i]]++] = i;
        }

        nodeOrder.resize(N);
        iota(nodeOrder.begin(), nodeOrder.end(), 0);
        stable_sort(nodeOrder.begin(), nodeOrder.end(), [&](int a, int b) {
            return degCnt[a] > degCnt[b];
        });
        revNodeOrder = nodeOrder;
        reverse(revNodeOrder.begin(), revNodeOrder.end());

        active.assign(M, 1);
        degW.assign(N, 0.0);
        rhs.assign(N, 0.0);
        x.assign(N, 0.0);
        logA.assign(N, 0.0);
        penalties.assign(M, 0.0);
        a.assign(N, 1);
        better_than_me.assign(N, 1);
        order.resize(M);
        scratch.reserve(maxDeg);
    }

    void initialize_from_local_geomean() {
        fill(degW.begin(), degW.end(), 0.0);
        fill(rhs.begin(), rhs.end(), 0.0);
        for (int i = 0; i < M; ++i) {
            double ww = (double)W[i];
            double lv = LogVal[i];
            degW[U[i]] += ww;
            degW[V[i]] += ww;
            rhs[U[i]] += ww * lv;
            rhs[V[i]] += ww * lv;
        }
        for (int i = 0; i < N; ++i) {
            if (degW[i] <= 0.0) {
                a[i] = 1;
            } else {
                double zi = 0.5 * rhs[i] / degW[i];
                a[i] = expToA(zi);
            }
            logA[i] = log((double)a[i]);
        }
    }

    void set_active_from_discards(const vector<int> &discards) {
        fill(active.begin(), active.end(), (unsigned char)1);
        for (int id : discards) active[id] = 0;
    }

    void gauss_seidel(int sweeps) {
        fill(degW.begin(), degW.end(), 0.0);
        fill(rhs.begin(), rhs.end(), 0.0);
        long double sumWActive = 0.0L;
        for (int i = 0; i < M; ++i) {
            if (!active[i]) continue;
            double ww = (double)W[i];
            degW[U[i]] += ww;
            degW[V[i]] += ww;
            rhs[U[i]] += ww * LogVal[i];
            rhs[V[i]] += ww * LogVal[i];
            sumWActive += (long double)W[i];
        }

        double lambda = (double)max(1.0e-12L, (2.0L * sumWActive / max(1, N)) * 1.0e-6L);

        for (int i = 0; i < N; ++i) x[i] = logA[i];

        auto relax_node = [&](int j, double &maxDiff) {
            if (degW[j] <= 0.0) return;
            double num = rhs[j];
            for (int p = adjStart[j]; p < adjStart[j + 1]; ++p) {
                int id = adj[p];
                if (!active[id]) continue;
                int other = U[id] + V[id] - j;
                num -= (double)W[id] * x[other];
            }
            double xnew = num / (degW[j] + lambda);
            maxDiff = max(maxDiff, fabs(xnew - x[j]));
            x[j] = xnew;
        };

        for (int it = 0; it < sweeps; ++it) {
            double maxDiff = 0.0;
            for (int j : nodeOrder) relax_node(j, maxDiff);
            for (int j : revNodeOrder) relax_node(j, maxDiff);
            if (maxDiff < 1e-9) break;
        }

        for (int i = 0; i < N; ++i) {
            if (degW[i] > 0.0) {
                a[i] = expToA(x[i]);
                logA[i] = log((double)a[i]);
            }
        }
    }

    void update_one_node(int j, bool &changed) {
        scratch.clear();
        double sw = 0.0;
        double slog = 0.0;

        for (int p = adjStart[j]; p < adjStart[j + 1]; ++p) {
            int id = adj[p];
            if (!active[id]) continue;
            int other = U[id] + V[id] - j;
            long long b = a[other];
            double t = (double)Val[id] / (double)b;
            double lam = (double)W[id] * (double)b * InvVal[id];
            scratch.push_back({t, lam});
            sw += lam;
            slog += lam * (LogVal[id] - logA[other]);
        }

        if (scratch.empty()) return;

        sort(scratch.begin(), scratch.end());

        double half = 0.5 * sw;
        double prefLog = slog / sw;
        double pref = exp(prefLog);

        double L = scratch.back().t;
        double cum = 0.0;
        for (const auto &it : scratch) {
            cum += it.lam;
            if (cum >= half) {
                L = it.t;
                break;
            }
        }

        double Uv = scratch.front().t;
        cum = 0.0;
        for (int idx = (int)scratch.size() - 1; idx >= 0; --idx) {
            cum += scratch[idx].lam;
            if (cum >= half) {
                Uv = scratch[idx].t;
                break;
            }
        }

        if (pref < L) pref = L;
        if (pref > Uv) pref = Uv;

        long long cand[4] = {
            a[j],
            clampA((long long)floor(L)),
            clampA((long long)ceil(Uv)),
            clampA((long long)llround(pref))
        };
        sort(cand, cand + 4);

        long long bestY = a[j];
        double bestCost = numeric_limits<double>::infinity();
        double bestTie = numeric_limits<double>::infinity();

        for (int ii = 0; ii < 4; ++ii) {
            if (ii > 0 && cand[ii] == cand[ii - 1]) continue;
            long long y = cand[ii];
            double cost = 0.0;
            double yd = (double)y;
            for (const auto &it : scratch) {
                cost += it.lam * fabs(yd - it.t);
            }
            double tie = fabs(log((double)y) - prefLog);
            if (cost + 1e-12 < bestCost || (fabs(cost - bestCost) <= 1e-12 && tie < bestTie)) {
                bestCost = cost;
                bestTie = tie;
                bestY = y;
            }
        }

        if (bestY != a[j]) {
            a[j] = bestY;
            logA[j] = log((double)bestY);
            changed = true;
        }
    }

    void coordinate_descent(int rounds) {
        for (int it = 0; it < rounds; ++it) {
            bool changed = false;
            for (int j : nodeOrder) update_one_node(j, changed);
            for (int j : revNodeOrder) update_one_node(j, changed);
            if (!changed) break;
        }
    }

    long double evaluate_trimmed(const vector<long long> &arr, vector<int> *discards = nullptr) {
        long double total = 0.0L;
        for (int i = 0; i < M; ++i) {
            long double prod = (long double)arr[U[i]] * (long double)arr[V[i]];
            long double diff = fabsl(prod - (long double)Val[i]);
            double pen = (double)((long double)W[i] * diff * (long double)InvVal[i]);
            penalties[i] = pen;
            total += (long double)pen;
        }

        if (D == 0) {
            if (discards) discards->clear();
            return total;
        }
        if (D == M) {
            if (discards) {
                discards->resize(M);
                iota(discards->begin(), discards->end(), 0);
            }
            return 0.0L;
        }

        iota(order.begin(), order.end(), 0);
        nth_element(order.begin(), order.begin() + D, order.end(), [&](int a, int b) {
            return penalties[a] > penalties[b];
        });

        long double removed = 0.0L;
        for (int i = 0; i < D; ++i) removed += (long double)penalties[order[i]];

        if (discards) {
            discards->assign(order.begin(), order.begin() + D);
        }
        return total - removed;
    }

    void final_polish() {
        if (D == 0 || D == M) return;
        a = better_than_me;
        for (int i = 0; i < N; ++i) logA[i] = log((double)a[i]);

        vector<int> discards;
        long double baseScore = evaluate_trimmed(a, &discards);
        set_active_from_discards(discards);
        gauss_seidel(4);
        coordinate_descent(1);
        long double newScore = evaluate_trimmed(a, nullptr);
        if (newScore + 1e-12L < baseScore) {
            better_than_me = a;
        }
    }

    void solve() {
        read_input();

        if (D == M) {
            for (int i = 0; i < N; ++i) {
                if (i) cout << ' ';
                cout << 1;
            }
            cout << '\n' << M;
            for (int i = 1; i <= M; ++i) cout << ' ' << i;
            cout << '\n';
            return;
        }

        initialize_from_local_geomean();
        better_than_me = a;
        long double bestScore = evaluate_trimmed(a, nullptr);

        vector<int> discards;
        int phases = (D > 0 ? 3 : 1);
        for (int phase = 0; phase < phases; ++phase) {
            gauss_seidel(phase == 0 ? 10 : 8);
            coordinate_descent(2);
            long double curScore = evaluate_trimmed(a, &discards);
            if (curScore + 1e-12L < bestScore) {
                bestScore = curScore;
                better_than_me = a;
            }
            if (phase + 1 < phases) {
                set_active_from_discards(discards);
            }
        }

        final_polish();

        vector<int> finalDiscards;
        evaluate_trimmed(better_than_me, &finalDiscards);

        for (int i = 0; i < N; ++i) {
            if (i) cout << ' ';
            cout << better_than_me[i];
        }
        cout << '\n';
        cout << finalDiscards.size();
        for (int id : finalDiscards) cout << ' ' << (id + 1);
        cout << '\n';
    }
};

static void read_your_input() {}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solver solver;
    solver.solve();
    return 0;
}
