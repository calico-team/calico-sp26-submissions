#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long L, W, E, R;
        cin >> L >> W >> E >> R;

        long long ans = E/(2*R*(L+W));

        cout << ans << "\n";
    }

    return 0;
}