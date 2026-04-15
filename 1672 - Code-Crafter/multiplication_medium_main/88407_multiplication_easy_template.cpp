#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int R, C, V, W;
};

/*
 * Fill in the original array A (length N, each in [1, 10^9])
 * and discards (at most D distinct 1-indexed cell indices). The
 * discards output line will begin with t, the number of discarded
 * cells, followed by those t indices; t is computed and written
 * for you in main().
 *
 * N: length of the array A
 * M: number of cells
 * D: maximum number of cells you may discard
 * cells: vector of M Cells; for cell k (1-indexed), the product
 *        A[R] * A[C] should be close to the target V, with weight W
 */
void solve(int N, int M, int D, const vector<Cell>& cells,
           vector<int>& A, vector<int>& discards) {
    vector<vector<int>> adj(N);
    vector<double> logV(M), Vd(M);

    for (int i = 0; i < M; i++) {
        adj[cells[i].R - 1].push_back(i);
        adj[cells[i].C - 1].push_back(i);
        Vd[i] = (double)cells[i].V;
        logV[i] = log(Vd[i]);
    }
    

    vector<double> x(N, 0.0);
    {
        vector<bool> vis(N, false);
        for (int s = 0; s < N; s++) {
            if (vis[s]) continue;
            vis[s] = true;
            queue<int> q; q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int ci : adj[u]) {
                    int v = (cells[ci].R - 1 == u) ? cells[ci].C - 1 : cells[ci].R - 1;
                    if (!vis[v]) {
                        vis[v] = true;
                        x[v] = logV[ci] - x[u];
                        q.push(v);
                    }
                }
            }
        }
    }
    vector<bool> skip(M, false);

    auto descent = [&](int iters) {
        for (int it = 0; it < iters; it++) {
            for (int i = 0; i < N; i++) {
                double num = 0, den = 0;
                for (int ci : adj[i]) {
                    if (skip[ci]) 
                        continue;
                    int p = (cells[ci].R - 1 == i) ? cells[ci].C - 1 : cells[ci].R - 1;
                    num += cells[ci].W * (logV[ci] - x[p]);
                    den += cells[ci].W;
                }
                if (den > 1e-12) 
                    x[i] = num / den;
            }
        }
    };
    auto make_A = [&]() {
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            double val = round(exp(x[i]));
            a[i] = (int)max(1.0, min(1e9, val));
        }
        return a;
    };


    descent(50);

    auto cur = make_A();
    int d = min(D, M);
    vector<pair<double, int>> penalties(M);
    for (int i = 0; i < M; i++) {
        double prod = (double)cur[cells[i].R - 1] * (double)cur[cells[i].C - 1];
        penalties[i] = {(double)cells[i].W * fabs(prod - Vd[i]) / Vd[i], i};
    }
    sort(penalties.rbegin(), penalties.rend());
    for (int i = 0; i < d; i++) skip[penalties[i].second] = true;

    descent(30);

    auto better_than_me = make_A();
    A = better_than_me;

    discards.clear();
    for (int i = 0; i < d; i++)
        discards.push_back(penalties[i].second + 1); 
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, D;
    cin >> N >> M >> D;
    vector<Cell> cells(M);
    for (int i = 0; i < M; i++) {
        cin >> cells[i].R >> cells[i].C >> cells[i].V >> cells[i].W;
    }

    vector<int> A, discards;
    solve(N, M, D, cells, A, discards);

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
    cout << discards.size();
    for (int idx : discards) cout << ' ' << idx;
    cout << '\n';
    return 0;
}
