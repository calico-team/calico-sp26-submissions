#include <bits/stdc++.h>
using namespace std;

int N, M, D;
long long A[4005];
int R[2000005], C[2000005], V[2000005], W[2000005];
bool out[2000005];
vector<int> G[4005];
pair<double, double> tmp[2000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;

    for (int i = 1; i <= M; ++i) {
        cin >> R[i] >> C[i] >> V[i] >> W[i];
        G[R[i]].push_back(i);
        G[C[i]].push_back(i);
    }

    for (int i = 1; i <= N; ++i) {
        vector<double> v_sqrt;
        for (int idx : G[i]) v_sqrt.push_back(sqrt(V[idx]));
        if (v_sqrt.empty()) A[i] = 1000;
        else {
            sort(v_sqrt.begin(), v_sqrt.end());
            A[i] = max(1LL, (long long)v_sqrt[v_sqrt.size() / 2]);
        }
    }

    for (int iter = 0; iter < 3; ++iter) {
        for (int i = 1; i <= N; ++i) {
            int sz = 0;
            double tot_w = 0;
            for (int idx : G[i]) {
                if (out[idx]) continue;
                int opp = (R[idx] == i ? C[idx] : R[idx]);
                double target = (double)V[idx] / A[opp];
                double weight = (double)W[idx] * A[opp] / V[idx];
                tmp[sz++] = {target, weight};
                tot_w += weight;
            }
            if (sz == 0) continue;
            sort(tmp, tmp + sz);
            double cur_w = 0;
            for (int j = 0; j < sz; ++j) {
                cur_w += tmp[j].second;
                if (cur_w >= tot_w / 2.0) {
                    A[i] = max(1LL, (long long)(tmp[j].first + 0.5));
                    break;
                }
            }
        }
        
        if (iter == 1 && D > 0) {
            vector<pair<double, int>> errs;
            for (int i = 1; i <= M; ++i) {
                double e = (double)W[i] * abs((double)A[R[i]] * A[C[i]] - V[i]) / V[i];
                errs.push_back({e, i});
            }
            sort(errs.rbegin(), errs.rend());
            for (int i = 0; i < D; ++i) out[errs[i].second] = true;
        }
    }

    for (int i = 1; i <= N; ++i) cout << A[i] << (i == N ? "" : " ");
    cout << "\n";

    vector<pair<double, int>> final_errs;
    for (int i = 1; i <= M; ++i) {
        double e = (double)W[i] * abs((double)A[R[i]] * A[C[i]] - V[i]) / V[i];
        final_errs.push_back({e, i});
    }
    sort(final_errs.rbegin(), final_errs.rend());
    
    cout << D;
    for (int i = 0; i < D; ++i) cout << " " << final_errs[i].second;
    cout << endl;

    return 0;
}