#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = (i + 2 * j) % 5;
                cout << val;
                if (j + 1 < m) cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}