#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define double long double
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
        if (disc[k]) continue;
        double lv2 = log(v[k]) / 2.0;
        sl[r[k]] += lv2;
        sl[c[k]] += lv2;
        cnt[r[k]]++;
        cnt[c[k]]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) x[i] = exp(sl[i] / cnt[i]);
    }

    double lr = 1.0;
    double beta1 = 0.9, beta2 = 0.99;
    V<double> m1(n, 0.0), m2(n, 0.0);

    auto gd = [&](int iters) {
        double clr = lr, noise = 1.0;
        fill(m1.begin(), m1.end(), 0.0);
        fill(m2.begin(), m2.end(), 0.0);
        int half_time = iters / 10;
        int noise_time = iters / 10;
        for (int iter = 1; iter <= iters; iter++) {
            if (iter % half_time == 0) clr /= 2.0;
            if (iter % noise_time == 0) noise /= 2.0;
            V<double> grad(n, 0.0);
            for (int k = 0; k < m; k++) {
                if (disc[k]) continue;
                int rr = r[k], cc = c[k];
                double prod = x[rr] * x[cc];
                double diff = prod - v[k];
                double g = ((double)w[k] / v[k] * (diff > 0 ? 1 : -1)) * (1 + noise * (iter % 2 ? -1 : 1));
                grad[rr] += g * x[cc];
                grad[cc] += g * x[rr];
            }
            double b1t = 1.0 - pow(beta1, iter), b2t = 1.0 - pow(beta2, iter);
            for (int i = 0; i < n; i++) {
                m1[i] = beta1 * m1[i] + (1 - beta1) * grad[i],
                m2[i] = beta2 * m2[i] + (1 - beta2) * grad[i] * grad[i];
                double mm = m1[i] / b1t, vv = m2[i] / b2t;
                x[i] -= clr * mm / (sqrt(vv) + 1e-8);
                x[i] = max(x[i], 0.0l);
            }
        }
    };

    gd(200);

    V<pair<double,int>> penalty(m);
    for (int k = 0; k < m; k++) {
        int rr = r[k], cc = c[k];
        double prod = x[rr] * x[cc];
        double pen = (double)w[k] * fabs(prod - v[k]) / fabs(v[k]);
        penalty[k] = {pen, k};
    }
    sort(penalty.rbegin(), penalty.rend());
    fill(disc.begin(), disc.end(), false);
    for (int i = 0; i < d; i++) disc[penalty[i].second] = true;

    gd(300);

    for (int i = 0; i < n; i++) {
        ll a = llround(x[i]);
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
