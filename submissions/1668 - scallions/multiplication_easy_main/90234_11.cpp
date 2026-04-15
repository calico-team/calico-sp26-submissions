#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static const ll LIM = (ll)1e18;
static const double LOG_LIM = log((long double)LIM);

struct FastScanner {
    static const int BUFSIZE = 1 << 20;
    int idx, size;
    char buf[BUFSIZE];

    FastScanner() : idx(0), size(0) {}

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
            val = val * 10 + (c - '0');
            c = getChar();
        }
        out = val * sign;
        return true;
    }
};

int main() {
    FastScanner fs;

    int N, M, D;
    fs.readInt(N);
    fs.readInt(M);
    fs.readInt(D);

    vector<int> R(M), C(M);
    vector<ll> V(M), W(M);
    vector<double> logV(M), edgeWeight(M); // edgeWeight used in log-space fitting
    vector<double> realCoeff(M);           // W / V for true penalty
    vector<char> discard(M, 0);

    for (int i = 0; i < M; ++i) {
        fs.readInt(R[i]);
        fs.readInt(C[i]);
        fs.readInt(V[i]);
        fs.readInt(W[i]);
        --R[i];
        --C[i];

        logV[i] = log((double)V[i]);
        edgeWeight[i] = (double)W[i];
        realCoeff[i] = (double)W[i] / (double)V[i];
    }

    vector<double> x(N, 0.0), nx(N, 0.0), sum(N), wsum(N);

    // Initial guess: each endpoint gets half of log(V), weighted by W.
    fill(sum.begin(), sum.end(), 0.0);
    fill(wsum.begin(), wsum.end(), 0.0);
    for (int i = 0; i < M; ++i) {
        double t = 0.5 * logV[i];
        double w = edgeWeight[i];
        sum[R[i]] += w * t;
        sum[C[i]] += w * t;
        wsum[R[i]] += w;
        wsum[C[i]] += w;
    }
    for (int i = 0; i < N; ++i) {
        x[i] = (wsum[i] > 0 ? sum[i] / wsum[i] : 0.0);
    }

    auto iterate = [&](int rounds, const vector<char>* disc_ptr) {
        const vector<char>& disc = disc_ptr ? *disc_ptr : discard;
        for (int it = 0; it < rounds; ++it) {
            fill(sum.begin(), sum.end(), 0.0);
            fill(wsum.begin(), wsum.end(), 0.0);

            for (int e = 0; e < M; ++e) {
                if (disc_ptr && disc[e]) continue;
                int u = R[e], v = C[e];
                double w = edgeWeight[e];
                double t = logV[e];

                sum[u] += w * (t - x[v]);
                wsum[u] += w;
                sum[v] += w * (t - x[u]);
                wsum[v] += w;
            }

            for (int i = 0; i < N; ++i) {
                if (wsum[i] > 0) {
                    double y = sum[i] / wsum[i];
                    nx[i] = 0.5 * x[i] + 0.5 * y; // damping for stability
                } else {
                    nx[i] = x[i];
                }
            }
            x.swap(nx);
        }
    };

    auto build_answer = [&](vector<ll>& a) {
        a.resize(N);
        for (int i = 0; i < N; ++i) {
            double y = x[i];
            if (y < 0.0) y = 0.0;
            if (y > LOG_LIM) y = LOG_LIM;
            long double z = expl((long double)y);
            if (z < 1.0L) z = 1.0L;
            if (z > (long double)LIM) z = (long double)LIM;
            a[i] = (ll) llround(z);
            if (a[i] < 1) a[i] = 1;
            if (a[i] > LIM) a[i] = LIM;
        }
    };

    auto choose_discards = [&](const vector<ll>& a) {
        if (D <= 0) {
            fill(discard.begin(), discard.end(), 0);
            return;
        }
        if (D >= M) {
            fill(discard.begin(), discard.end(), 1);
            return;
        }

        vector<double> score(M);
        vector<int> idx(M);
        for (int i = 0; i < M; ++i) {
            long double prod = (long double)a[R[i]] * (long double)a[C[i]];
            long double sc = (long double)realCoeff[i] * fabsl(prod - (long double)V[i]);
            score[i] = (double)sc;
            idx[i] = i;
        }

        nth_element(idx.begin(), idx.begin() + D, idx.end(),
            [&](int i, int j) {
                return score[i] > score[j];
            });

        fill(discard.begin(), discard.end(), 0);
        for (int i = 0; i < D; ++i) discard[idx[i]] = 1;
    };

    auto total_score = [&](const vector<ll>& a) -> long double {
        long double ans = 0;
        for (int i = 0; i < M; ++i) {
            if (discard[i]) continue;
            long double prod = (long double)a[R[i]] * (long double)a[C[i]];
            ans += (long double)realCoeff[i] * fabsl(prod - (long double)V[i]);
        }
        return ans;
    };

    vector<ll> bestA, curA;
    vector<char> bestDiscard;
    long double bestScore = 1e300L;

    // A few restarts with tiny perturbations.
    for (int restart = 0; restart < 3; ++restart) {
        if (restart > 0) {
            for (int i = 0; i < N; ++i) {
                x[i] += ((i * 37 + restart * 101) % 7 - 3) * 0.03;
            }
        }

        // Fit all edges.
        iterate(10, nullptr);
        build_answer(curA);

        // Discard worst D under true objective.
        choose_discards(curA);

        // Refit on kept edges.
        iterate(8, &discard);
        build_answer(curA);

        // Recompute discards once more and a final short refinement.
        choose_discards(curA);
        iterate(4, &discard);
        build_answer(curA);

        long double sc = total_score(curA);
        if (sc < bestScore) {
            bestScore = sc;
            bestA = curA;
            bestDiscard = discard;
        }
    }

    // Output
    for (int i = 0; i < N; ++i) {
        if (i) putchar(' ');
        printf("%lld", bestA[i]);
    }
    putchar('\n');

    int cnt = 0;
    for (int i = 0; i < M; ++i) cnt += bestDiscard[i];
    printf("%d", cnt);
    for (int i = 0; i < M; ++i) {
        if (bestDiscard[i]) {
            printf(" %d", i + 1);
        }
    }
    putchar('\n');

    return 0;
}