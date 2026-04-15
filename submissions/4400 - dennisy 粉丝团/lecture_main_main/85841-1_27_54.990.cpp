#include <algorithm>
#include <cstdint>
#include <ios>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

void solve() {

    std::int32_t k;
    std::int32_t m;
    std::int32_t n;

    std::cin >> n >> m >> k;

    std::vector<std::string> grid(n);

    for (auto& x : grid) {
        std::cin >> x;
    }

    if (k == 1) {
        for (std::int32_t i = 0; i < n; ++i) {
            for (std::int32_t j = 0; j < m; ++j) {
                if (grid[i][j] == '-') {
                    std::cout << i << ' ' << j << '\n';
                    return;
                }
            }
        }
    }

    const std::int32_t sz = n + m;

    std::int32_t dist = sz - 1;
    std::vector has(sz - 1, std::vector<std::int32_t>(sz - 1));
    std::vector pfxs(sz, std::vector<std::int32_t>(sz));
    std::int32_t init_c = 0;
    std::int32_t init_r = 0;

    for (std::int32_t i = 0; i < n; ++i) {
        for (std::int32_t j = 0; j < m; ++j) {
            if (grid[i][j] == '-') {
                ++pfxs[i + j + 1][i - j + m];
                has[i + j][i - j + (m - 1)] = true;
            }
        }
    }

    for (std::int32_t i = 1; i < sz; ++i) {
        std::partial_sum(std::begin(pfxs[i]), std::end(pfxs[i]), std::begin(pfxs[i]));
        for (std::int32_t j = 0; j < sz; ++j) {
            pfxs[i][j] += pfxs[i - 1][j];
        }
    }

    for (std::int32_t i = 0; i < sz - 1; ++i) {
        for (std::int32_t j = 0; j < sz - 1; ++j) {
            const auto get = [&](
                std::int32_t r_1, std::int32_t c_1, std::int32_t r_2, std::int32_t c_2
            ) -> std::int32_t {
                return pfxs[r_2][c_2] - pfxs[r_2][c_1] - pfxs[r_1][c_2] + pfxs[r_1][c_1];
            };
            if (get(i, j, sz - 1, sz - 1) < k) {
                continue;
            }
            std::int32_t hi = sz;
            std::int32_t lo = 0;
            while (hi - lo > 1) {
                const std::int32_t mi = (lo + hi) / 2;
                (get(i, j, std::min(i + mi, sz - 1), std::min(j + mi, sz - 1)) >= k ? hi : lo) = mi;
            }
            if (hi < dist) {
                dist = hi;
                init_r = i;
                init_c = j;
            }
        }
    }

    for (std::int32_t i = init_r; i < init_r + dist; ++i) {
        for (std::int32_t j = init_c; j < init_c + dist; ++j) {
            if (has[i][j] && k) {
                std::cout << (i + j - (m - 1)) / 2 << ' ' << (i - j + (m - 1)) / 2 << '\n';
                --k;
            }
        }
    }

}

int main() {

    std::cin.tie(nullptr);

    std::ios_base::sync_with_stdio(false);

    std::int32_t t;

    std::cin >> t;

    for (std::int32_t i = 0; i < t; ++i) {
        solve();
    }

    return 0;

}
