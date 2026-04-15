#include <bits/stdc++.h>
using namespace std;
struct Constraint { int r, c, v, w; };

void read_your_input() {
    int N, M, D;
    cin >> N >> M >> D;
    vector<Constraint> cons(M);
    for (int i = 0; i < M; i++)
        cin >> cons[i].r >> cons[i].c >> cons[i].v >> cons[i].w;

    vector<double> logV(M);
    for (int i = 0; i < M; i++) logV[i] = log((double)cons[i].v);

    // BFS init
    auto bfs_init = [&](vector<double>& x, const vector<bool>& discarded) {
        fill(x.begin(), x.end(), 0.0);
        vector<vector<pair<int,int>>> adj(N + 1);
        for (int i = 0; i < M; i++) {
            if (discarded[i]) continue;
            adj[cons[i].r].push_back({cons[i].c, i});
            adj[cons[i].c].push_back({cons[i].r, i});
        }
        vector<bool> visited(N + 1, false);
        queue<int> q;
        for (int start = 1; start <= N; start++) {
            if (!visited[start]) {
                visited[start] = true;
                q.push(start);
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (auto [vnode, idx] : adj[u]) {
                        if (!visited[vnode]) {
                            visited[vnode] = true;
                            x[vnode] = logV[idx] - x[u];
                            q.push(vnode);
                        }
                    }
                }
            }
        }
    };

    auto optimize = [&](vector<double>& x, const vector<bool>& discarded) {
        vector<vector<tuple<int,double,int>>> node_cons(N + 1);
        for (int i = 0; i < M; i++) {
            if (discarded[i]) continue;
            node_cons[cons[i].r].emplace_back(cons[i].c, logV[i], cons[i].w);
            node_cons[cons[i].c].emplace_back(cons[i].r, logV[i], cons[i].w);
        }
        for (int iter = 0; iter < 200; iter++) {
            double max_change = 0;
            for (int i = 1; i <= N; i++) {
                if (node_cons[i].empty()) continue;
                double num = 0, den = 0;
                for (auto& [partner, lv, w] : node_cons[i]) {
                    num += w * (lv - x[partner]);
                    den += w;
                }
                double new_x = num / den;
                max_change = max(max_change, abs(new_x - x[i]));
                x[i] = new_x;
            }
            if (max_change < 1e-12) break;
        }
    };

    auto total_penalty = [&](const vector<double>& x, const vector<bool>& discarded) {
        double pen = 0;
        for (int i = 0; i < M; i++) {
            if (discarded[i]) continue;
            double prod = exp(x[cons[i].r] + x[cons[i].c]);
            pen += (double)cons[i].w * abs(prod - cons[i].v) / cons[i].v;
        }
        return pen;
    };

    auto to_ints = [&](const vector<double>& x, vector<long long>& a) {
        for (int i = 1; i <= N; i++) {
            double val = round(exp(x[i]));
            a[i] = (long long)max(1.0, min(1e9, val));
        }
    };

    // Greedy: each round, try removing each remaining active constraint,
    // pick whichever removal gives lowest total penalty after re-optimize
    vector<bool> discarded(M, false);
    vector<double> x(N + 1, 0.0);

    bfs_init(x, discarded);
    optimize(x, discarded);

    for (int round = 0; round < D; round++) {
        double best_pen = total_penalty(x, discarded); // baseline: discard nothing new
        int best_discard = -1;

        for (int i = 0; i < M; i++) {
            if (discarded[i]) continue;
            discarded[i] = true;

            vector<double> x2(N + 1, 0.0);
            bfs_init(x2, discarded);
            optimize(x2, discarded);
            double pen = total_penalty(x2, discarded);

            if (pen < best_pen) {
                best_pen = pen;
                best_discard = i;
            }

            discarded[i] = false;
        }

        if (best_discard == -1) break; // no improvement from discarding
        discarded[best_discard] = true;
        bfs_init(x, discarded);
        optimize(x, discarded);
    }

    vector<long long> a(N + 1);
    to_ints(x, a);

    for (int i = 1; i <= N; i++)
        cout << a[i] << " \n"[i == N];

    int cnt = 0;
    for (int i = 0; i < M; i++) if (discarded[i]) cnt++;
    cout << cnt;
    for (int i = 0; i < M; i++) if (discarded[i]) cout << " " << (i+1);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_your_input();
    return 0;
}