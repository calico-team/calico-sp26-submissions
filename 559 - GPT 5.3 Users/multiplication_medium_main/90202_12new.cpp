#include <bits/stdc++.h>
using namespace std;
#define V vector
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    V<int> r(m), c(m), w(m);
    V<float> v(m);
    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i] >> v[i] >> w[i];
        r[i]--; c[i]--;
    }
    V<int> is(m);
    iota(is.begin(), is.end(), 0);
    sort(is.begin(), is.end(), [&](int a, int b){ return w[a] > w[b]; });
    V<bool> disc(m, false);
    for (int i = 0; i < d; i++) disc[is[i]] = true;

    V<double> x(n, 0.0);
    V<double> sl(n, 0.0);
    V<int> cnt(n, 0);
    for (int k = 0; k < m; k++) {
        if (disc[k] || v[k] <= 0) continue;
        double lv2 = log((double)v[k]) / 2.0;
        sl[r[k]] += lv2; sl[c[k]] += lv2;
        cnt[r[k]]++; cnt[c[k]]++;
    }
    for (int i = 0; i < n; i++)
        if (cnt[i] > 0) x[i] = sl[i] / cnt[i];

    double beta1 = 0.89999999, beta2 = 0.98999999;
    V<double> m1(n, 0.0), m2(n, 0.0);
    V<double> grad(n, 0.0);
    V<double> ex(n);
    for (int i = 0; i < n; i++) ex[i] = exp(x[i]);

    auto gd = [&](int iters, double lr, int half_time) {
        double clr = lr;
        fill(m1.begin(), m1.end(), 0.0);
        fill(m2.begin(), m2.end(), 0.0);
        V<int> active;
        active.reserve(m);
        for (int k = 0; k < m; k++) if (!disc[k]) active.push_back(k);
        double b1t_acc = 1.0, b2t_acc = 1.0;
        for (int iter = 1; iter <= iters; iter++) {
            if (iter % 50 == 0)
                for (int i = 0; i < n; i++) ex[i] = exp(x[i]);
            if (iter % half_time == 0) clr /= 2.07;
            b1t_acc *= beta1; b2t_acc *= beta2;
            double b1t = 1.0 - b1t_acc, b2t = 1.0 - b2t_acc;
            fill(grad.begin(), grad.end(), 0.0);
            for (int k : active) {
                int rr = r[k], cc = c[k];
                double prod = ex[rr] * ex[cc];
                double g = (double)w[k] / v[k] * (prod > v[k] ? prod : -prod);
                grad[rr] += g;
                grad[cc] += g;
            }
            for (int i = 0; i < n; i++) {
                m1[i] = beta1 * m1[i] + (1 - beta1) * grad[i];
                m2[i] = beta2 * m2[i] + (1 - beta2) * grad[i] * grad[i];
                double delta = clr * (m1[i] / b1t) / (sqrt(m2[i] / b2t) + 1e-8);
                x[i] -= delta;
                ex[i] *= exp(-delta);
            }
        }
    };

    gd(200, 0.4, 100);
    for (int round = 0; round < 5; round++) {
        V<pair<double,int>> penalty(m);
        for (int k = 0; k < m; k++) {
            double prod = ex[r[k]] * ex[c[k]];
            penalty[k] = {(double)w[k] * fabs(prod - v[k]) / fabs(v[k]), k};
        }
        sort(penalty.rbegin(), penalty.rend());
        fill(disc.begin(), disc.end(), false);
        for (int i = 0; i < d; i++) disc[penalty[i].second] = true;

        // reinit x from new discard set
        fill(sl.begin(), sl.end(), 0.0);
        fill(cnt.begin(), cnt.end(), 0);
        for (int k = 0; k < m; k++) {
            if (disc[k] || v[k] <= 0) continue;
            double lv2 = log((double)v[k]) / 2.0;
            sl[r[k]] += lv2; sl[c[k]] += lv2;
            cnt[r[k]]++; cnt[c[k]]++;
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] > 0) x[i] = sl[i] / cnt[i];
            ex[i] = exp(x[i]);
        }

        double ilr = 0.3 / (round + 0.7);
        gd(400, ilr, 200);
    }

    for (int i = 0; i < n; i++) {
        long long a = llround(ex[i]);
        ex[i] = a;
        if (a <= 0) a = 1;
        cout << a;
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    V<int> disc_final;
    for (int k = 0; k < m; k++) if (disc[k]) disc_final.push_back(k + 1);
    cout << disc_final.size();
    for (int idx : disc_final) cout << " " << idx;
    cout << "\n";
    double final_pen = 0.0;
    for (int k = 0; k < m; k++) {
        if (!disc[k]) {
            double prod = ex[r[k]] * ex[c[k]];
            final_pen += (double)w[k] * fabs(prod - v[k]) / fabs(v[k]);
        }
    }
    cerr << fixed << setprecision(7) << final_pen << "\n";
}
