#include <array>
#include <cstdint>
#include <ios>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

template <typename T>
std::array<T, 3> extended_gcd(T m, T n) {

    T a_m = 1;
    T a_n = 0;
    T b_m = 0;
    T b_n = 1;

    while (n) {
        const T q = m / n;
        a_n = std::exchange(a_m, a_n) - a_n * q;
        b_n = std::exchange(b_m, b_n) - b_n * q;
        n = std::exchange(m, n) - n * q;
    }

    return std::array<T, 3>({m, a_m, b_m});

}

template <typename T>
class modular_congruence {

public:

    T m;
    T a;

    explicit modular_congruence() : modular_congruence(0, 0) {}

    explicit modular_congruence(T m, T a) : m(m), a(a) {}

    void operator&=(modular_congruence other) {

        const auto [gcd, coef_1, coef_2] = extended_gcd(m, other.m);

        if ((a - other.a) % gcd) {
            m = 0;
            a = 0;
            return;
        }

        const T lcm = m / gcd * other.m;

        a = (a + (((coef_1 * (other.a - a)) / gcd) % (other.m / gcd)) * m) % lcm;
        m = lcm;

        if (a < 0) {
            a += m;
        }

    }

    friend modular_congruence operator&(modular_congruence lhs, modular_congruence rhs) {

        lhs &= rhs;

        return lhs;

    }

};

void solve() {

    using cong_t = modular_congruence<std::int64_t>;

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

    std::int32_t idx = 0;
    std::int64_t tm = std::lcm(n / std::gcd(n, q), m / std::gcd(m, p));

    for (std::int32_t i = 1; i < k; ++i) {
        const auto norm = [](std::int64_t val, std::int64_t mod) -> std::int64_t {
            return (val % mod + mod) % mod;
        };
        const std::int64_t gcd_1 = std::gcd(q, n);
        const std::int64_t gcd_2 = std::gcd(p, m);
        if (norm(x[i] - x[0], n) % gcd_1 || norm(y[i] - y[0], m) % gcd_2) {
            continue;
        }
        const auto get = [&](std::int64_t a, std::int64_t b, std::int64_t mod) -> cong_t {
            a = norm(a, mod);
            b = norm(b, mod);
            const std::int64_t gcd = std::gcd(a, mod);
            a /= gcd;
            b /= gcd;
            mod /= gcd;
            return cong_t(mod, norm(b * extended_gcd(a, mod)[1], mod));
        };
        const cong_t cong = get(q, x[i] - x[0], n) & get(p, y[i] - y[0], m);
        if (cong.m && cong.a < tm) {
            tm = cong.a;
            idx = i;
        }
    }

    std::cout << idx << '\n';

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
