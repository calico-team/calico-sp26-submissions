#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Work in log space: let b[i] = log(a[i])
// Then log(a[r]*a[c]) = b[r]+b[c], want it close to log(V)
// Minimize sum Wi * |exp(b[r]+b[c]) - V| / V
// In log space: minimize sum Wi * |exp(b[r]+b[c] - log(V)) - 1|
// Good approximation: minimize sum Wi * (b[r]+b[c] - log(V))^2

// Use coordinate descent on b[i]

int N, M, D;
struct Constraint {
    int r, c;
    ll v, w;
};

vector<Constraint> cons;
vector<ld> b; // log(a[i]), 1-indexed

ld compute_penalty(vector<ld>& a, vector<bool>& discarded) {
    ld pen = 0;
    for (int i = 0; i < M; i++) {
        if (discarded[i]) continue;
        ld prod = a[cons[i].r] * a[cons[i].c];
        pen += cons[i].w * abs(prod - cons[i].v) / cons[i].v;
    }
    return pen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> D;
    cons.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> cons[i].r >> cons[i].c >> cons[i].v >> cons[i].w;
        cons[i].r--; cons[i].c--;
    }

    b.assign(N, 0.0);

    // Initialize b using weighted least squares in log space
    // For each index i, given fixed others, optimal b[i]:
    // sum over constraints with r==i or c==i of Wi*(b[i] + b[other] - logV)^2
    // derivative: 2 * sum Wi * (b[i] + b[other] - logV) = 0
    // b[i] = (sum Wi*(logV - b[other])) / (sum Wi)

    // Build adjacency: for each node, list of (other, logV, w)
    vector<vector<tuple<int,ld,ld>>> adj(N);
    for (int i = 0; i < M; i++) {
        int r = cons[i].r, c = cons[i].c;
        ld lv = log((ld)cons[i].v);
        ld w = cons[i].w;
        adj[r].emplace_back(c, lv, w);
        adj[c].emplace_back(r, lv, w);
    }

    // Initialize b[i] from constraints: rough estimate
    // b[i] = average of (logV - b[other]) weighted
    // Start with b all 0, then do coordinate descent
    for (int iter = 0; iter < 200; iter++) {
        for (int i = 0; i < N; i++) {
            ld num = 0, den = 0;
            for (auto& [other, lv, w] : adj[i]) {
                num += w * (lv - b[other]);
                den += w;
            }
            if (den > 1e-9) b[i] = num / den;
        }
    }

    // Convert back to a values, clamp to [1, 1e9]
    vector<ld> a(N);
    for (int i = 0; i < N; i++) {
        a[i] = exp(b[i]);
        a[i] = max((ld)1.0, min((ld)1e9, a[i]));
    }

    // Compute per-constraint penalty for discarding
    // Discard top-D by penalty contribution
    vector<pair<ld,int>> pen_idx(M);
    for (int i = 0; i < M; i++) {
        ld prod = a[cons[i].r] * a[cons[i].c];
        ld p = cons[i].w * abs(prod - cons[i].v) / cons[i].v;
        pen_idx[i] = {p, i};
    }
    sort(pen_idx.rbegin(), pen_idx.rend());

    vector<bool> discarded(M, false);
    vector<int> discarded_list;
    for (int i = 0; i < D; i++) {
        discarded[pen_idx[i].second] = true;
        discarded_list.push_back(pen_idx[i].second + 1); // 1-indexed
    }

    // Re-run coordinate descent without discarded constraints
    b.assign(N, 0.0);
    vector<vector<tuple<int,ld,ld>>> adj2(N);
    for (int i = 0; i < M; i++) {
        if (discarded[i]) continue;
        int r = cons[i].r, c = cons[i].c;
        ld lv = log((ld)cons[i].v);
        ld w = cons[i].w;
        adj2[r].emplace_back(c, lv, w);
        adj2[c].emplace_back(r, lv, w);
    }
    for (int iter = 0; iter < 300; iter++) {
        for (int i = 0; i < N; i++) {
            ld num = 0, den = 0;
            for (auto& [other, lv, w] : adj2[i]) {
                num += w * (lv - b[other]);
                den += w;
            }
            if (den > 1e-9) b[i] = num / den;
        }
    }

    // Final a values
    vector<ll> better_than_me(N);
    for (int i = 0; i < N; i++) {
        ld val = exp(b[i]);
        val = max((ld)1.0, min((ld)1e9, val));
        better_than_me[i] = llround(val);
        better_than_me[i] = max(1LL, min((ll)1e9, better_than_me[i]));
    }

    // Re-discard: recompute with final integer a values
    vector<pair<ld,int>> pen_idx2(M);
    for (int i = 0; i < M; i++) {
        ld prod = (ld)better_than_me[cons[i].r] * better_than_me[cons[i].c];
        ld p = cons[i].w * abs(prod - cons[i].v) / cons[i].v;
        pen_idx2[i] = {p, i};
    }
    sort(pen_idx2.rbegin(), pen_idx2.rend());

    discarded_list.clear();
    for (int i = 0; i < D; i++) {
        discarded_list.push_back(pen_idx2[i].second + 1);
    }

    for (int i = 0; i < N; i++) {
        cout << better_than_me[i] << " \n"[i==N-1];
    }
    cout << D;
    for (int x : discarded_list) cout << " " << x;
    cout << "\n";

    return 0;
}

void read_your_input() {
    // input handled in main
}