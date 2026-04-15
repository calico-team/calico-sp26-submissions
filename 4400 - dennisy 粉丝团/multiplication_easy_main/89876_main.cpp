#include <algorithm>
#include <cmath>
#include <cstdint>
#include <ios>
#include <iostream>
#include <random>
#include <vector>

void solve() {

    static std::mt19937 rng(33);

    std::int32_t d;
    std::int32_t m;
    std::int32_t n;

    std::cin >> n >> m >> d;

    std::vector<std::int32_t> c(m);
    std::vector<std::int32_t> r(m);
    std::vector<std::int64_t> v(m);
    std::vector<std::int64_t> w(m);

    for (std::int32_t i = 0; i < m; ++i) {
        std::cin >> r[i] >> c[i] >> v[i] >> w[i];
        --r[i];
        --c[i];
    }

    std::vector<std::int64_t> ans;
    double pen = 1e18;
    std::vector<std::int32_t> s;

    for (std::int32_t q = 0; q < 500; ++q) {
        std::vector<std::int32_t> ord(m);
        std::shuffle(std::begin(ord), std::end(ord), rng);
        std::vector<std::int64_t> a(n);
        std::sort(
            std::begin(ord), std::end(ord), [&](std::int32_t idx_1, std::int32_t idx_2) -> bool {
                return w[idx_1] > w[idx_2];
            }
        );
        for (auto x : ord) {
            if (a[r[x]] == 0 && a[c[x]] == 0) {
                const std::int32_t rt = std::sqrt(v[x]);
                a[r[x]] = rt;
                a[c[x]] = rt + 1;
            } else if (a[r[x]] == 0) {
                a[r[x]] = v[x] / a[c[x]];
            } else if (a[c[x]] == 0) {
                a[c[x]] = v[x] / a[r[x]];
            }
        }
        std::vector<double> pens(m);
        for (std::int32_t i = 0; i < m; ++i) {
            pens[i] = w[i] * double(std::abs(a[r[i]] * a[c[i]] - v[i])) / v[i];
        }
        std::sort(
            std::begin(ord), std::end(ord), [&](std::int32_t idx_1, std::int32_t idx_2) -> bool {
                return pens[idx_1] > pens[idx_2];
            }
        );
        double cur = 0;
        for (std::int32_t i = d; i < m; ++i) {
            cur += pens[i];
        }
        if (cur < pen) {
            pen = cur;
            ans = a;
            s.clear();
            for (std::int32_t i = 0; i < d; ++i) {
                s.push_back(ord[i]);
            }
        }
    }

    for (std::int32_t i = 0; i < n; ++i) {
        if (ans[i] == 0) {
            ans[i] = 1;
        }
        std::cout << ans[i] << (i < n - 1 ? ' ' : '\n');
    }

    std::cout << d;

    for (auto x : s) {
        std::cout << ' ' << x + 1;
    }

    std::cout << '\n';

}

int main() {

    std::cin.tie(nullptr);

    std::ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
