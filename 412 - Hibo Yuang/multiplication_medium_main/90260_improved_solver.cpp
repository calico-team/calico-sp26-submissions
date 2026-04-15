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
        char c = getChar();
        if (!c) return false;
        while (c != '-' && (c < '0' || c > '9')) {
            c = getChar();
            if (!c) return false;
        }
        T sign = 1;
        if (c == '-') {
            sign = -1;
            c = getChar();
        }
        T val = 0;
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

    struct Item {
        double t;
        double w;
        bool operator<(const Item &other) const { return t < other.t; }
    };

    int N = 0, M = 0, D = 0;
    vector<int> U, V, Val, W;
    vector<double> LogVal, InvVal;

    vector<int> degCnt;
    vector<int> adjStart;
    vector<int> adj;
    int maxDeg = 0;

    vector<int> nodeOrder, revNodeOrder;
    vector<unsigned char> active;
    vector<double> penalties;
    vector<int> order;

    vector<double> degW, rhs, x, logCur;
    vector<long long> curA, better_than_me;
    vector<int> bestDiscard;

    vector<Item> scratch;
    vector<int> discards;

    chrono::steady_clock::time_point startTime;
    double budgetSeconds = 9.15;

    inline long long clampA(long long z) const {
        if (z < MIN_A) return MIN_A;
        if (z > MAX_A) return MAX_A;
        return z;
    }

    inline double elapsed() const {
        return chrono::duration<double>(chrono::steady_clock::now() - startTime).count();
    }

    inline bool out_of_time(double margin = 0.0) const {
        return elapsed() >= budgetSeconds - margin;
    }

    inline double safeLogA(long long v) const {
        return log((double)max(1LL, v));
    }

    inline long long expToA(double z) const {
        static const double LOG_MAX_A = log((double)MAX_A);
        if (z <= 0.0) return MIN_A;
        if (z >= LOG_MAX_A) return MAX_A;
        long long v = llround(exp(z));
        return clampA(v);
    }

    inline double boundedExp(double z) const {
        static const double LOG_MAX_A = log((double)MAX_A);
        if (z <= 0.0) return 1.0;
        if (z >= LOG_MAX_A) return (double)MAX_A;
        return exp(z);
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
            int r, c, val, w;
            fs.readInt(r);
            fs.readInt(c);
            fs.readInt(val);
            fs.readInt(w);
            --r; --c;
            U[i] = r;
            V[i] = c;
            Val[i] = val;
            W[i] = w;
            LogVal[i] = log((double)val);
            InvVal[i] = 1.0 / (double)val;
            ++degCnt[r];
            ++degCnt[c];
        }

        adjStart.assign(N + 1, 0);
        maxDeg = 0;
        for (int i = 0; i < N; ++i) {
            maxDeg = max(maxDeg, degCnt[i]);
            adjStart[i + 1] = adjStart[i] + degCnt[i];
        }
        adj.assign(2 * M, 0);
        vector<int> ptr = adjStart;
        for (int i = 0; i < M; ++i) {
            adj[ptr[U[i]]++] = i;
            adj[ptr[V[i]]++] = i;
        }

        nodeOrder.resize(N);
        iota(nodeOrder.begin(), nodeOrder.end(), 0);
        stable_sort(nodeOrder.begin(), nodeOrder.end(), [&](int a, int b) {
            if (degCnt[a] != degCnt[b]) return degCnt[a] > degCnt[b];
            return a < b;
        });
        revNodeOrder = nodeOrder;
        reverse(revNodeOrder.begin(), revNodeOrder.end());

        active.assign(M, 1);
        penalties.assign(M, 0.0);
        order.resize(M);
        degW.assign(N, 0.0);
        rhs.assign(N, 0.0);
        x.assign(N, 0.0);
        logCur.assign(N, 0.0);
        curA.assign(N, 1);
        better_than_me.assign(N, 1);
        scratch.reserve(maxDeg);
        discards.reserve(D);
    }

    void sync_logs_from_cur() {
        for (int i = 0; i < N; ++i) logCur[i] = safeLogA(curA[i]);
    }

    void set_cur(const vector<long long> &a) {
        curA = a;
        sync_logs_from_cur();
    }

    void init_all_ones(vector<long long> &a) {
        a.assign(N, 1);
    }

    void init_local_geomean(vector<long long> &a) {
        a.assign(N, 1);
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
            if (degW[i] > 0.0) a[i] = expToA(0.5 * rhs[i] / degW[i]);
        }
    }

    void gauss_seidel_log_ls(vector<long long> &a, int sweeps, const vector<unsigned char> *act = nullptr, bool warmStart = false) {
        if (!warmStart) {
            fill(degW.begin(), degW.end(), 0.0);
            fill(rhs.begin(), rhs.end(), 0.0);
            for (int i = 0; i < M; ++i) {
                if (act && !(*act)[i]) continue;
                double ww = (double)W[i];
                degW[U[i]] += ww;
                degW[V[i]] += ww;
                rhs[U[i]] += ww * LogVal[i];
                rhs[V[i]] += ww * LogVal[i];
            }
            for (int i = 0; i < N; ++i) x[i] = (degW[i] > 0.0 ? 0.5 * rhs[i] / degW[i] : 0.0);
        } else {
            for (int i = 0; i < N; ++i) x[i] = safeLogA(a[i]);
            fill(degW.begin(), degW.end(), 0.0);
            fill(rhs.begin(), rhs.end(), 0.0);
            for (int i = 0; i < M; ++i) {
                if (act && !(*act)[i]) continue;
                double ww = (double)W[i];
                degW[U[i]] += ww;
                degW[V[i]] += ww;
                rhs[U[i]] += ww * LogVal[i];
                rhs[V[i]] += ww * LogVal[i];
            }
        }

        double lambda = 1e-8;
        auto relax_node = [&](int j, double &maxDiff) {
            if (degW[j] <= 0.0) return;
            double num = rhs[j];
            for (int p = adjStart[j]; p < adjStart[j + 1]; ++p) {
                int id = adj[p];
                if (act && !(*act)[id]) continue;
                int other = U[id] + V[id] - j;
                num -= (double)W[id] * x[other];
            }
            double xnew = num / (degW[j] + lambda);
            maxDiff = max(maxDiff, fabs(xnew - x[j]));
            x[j] = xnew;
        };

        for (int it = 0; it < sweeps && !out_of_time(0.25); ++it) {
            double maxDiff = 0.0;
            for (int j : nodeOrder) relax_node(j, maxDiff);
            for (int j : revNodeOrder) relax_node(j, maxDiff);
            if (maxDiff < 1e-9) break;
        }

        for (int i = 0; i < N; ++i) {
            if (degW[i] > 0.0) a[i] = expToA(x[i]);
        }
    }

    inline pair<double, double> weighted_interval_sorted() {
        double sw = 0.0;
        for (const auto &it : scratch) sw += it.w;
        double half = 0.5 * sw;

        double L = scratch.back().t;
        double cum = 0.0;
        for (const auto &it : scratch) {
            cum += it.w;
            if (cum >= half) {
                L = it.t;
                break;
            }
        }

        double Uv = scratch.front().t;
        cum = 0.0;
        for (int idx = (int)scratch.size() - 1; idx >= 0; --idx) {
            cum += scratch[idx].w;
            if (cum >= half) {
                Uv = scratch[idx].t;
                break;
            }
        }
        return {L, Uv};
    }

    void exact_sweep_original(int rounds, const vector<unsigned char> *act = nullptr) {
        for (int rep = 0; rep < rounds && !out_of_time(0.25); ++rep) {
            bool changed = false;
            for (int pass = 0; pass < 2 && !out_of_time(0.25); ++pass) {
                const vector<int> &ord = (pass == 0 ? nodeOrder : revNodeOrder);
                for (int j : ord) {
                    scratch.clear();
                    for (int p = adjStart[j]; p < adjStart[j + 1]; ++p) {
                        int id = adj[p];
                        if (act && !(*act)[id]) continue;
                        int other = U[id] + V[id] - j;
                        long long b = curA[other];
                        double t = (double)Val[id] / (double)b;
                        double lam = (double)W[id] * (double)b * InvVal[id];
                        scratch.push_back({t, lam});
                    }
                    if (scratch.empty()) continue;
                    sort(scratch.begin(), scratch.end());
                    auto [L, Uv] = weighted_interval_sorted();

                    long long lo = clampA((long long)ceil(L - 1e-12));
                    long long hi = clampA((long long)floor(Uv + 1e-12));
                    long long oldv = curA[j];
                    long long bestv = oldv;

                    if (lo <= hi) {
                        if (oldv < lo) bestv = lo;
                        else if (oldv > hi) bestv = hi;
                    } else {
                        long long c1 = clampA((long long)floor(L));
                        long long c2 = clampA((long long)ceil(Uv));
                        if (c1 == c2) bestv = c1;
                        else {
                            double cost1 = 0.0, cost2 = 0.0;
                            double d1 = (double)c1, d2 = (double)c2;
                            for (const auto &it : scratch) {
                                cost1 += it.w * fabs(d1 - it.t);
                                cost2 += it.w * fabs(d2 - it.t);
                            }
                            if (cost1 < cost2 - 1e-12) bestv = c1;
                            else if (cost2 < cost1 - 1e-12) bestv = c2;
                            else bestv = (fabs((double)oldv - d1) <= fabs((double)oldv - d2) ? c1 : c2);
                        }
                    }

                    if (bestv != oldv) {
                        curA[j] = bestv;
                        logCur[j] = safeLogA(bestv);
                        changed = true;
                    }
                }
            }
            if (!changed) break;
        }
    }

    void sweep_log_l1_surrogate(int rounds, const vector<unsigned char> *act = nullptr) {
        for (int rep = 0; rep < rounds && !out_of_time(0.25); ++rep) {
            bool changed = false;
            for (int pass = 0; pass < 2 && !out_of_time(0.25); ++pass) {
                const vector<int> &ord = (pass == 0 ? nodeOrder : revNodeOrder);
                for (int j : ord) {
                    scratch.clear();
                    for (int p = adjStart[j]; p < adjStart[j + 1]; ++p) {
                        int id = adj[p];
                        if (act && !(*act)[id]) continue;
                        int other = U[id] + V[id] - j;
                        double t = LogVal[id] - logCur[other];
                        double ww = (double)W[id];
                        scratch.push_back({t, ww});
                    }
                    if (scratch.empty()) continue;
                    sort(scratch.begin(), scratch.end());
                    auto [Lz, Uz] = weighted_interval_sorted();

                    double lowReal = boundedExp(Lz);
                    double highReal = boundedExp(Uz);
                    long long lo = clampA((long long)ceil(lowReal - 1e-12));
                    long long hi = clampA((long long)floor(highReal + 1e-12));
                    long long oldv = curA[j];
                    long long bestv = oldv;

                    if (lo <= hi) {
                        if (oldv < lo) bestv = lo;
                        else if (oldv > hi) bestv = hi;
                    } else {
                        long long c1 = clampA((long long)floor(lowReal));
                        long long c2 = clampA((long long)ceil(highReal));
                        if (c1 == c2) bestv = c1;
                        else {
                            double z1 = safeLogA(c1), z2 = safeLogA(c2);
                            double cost1 = 0.0, cost2 = 0.0;
                            for (const auto &it : scratch) {
                                cost1 += it.w * fabs(z1 - it.t);
                                cost2 += it.w * fabs(z2 - it.t);
                            }
                            if (cost1 < cost2 - 1e-12) bestv = c1;
                            else if (cost2 < cost1 - 1e-12) bestv = c2;
                            else bestv = (fabs(logCur[j] - z1) <= fabs(logCur[j] - z2) ? c1 : c2);
                        }
                    }

                    if (bestv != oldv) {
                        curA[j] = bestv;
                        logCur[j] = safeLogA(bestv);
                        changed = true;
                    }
                }
            }
            if (!changed) break;
        }
    }

    void set_active_from_discards(const vector<int> &drop) {
        fill(active.begin(), active.end(), (unsigned char)1);
        for (int id : drop) active[id] = 0;
    }

    long double evaluate_trimmed(const vector<long long> &a, vector<int> *drop = nullptr) {
        long double total = 0.0L;
        for (int i = 0; i < M; ++i) {
            long double prod = (long double)a[U[i]] * (long double)a[V[i]];
            long double diff = fabsl(prod - (long double)Val[i]);
            double pen = (double)((long double)W[i] * diff * (long double)InvVal[i]);
            penalties[i] = pen;
            total += (long double)pen;
        }

        if (D == 0) {
            if (drop) drop->clear();
            return total;
        }
        if (D >= M) {
            if (drop) {
                drop->resize(M);
                iota(drop->begin(), drop->end(), 0);
            }
            return 0.0L;
        }

        iota(order.begin(), order.end(), 0);
        nth_element(order.begin(), order.begin() + D, order.end(), [&](int aIdx, int bIdx) {
            return penalties[aIdx] > penalties[bIdx];
        });
        long double removed = 0.0L;
        if (drop) drop->assign(order.begin(), order.begin() + D);
        for (int i = 0; i < D; ++i) removed += (long double)penalties[order[i]];
        return total - removed;
    }

    struct Plan {
        int initMode;          // 0 ones, 1 local, 2 ls
        int initLsSweeps;
        int preLogRounds;
        int preExactRounds;
        int outerLoops;
        int activeLogRounds;
        int activeExactRounds;
        int edgeKickK;
    };

    vector<long long> build_initial_array(const Plan &plan) {
        vector<long long> a;
        if (plan.initMode == 0) init_all_ones(a);
        else if (plan.initMode == 1) init_local_geomean(a);
        else {
            init_local_geomean(a);
            gauss_seidel_log_ls(a, plan.initLsSweeps, nullptr, false);
        }
        return a;
    }

    long double score_current(vector<int> *drop = nullptr) {
        return evaluate_trimmed(curA, drop);
    }

    void maybe_update_global_best(const vector<long long> &candidate, long double score, const vector<int> &drop) {
        static long double bestScore = numeric_limits<long double>::infinity();
        if (score + 1e-12L < bestScore) {
            bestScore = score;
            better_than_me = candidate;
            bestDiscard = drop;
        }
    }

    long double run_plan(const Plan &plan) {
        vector<long long> a = build_initial_array(plan);
        set_cur(a);

        if (plan.preLogRounds > 0) sweep_log_l1_surrogate(plan.preLogRounds, nullptr);
        if (plan.preExactRounds > 0) exact_sweep_original(plan.preExactRounds, nullptr);

        vector<long long> localBestA = curA;
        vector<int> localBestDrop;
        long double localBestScore = score_current(&localBestDrop);

        if (D > 0) set_active_from_discards(localBestDrop);
        else fill(active.begin(), active.end(), (unsigned char)1);

        for (int outer = 0; outer < plan.outerLoops && !out_of_time(0.35); ++outer) {
            if (plan.activeLogRounds > 0) sweep_log_l1_surrogate(plan.activeLogRounds, &active);
            if (plan.activeExactRounds > 0) exact_sweep_original(plan.activeExactRounds, &active);

            vector<int> drop;
            long double score = score_current(&drop);
            if (score + 1e-12L < localBestScore) {
                localBestScore = score;
                localBestA = curA;
                localBestDrop = drop;
            }
            if (outer + 1 < plan.outerLoops && D > 0) set_active_from_discards(drop);
        }

        // Small local escape on a few high-penalty kept edges.
        if (plan.edgeKickK > 0 && !out_of_time(0.35)) {
            set_cur(localBestA);
            score_current(&discards);
            vector<int> candKeep;
            candKeep.reserve(plan.edgeKickK);
            if (D < M) {
                int need = min(plan.edgeKickK, max(0, M - D));
                iota(order.begin(), order.end(), 0);
                int kth = D + need;
                if (kth < M) {
                    nth_element(order.begin(), order.begin() + kth, order.end(), [&](int aIdx, int bIdx) {
                        return penalties[aIdx] > penalties[bIdx];
                    });
                } else {
                    sort(order.begin(), order.end(), [&](int aIdx, int bIdx) {
                        return penalties[aIdx] > penalties[bIdx];
                    });
                }
                vector<unsigned char> isDrop(M, 0);
                for (int i = 0; i < D; ++i) isDrop[order[i]] = 1;
                for (int i = D; i < M && (int)candKeep.size() < need; ++i) {
                    int id = order[i];
                    if (!isDrop[id]) candKeep.push_back(id);
                }
            }

            if (!candKeep.empty()) {
                set_active_from_discards(discards);
                vector<long long> saved = curA;
                vector<long long> bestKickA = localBestA;
                vector<int> bestKickDrop = discards;
                long double bestKickScore = localBestScore;

                for (int id : candKeep) {
                    if (out_of_time(0.30)) break;
                    int u = U[id], v = V[id];
                    for (int side = 0; side < 2; ++side) {
                        curA = saved;
                        sync_logs_from_cur();
                        int changeNode = (side == 0 ? u : v);
                        int otherNode = (side == 0 ? v : u);
                        long long otherVal = curA[otherNode];
                        curA[changeNode] = clampA((long long)llround((double)Val[id] / (double)otherVal));
                        logCur[changeNode] = safeLogA(curA[changeNode]);
                        exact_sweep_original(1, &active);
                        vector<int> drop;
                        long double score = score_current(&drop);
                        if (score + 1e-12L < bestKickScore) {
                            bestKickScore = score;
                            bestKickA = curA;
                            bestKickDrop = drop;
                        }
                    }
                }
                if (bestKickScore + 1e-12L < localBestScore) {
                    localBestScore = bestKickScore;
                    localBestA.swap(bestKickA);
                    localBestDrop.swap(bestKickDrop);
                }
            }
        }

        maybe_update_global_best(localBestA, localBestScore, localBestDrop);
        return localBestScore;
    }

    void solve() {
        startTime = chrono::steady_clock::now();
        read_input();

        if (D >= M) {
            better_than_me.assign(N, 1);
            bestDiscard.resize(M);
            iota(bestDiscard.begin(), bestDiscard.end(), 0);
            write_answer();
            return;
        }

        // Fallback very cheap baseline.
        init_local_geomean(better_than_me);
        long double baseScore = evaluate_trimmed(better_than_me, &bestDiscard);
        (void)baseScore;

        int outer = 4, initLsSweeps = 10, kickK = 6;
        int exactActive = 1, logActive = 0;
        int planLimit = 4;
        int preLog = 2;
        if (M > 1600000) {
            outer = 2;
            initLsSweeps = 5;
            kickK = 0;
            exactActive = 1;
            logActive = 0;
            preLog = 1;
            planLimit = 1;
            budgetSeconds = 8.90;
        } else if (M > 900000) {
            outer = 3;
            initLsSweeps = 6;
            kickK = 0;
            exactActive = 1;
            logActive = 0;
            preLog = 2;
            planLimit = 2;
            budgetSeconds = 9.00;
        } else if (M > 350000) {
            outer = 3;
            initLsSweeps = 8;
            kickK = 0;
            exactActive = 1;
            logActive = 0;
            preLog = 2;
            planLimit = 2;
        }

        vector<Plan> plans;
        plans.push_back({2, initLsSweeps, preLog, 0, outer, logActive, exactActive, kickK});      // LS -> log-L1 init -> trimmed exact
        plans.push_back({0, initLsSweeps, preLog, 0, outer, logActive, exactActive, kickK});      // ones -> log-L1 init -> trimmed exact
        plans.push_back({1, initLsSweeps, 0, 0, outer, 0, exactActive, kickK / 2});               // local geomean
        plans.push_back({2, initLsSweeps, 0, 0, outer, 0, exactActive + 1, kickK / 2});           // plain LS + exact

        for (int i = 0; i < (int)plans.size() && i < planLimit; ++i) {
            if (out_of_time(0.40)) break;
            run_plan(plans[i]);
        }

        // Final polish only when the instance is not too large.
        if (M <= 900000 && !better_than_me.empty() && !out_of_time(0.25)) {
            set_cur(better_than_me);
            vector<int> drop;
            long double bestScore = score_current(&drop);
            if (D > 0) set_active_from_discards(drop);
            else fill(active.begin(), active.end(), (unsigned char)1);
            if (!out_of_time(0.20)) sweep_log_l1_surrogate(1, &active);
            if (!out_of_time(0.15)) exact_sweep_original(1, &active);
            long double newScore = score_current(&drop);
            if (newScore + 1e-12L < bestScore) {
                better_than_me = curA;
                bestDiscard = drop;
            }
        }

        if (bestDiscard.empty()) evaluate_trimmed(better_than_me, &bestDiscard);
        write_answer();
    }

    void write_answer() {
        for (int i = 0; i < N; ++i) {
            if (i) cout << ' ';
            cout << better_than_me[i];
        }
        cout << '\n';
        cout << bestDiscard.size();
        for (int id : bestDiscard) cout << ' ' << (id + 1);
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
