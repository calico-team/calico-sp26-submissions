#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = (i * 3 + j * 4) % 5;
                cout << val;
                if (j != m-1) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
