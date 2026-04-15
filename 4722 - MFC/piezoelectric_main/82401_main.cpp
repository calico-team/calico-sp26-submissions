#include <iostream>

int main() {
    // gets the number of cases
    int cases{};
    std::cin >> cases;

    // for every case
    for (int i{0}; i < cases; i++) {
        int L;
        int W;
        int E;
        int R;

        std::cin >> L;
        std::cin >> W;
        std::cin >> E;
        std::cin >> R;

        int perimeter = 2 * L + 2 * W;
        int e_per_lap = perimeter * R;

        std::cout << E / e_per_lap;
    }

    return 0;
}
