#include <iostream>
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
using namespace std;

int main() { FASTIO;
    int t, l, w, e, r; // test cases, length, width, electricity, electricity/step
    cin >> t;
    while (t--) {
        cin >> l >> w >> e >> r;
        // 1. find steps needed
        int steps = e/r;
        // 2. find perimeter
        int p = 2 * (l + w);
        // 3. find laps
        int laps = steps/p;

        cout << laps << endl;
    }
    return 0;
}