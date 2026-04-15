#include <array>
#include <cstdint>
#include <ios>
#include <iostream>
#include <map>
#include <vector>

void solve() {

    using cell_t = std::array<std::int64_t, 2>;

    std::int64_t k;
    std::int64_t m;
    std::int64_t n;
    std::int64_t p;
    std::int64_t q;

    std::cin >> k >> n >> m >> p >> q;

    std::vector<std::int32_t> x(k);
    std::vector<std::int32_t> y(k);

    for (std::int32_t i = 0; i < k; ++i) {
        std::cin >> x[i] >> y[i];
    }

    std::int64_t cur_x = x[0];
    std::int64_t cur_y = y[0];
    std::map<cell_t, std::int32_t> idxs;

    for (std::int32_t i = 0; i < k; ++i) {
        idxs[cell_t({x[i], y[i]})] = i;
    }

    while (true) {
        cur_x = (cur_x + q) % n;
        cur_y = (cur_y + p) % m;
        if (idxs.count(cell_t({cur_x, cur_y}))) {
            std::cout << idxs[cell_t({cur_x, cur_y})] << '\n';
            break;
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
