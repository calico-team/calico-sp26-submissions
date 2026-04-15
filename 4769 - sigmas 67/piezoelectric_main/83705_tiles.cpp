#include <iostream>

int main() {
    int numTests;
    std::cin >> numTests;

    for (int i {0}; i < numTests; i++) {
        int len, width, total, step;
        std::cin >> len >> width >> total >> step;

        int perimeter = len * 2 + width * 2;
        int lap = perimeter * step;

        int a = total/lap;
        std::cout << a << std::endl;
    }
    return 0;
}