#include <bits/stdc++.h>
using namespace std;
struct Constraint { int r, c, v, w; };

int N, M, D;
vector<Constraint> cons;
vector<double> logV;

void optimize(vector<double>& x, const vector<bool>& discarded) {
    fill(x.begin(), x.end(), 0.0);

    // BFS init
    vector<vector<pair<int,int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        if (discarded[i]) continue;
        adj[cons[i].r].push_back({cons[i].c, i});
        adj[cons[i].c].push_back({cons[i].r, i});
    }
    vector<bool> visited(N + 1, false);
    queue<int> q;
    for (int s = 1; s <= N; s++) {
        if (!visited[s]) {
            visited[s] = true; q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto [vn, idx] : adj[u]) {
                    if (!visited[vn]) {
                        visited[vn] = true;
                        x[vn] = logV[idx] - x[u];
                        q.push(vn);
                    }
                }
            }
        }
    }

    // Coordinate descent
    vector<vector<tuple<int,double,int>>> nc(N + 1);
    for (int i = 0; i < M; i++) {
        if (discarded[i]) continue;
        nc[cons[i].r].emplace_back(cons[i].c, logV[i], cons[i].w);
        nc[cons[i].c].emplace_back(cons[i].r, logV[i], cons[i].w);
    }
    for (int iter = 0; iter < 300; iter++) {
        double mc = 0;
        for (int i = 1; i <= N; i++) {
            if (nc[i].empty()) continue;
            double num = 0, den = 0;
            for (auto& [p, lv, w] : nc[i]) {
                num += w * (lv - x[p]);
                den += w;
            }
            double nx = num / den;
            mc = max(mc, abs(nx - x[i]));
            x[i] = nx;
        }
        if (mc < 1e-12) break;
    }
}

double total_penalty(const vector<double>& x, const vector<bool>& discarded) {
    double p = 0;
    for (int i = 0; i < M; i++) {
        if (discarded[i]) continue;
        double prod = exp(x[cons[i].r] + x[cons[i].c]);
        p += (double)cons[i].w * abs(prod - cons[i].v) / cons[i].v;
    }
    return p;
}

void read_your_input() {
    cin >> N >> M >> D;
    cons.resize(M);
    logV.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> cons[i].r >> cons[i].c >> cons[i].v >> cons[i].w;
        logV[i] = log((double)cons[i].v);
    }

    // Sort constraints by weight descending - high weight ones are
    // most likely to be the outliers worth discarding
    vector<int> by_weight(M);
    iota(by_weight.begin(), by_weight.end(), 0);
    sort(by_weight.begin(), by_weight.end(), [](int a, int b){
        return cons[a].w > cons[b].w;
    });

    vector<bool> best_discarded(M, false);
    vector<double> best_x(N + 1, 0.0);
    double best_pen = 1e18;

    // How many candidates to try for discard = top candidates by weight
    // For large M, limit to top sqrt(M) or so
    int num_candidates = min(M, max(D * 3, 200));

    // Try: for each subset of size D from top candidates, optimize and score
    // For D=1: just try each candidate individually (O(candidates * optimize))
    // For D>1: greedy - pick best single discard, then best second, etc.

    auto try_discard_set = [&](vector<int> to_discard) -> pair<double, vector<double>> {
        vector<bool> disc(M, false);
        for (int i : to_discard) disc[i] = true;
        vector<double> x(N + 1, 0.0);
        optimize(x, disc);
        return {total_penalty(x, disc), x};
    };

    // Start: no discards
    {
        auto [pen, x] = try_discard_set({});
        if (pen < best_pen) {
            best_pen = pen;
            best_x = x;
            best_discarded.assign(M, false);
        }
    }

    if (D > 0) {
        // Greedy forward: build discard set one at a time
        // At each step, try adding each of top candidates not yet discarded
        vector<int> current_discards;
        vector<bool> in_discard(M, false);

        for (int round = 0; round < D; round++) {
            double round_best_pen = 1e18;
            int round_best_cand = -1;
            vector<double> round_best_x;

            for (int ci = 0; ci < num_candidates; ci++) {
                int cand = by_weight[ci];
                if (in_discard[cand]) continue;

                vector<int> trial = current_discards;
                trial.push_back(cand);
                auto [pen, x] = try_discard_set(trial);

                if (pen < round_best_pen) {
                    round_best_pen = pen;
                    round_best_cand = cand;
                    round_best_x = x;
                }
            }

            if (round_best_cand == -1 || round_best_pen >= best_pen - 1e-9) break;

            current_discards.push_back(round_best_cand);
            in_discard[round_best_cand] = true;
            best_pen = round_best_pen;
            best_x = round_best_x;
            best_discarded.assign(M, false);
            for (int i : current_discards) best_discarded[i] = true;
        }
    }

    // Output
    for (int i = 1; i <= N; i++) {
        long long val = llround(exp(best_x[i]));
        val = max(1LL, min((long long)1e9, val));
        cout << val << " \n"[i == N];
    }

    int cnt = 0;
    for (bool d : best_discarded) if (d) cnt++;
    cout << cnt;
    for (int i = 0; i < M; i++) if (best_discarded[i]) cout << " " << (i+1);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_your_input();
    return 0;
}