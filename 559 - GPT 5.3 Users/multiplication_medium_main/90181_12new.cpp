#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define V vector

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    V<int> r(m), c(m), w(m);
    V<double> v(m);

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
        double lv2 = log(v[k]) / 2.0;
        sl[r[k]] += lv2;
        sl[c[k]] += lv2;
        cnt[r[k]]++;
        cnt[c[k]]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) x[i] = sl[i] / cnt[i];
    }

    double lr = 0.05;
    double beta1 = 0.9, beta2 = 0.99;
    V<double> m1(n, 0.0), m2(n, 0.0);

    auto gd = [&](int iters) {
        fill(m1.begin(), m1.end(), 0.0);
        fill(m2.begin(), m2.end(), 0.0);
        for (int iter = 1; iter <= iters; iter++) {
            V<double> grad(n, 0.0);
            for (int k = 0; k < m; k++) {
                if (disc[k]) continue;
                int rr = r[k], cc = c[k];
                double prod = exp(x[rr] + x[cc]);
                double diff = prod - v[k];
                double g = (double)w[k] / fabs(v[k]) * (diff > 0 ? prod : -prod);
                grad[rr] += g;
                grad[cc] += g;
            }
            double b1t = 1.0 - pow(beta1, iter), b2t = 1.0 - pow(beta2, iter);
            for (int i = 0; i < n; i++) {
                m1[i] = beta1 * m1[i] + (1 - beta1) * grad[i],
                m2[i] = beta2 * m2[i] + (1 - beta2) * grad[i] * grad[i];
                double mm = m1[i] / b1t, vv = m2[i] / b2t;
                x[i] -= lr * mm / (sqrt(vv) + 1e-8);
            }
        }
    };

    gd(200);

    V<pair<double,int>> penalty(m);
    for (int k = 0; k < m; k++) {
        int rr = r[k], cc = c[k];
        double prod = exp(x[rr] + x[cc]);
        double pen = (double)w[k] * fabs(prod - v[k]) / fabs(v[k]);
        penalty[k] = {pen, k};
    }
    sort(penalty.rbegin(), penalty.rend());
    fill(disc.begin(), disc.end(), false);
    for (int i = 0; i < d; i++) disc[penalty[i].second] = true;

    gd(300);

    for (int i = 0; i < n; i++) {
        ll a = llround(exp(x[i]));
        if (a == 0) a = 1;
        cout << a;
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    V<int> disc_final;
    for (int k = 0; k < m; k++) if (disc[k]) disc_final.push_back(k + 1);
    cout << disc_final.size();
    for (int idx : disc_final) cout << " " << idx;
    cout << endl;
}
