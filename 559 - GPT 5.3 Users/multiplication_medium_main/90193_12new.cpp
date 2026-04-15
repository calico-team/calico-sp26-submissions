#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;
#define V vector

int main() {
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

    V<float> x(n, 0.0f);
    V<float> sl(n, 0.0f);
    V<int> cnt(n, 0);
    for (int k = 0; k < m; k++) {
        if (disc[k]) continue;
        float lv2 = log(v[k]) / 2.0f;
        sl[r[k]] += lv2;
        sl[c[k]] += lv2;
        cnt[r[k]]++;
        cnt[c[k]]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] > 0) x[i] = sl[i] / cnt[i];
    }

    float beta1 = 0.9, beta2 = 0.99;
    V<float> m1(n, 0.0f), m2(n, 0.0f);

    V<float> grad(n, 0.0f);
    auto gd = [&](int iters, float lr, int half_time) {
        float clr = lr;
        fill(m1.begin(), m1.end(), 0.0f);
        fill(m2.begin(), m2.end(), 0.0f);

        V<int> active;
        active.reserve(m);
        for (int k = 0; k < m; k++) if (!disc[k]) active.push_back(k);

        float b1t_acc = 1.0f, b2t_acc = 1.0f;

        for (int iter = 1; iter <= iters; iter++) {
            if (iter % half_time == 0) clr /= 2.0f;
            b1t_acc *= beta1;
            b2t_acc *= beta2;
            float b1t = 1.0f - b1t_acc, b2t = 1.0f - b2t_acc;

            fill(grad.begin(), grad.end(), 0.0f);
            for (int k : active) {
                int rr = r[k], cc = c[k];
                float prod = expf(x[rr] + x[cc]);
                float g = (float)w[k] / v[k] * (prod > v[k] ? prod : -prod);
                grad[rr] += g;
                grad[cc] += g;
            }
            for (int i = 0; i < n; i++) {
                m1[i] = beta1 * m1[i] + (1 - beta1) * grad[i];
                m2[i] = beta2 * m2[i] + (1 - beta2) * grad[i] * grad[i];
                x[i] -= clr * (m1[i] / b1t) / (sqrtf(m2[i] / b2t) + 1e-8f);
            }
        }
    };

    gd(200, 0.5, 50);

    for (int round = 0; round < 4; round++) {
        V<pair<float,int>> penalty(m);
        for (int k = 0; k < m; k++) {
            float prod = expf(x[r[k]] + x[c[k]]);
            float pen = (float)w[k] * fabs(prod - v[k]) / fabs(v[k]);
            penalty[k] = {pen, k};
        }
        sort(penalty.rbegin(), penalty.rend());
        fill(disc.begin(), disc.end(), false);
        for (int i = 0; i < d; i++) disc[penalty[i].second] = true;

        fill(sl.begin(), sl.end(), 0.0f);
        fill(cnt.begin(), cnt.end(), 0);
        for (int k = 0; k < m; k++) {
            if (disc[k] || v[k] <= 0) continue;
            float lv2 = log(v[k]) / 2.0f;
            sl[r[k]] += lv2; sl[c[k]] += lv2;
            cnt[r[k]]++; cnt[c[k]]++;
        }
        for (int i = 0; i < n; i++)
            if (cnt[i] > 0) x[i] = sl[i] / cnt[i];

        float ilr = 0.3f / (round + 1);
        gd(400, ilr, 100);
    }

    for (int i = 0; i < n; i++) {
        long long a = llround(exp(x[i]));
        if (a <= 0) a = 1;
        cout << a;
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    V<int> disc_final;
    for (int k = 0; k < m; k++) if (disc[k]) disc_final.push_back(k + 1);
    cout << disc_final.size();
    for (int idx : disc_final) cout << " " << idx;
    cout << endl;

    float final_pen = 0.0f;
    for (int k = 0; k < m; k++) {
        if (!disc[k]) {
            long long prod = llround(expf(x[r[k]] + x[c[k]]));
            final_pen += (float)w[k] * fabs(prod - v[k]) / fabs(v[k]);
        }
    }
    cerr << final_pen << endl;
}
