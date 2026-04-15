#include <bits/stdc++.h>
using namespace std;
struct Cell {
    int R, C, V, W;
};
void solve(int N, int M, int D, const vector<Cell>& cs, vector<int>& A, vector<int>& ds) {
    struct e { int t, v, w, id; };
    vector<int> c(N + 1, 0);
    for (const auto& i : cs) {
        c[i.R]++;
        c[i.C]++;
    }
    vector<int> h(N + 2, 0);
    for (int i = 1; i <= N; i++) h[i + 1] = h[i] + c[i];
    vector<e> b(2 * M);
    vector<int> ch = h;
    for (int i = 0; i < M; i++) {
        b[ch[cs[i].R]++] = {cs[i].C, cs[i].V, cs[i].W, i + 1};
        b[ch[cs[i].C]++] = {cs[i].R, cs[i].V, cs[i].W, i + 1};
    }
    vector<double> x(N + 1, 1000.0);
    for (int i = 1; i <= N; i++) {
        double sv = 0;
        int ct = 0;
        for (int j = h[i]; j < h[i + 1]; j++) {
            sv += b[j].v;
            ct++;
        }
        if (ct) x[i] = sqrt(sv / ct);
    }
    vector<bool> sk(M + 1, false);
    vector<pair<double, double>> p;
    p.reserve(M);
    auto f = [&]() {
        for (int i = 1; i <= N; i++) {
            p.clear();
            for (int j = h[i]; j < h[i + 1]; j++) {
                if (sk[b[j].id]) continue;
                double v_j = b[j].v, ak = x[b[j].t];
                p.push_back({v_j / ak, (double)b[j].w * ak / v_j});
            }
            if (p.empty()) continue;
            sort(p.begin(), p.end());
            double sm = 0, cv = 0;
            for (auto& k : p) sm += k.second;
            for (auto& k : p) {
                cv += k.second;
                if (cv >= sm / 2.0) {
                    x[i] = k.first;
                    break;
                }
            }
            if (x[i] < 1.0) x[i] = 1.0;
            if (x[i] > 1e9) x[i] = 1e9;
        }
    };
    for (int i = 0; i < 2; i++) f();
    vector<pair<double, int>> r;
    r.reserve(M);
    for (int i = 0; i < M; i++) {
        double er = (double)cs[i].W * abs(x[cs[i].R] * x[cs[i].C] - cs[i].V) / cs[i].V;
        r.push_back({er, i + 1});
    }
    sort(r.rbegin(), r.rend());
    for (int i = 0; i < D && i < M; i++) {
        sk[r[i].second] = true;
        ds.push_back(r[i].second);
    }
    for (int i = 0; i < 3; i++) f();
    A.resize(N);
    for (int i = 0; i < N; i++) {
        long long v = (long long)(x[i + 1] + 0.5);
        if (v < 1) v = 1;
        if (v > 1000000000) v = 1000000000;
        A[i] = (int)v;
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