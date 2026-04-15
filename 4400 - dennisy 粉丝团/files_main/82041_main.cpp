#include <algorithm>
#include <cstdint>
#include <ios>
#include <iostream>
#include <string>

void solve() {

    std::string a;
    std::string b;

    std::cin >> a >> b;

    std::reverse(std::begin(b), std::end(b));

    for (auto x : a) {
        if (!std::empty(b) && x == b.back()) {
            std::cout << x;
            b.pop_back();
        } else {
            std::cout << '#';
        }
    }

    std::cout << '\n';

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
