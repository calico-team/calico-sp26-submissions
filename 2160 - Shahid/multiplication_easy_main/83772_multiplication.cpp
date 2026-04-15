#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M, D;
    scanf("%d %d %d", &N, &M, &D);

    vector<int> R(M), C(M);
    vector<double> V(M), W(M), logV(M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d %lf %lf", &R[i], &C[i], &V[i], &W[i]);
        R[i]--; C[i]--;
        logV[i] = log(V[i]);
    }

    // Build CSR adjacency
    vector<int> off(N + 1, 0);
    for (int i = 0; i < M; i++) {
        off[R[i] + 1]++;
        off[C[i] + 1]++;
    }
    for (int j = 0; j < N; j++) {
        off[j + 1] += off[j];
    }

    vector<int> adj_ci(2 * M), adj_p(2 * M);
    vector<int> cur(off.begin(), off.begin() + N);

    for (int i = 0; i < M; i++) {
        int r = R[i], c = C[i];
        adj_ci[cur[r]] = i; adj_p[cur[r]] = c; cur[r]++;
        adj_ci[cur[c]] = i; adj_p[cur[c]] = r; cur[c]++;
    }

    // BFS initialization in log-space
    vector<double> x(N, 0.0);
    vector<char> visited(N, 0);

    queue<int> q;
    for (int start = 0; start < N; start++) {
        if (visited[start]) continue;
        if (off[start] == off[start + 1]) continue;

        double sm = 0.0, wt = 0.0;
        for (int k = off[start]; k < off[start + 1]; k++) {
            int ci = adj_ci[k];
            sm += W[ci] * logV[ci] * 0.5;
            wt += W[ci];
        }
        if (wt > 0) x[start] = sm / wt;

        visited[start] = 1;
        q.push(start);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int k = off[u]; k < off[u + 1]; k++) {
                int v = adj_p[k];
                if (!visited[v]) {
                    x[v] = logV[adj_ci[k]] - x[u];
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    // Gauss-Seidel refinement
    int num_iters = min(20, max(5, 500000 / max(M, 1)));
    for (int iter = 0; iter < num_iters; iter++) {
        for (int j = 0; j < N; j++) {
            int sj = off[j], ej = off[j + 1];
            if (sj == ej) continue;
            double num = 0.0, den = 0.0;
            for (int k = sj; k < ej; k++) {
                int ci = adj_ci[k];
                double w = W[ci];
                num += w * (logV[ci] - x[adj_p[k]]);
                den += w;
            }
            if (den > 0) x[j] = num / den;
        }
    }

    // Convert to integers
    vector<long long> a(N);
    for (int j = 0; j < N; j++) {
        double v = exp(x[j]);
        a[j] = max(1LL, min(1000000000LL, (long long)(v + 0.5)));
    }

    // Coordinate descent with weighted median
    int cd_iters = min(5, max(2, 1000000 / max(M, 1)));
    for (int iter = 0; iter < cd_iters; iter++) {
        bool changed = false;
        for (int j = 0; j < N; j++) {
            int sj = off[j], ej = off[j + 1];
            if (sj == ej) continue;

            int deg = ej - sj;
            vector<pair<double, double>> pairs(deg);
            for (int k = sj; k < ej; k++) {
                int ci = adj_ci[k];
                double ap = (double)a[adj_p[k]];
                if (ap <= 0) ap = 1;
                double t = V[ci] / ap;
                double w = W[ci] * ap / V[ci];
                pairs[k - sj] = {t, w};
            }
            sort(pairs.begin(), pairs.end());

            double total_w = 0.0;
            for (auto& p : pairs) total_w += p.second;
            double half = total_w * 0.5;
            double cum_w = 0.0;
            double optimal = pairs[0].first;
            for (auto& p : pairs) {
                cum_w += p.second;
                if (cum_w >= half) {
                    optimal = p.first;
                    break;
                }
            }

            long long cf = max(1LL, min(1000000000LL, (long long)floor(optimal)));
            long long cc = max(1LL, min(1000000000LL, (long long)ceil(optimal)));

            double pf = 0.0, pc = 0.0;
            for (int k = sj; k < ej; k++) {
                int ci = adj_ci[k];
                double ap = (double)a[adj_p[k]];
                if (ap <= 0) ap = 1;
                double v = V[ci], w = W[ci];
                pf += w * fabs((double)cf * ap - v) / v;
                pc += w * fabs((double)cc * ap - v) / v;
            }

            long long nv = (pf <= pc) ? cf : cc;
            if (nv != a[j]) {
                changed = true;
                a[j] = nv;
            }
        }
        if (!changed) break;
    }

    // Output variable values
    for (int j = 0; j < N; j++) {
        if (j > 0) putchar(' ');
        printf("%lld", a[j]);
    }
    putchar('\n');

    // Compute penalties and discard top D
    if (D > 0) {
        vector<double> penalties(M);
        for (int i = 0; i < M; i++) {
            penalties[i] = W[i] * fabs((double)a[R[i]] * (double)a[C[i]] - V[i]) / V[i];
        }

        int dc = min(D, M);
        vector<int> indices(M);
        for (int i = 0; i < M; i++) indices[i] = i;

        partial_sort(indices.begin(), indices.begin() + dc, indices.end(),
                     [&](int a, int b) { return penalties[a] > penalties[b]; });

        vector<int> discard;
        discard.reserve(dc);
        for (int k = 0; k < dc; k++) {
            if (penalties[indices[k]] > 0) {
                discard.push_back(indices[k] + 1);
            }
        }
        sort(discard.begin(), discard.end());

        printf("%d", (int)discard.size());
        for (int idx : discard) {
            printf(" %d", idx);
        }
        putchar('\n');
    } else {
        printf("0\n");
    }

    return 0;
}
