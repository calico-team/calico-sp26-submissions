#include <iostream>

using namespace std;

int main() {
    int T, L, W, E, R;
    cin >> T;
    
    while (T--) {
        cin >> L >> W >> E >> R;
        cout << E / (2 * (L + W) * R) << "\n";
    }
    
    return 0;
}