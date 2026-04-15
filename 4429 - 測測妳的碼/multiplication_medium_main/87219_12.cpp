#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int R, C, V, W;
};

void solve(int N, int M, int D, const vector<Cell>& cells,
           vector<int>& A, vector<int>& discards) {
    struct E { int t, v, w; };
    vector<vector<E>> g(N + 1);
    A.assign(N, 1);
    discards.clear();
    for (int i = 0; i < M; i++) {
        g[cells[i].R].push_back({cells[i].C, cells[i].V, cells[i].W});
        g[cells[i].C].push_back({cells[i].R, cells[i].V, cells[i].W});
    }
    for (int i = 1; i <= N; i++) {
        if (g[i].empty()) continue;
        vector<double> v;
        for (auto& e : g[i]) v.push_back(sqrt(e.v));
        sort(v.begin(), v.end());
        A[i - 1] = (int)max(1LL, min(1000000000LL, (long long)round(v[v.size() / 2])));
    }
    for (int it = 0; it < 4; it++) {
        for (int i = 1; i <= N; i++) {
            if (g[i].empty()) continue;
            vector<pair<double, double>> p;
            double tw = 0;
            for (auto& e : g[i]) {
                double tg = (double)e.v / A[e.t - 1];
                double wt = (double)e.w * A[e.t - 1] / e.v;
                p.push_back({tg, wt});
                tw += wt;
            }
            sort(p.begin(), p.end());
            double cw = 0, r = p.back().first;
            for (auto& x : p) {
                cw += x.second;
                if (cw >= tw / 2.0) {
                    r = x.first;
                    break;
                }
            }
            A[i - 1] = (int)max(1LL, min(1000000000LL, (long long)round(r)));
        }
    }
    struct R { double e; int i; };
    vector<R> ev;
    for (int i = 0; i < M; i++) {
        double er = (double)cells[i].W * abs((double)A[cells[i].R - 1] * A[cells[i].C - 1] - cells[i].V) / cells[i].V;
        ev.push_back({er, i + 1});
    }
    sort(ev.begin(), ev.end(), [](const R& x, const R& y) {
        return x.e > y.e;
    });
    for (int i = 0; i < D && i < M; i++) {
        if (ev[i].e > 0) discards.push_back(ev[i].i);
    }
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