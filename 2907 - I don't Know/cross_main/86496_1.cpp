#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (2 * i + j) % 5 << (j == m - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}