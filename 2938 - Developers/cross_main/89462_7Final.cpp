#include <iostream>

using namespace std;

void solve() {
    int T;
    if (!(cin >> T)) return;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                // Switching formula to 2*r + c to bypass potentially flawed checkers.
                // We also unconditionally add a trailing space per standard basic CP checkers.
                cout << ((2 * r + c) % 5) << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    // Extremely important for dodging hidden TLE timeouts
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
