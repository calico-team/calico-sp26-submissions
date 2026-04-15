#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        if (!(cin >> n >> m)) return 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j) cout << ' ';
                cout << (i + 2 * j) % 5;
            }
            cout << '\n';
        }
    }

    return 0;
}
