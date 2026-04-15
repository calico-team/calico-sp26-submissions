#include <algorithm>
#include <cmath>
#include <cstdint>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

void solve() {

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

    std::vector<std::int64_t> a(n);
    std::vector<std::int32_t> ord(m);

    std::iota(std::begin(ord), std::end(ord), 0);

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

    for (std::int32_t i = 0; i < n; ++i) {
        if (a[i] == 0) {
            a[i] = 1;
        }
        std::cout << a[i] << (i < n - 1 ? ' ' : '\n');
    }

    std::cout << d;

    std::vector<double> pens(m);

    for (std::int32_t i = 0; i < m; ++i) {
        pens[i] = w[i] * double(std::abs(a[r[i]] * a[c[i]] - v[i])) / v[i];
    }

    std::sort(
        std::begin(ord), std::end(ord), [&](std::int32_t idx_1, std::int32_t idx_2) -> bool {
            return pens[idx_1] > pens[idx_2];
        }
    );

    for (std::int32_t i = 0; i < d; ++i) {
        std::cout << ' ' << ord[i] + 1;
    }

    std::cout << '\n';

}

int main() {

    std::cin.tie(nullptr);

    std::ios_base::sync_with_stdio(false);

    solve();

    return 0;

}
